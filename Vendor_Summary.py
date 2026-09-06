import sqlite3
import pandas as pd
import logging
from Ingestion import ingestion
logging.basicConfig(
    filename="logs/vendor-summary.log",
    level=logging.DEBUG,
    format="%(asctime)s- %(levelname)s- %(message)s",
    filemode="a"
)

def create_ven_summ(con):
    vendor_sales_summ=pd.read_sql_query("""
    WITH FreightSummary AS (
        SELECT
            VendorNumber,
            SUM(Freight) AS FreightCost
        FROM vendor_invoice
        GROUP BY VendorNumber
    ),
    PurchaseSummary AS (
        SELECT
            p.VendorNumber,
            p.VendorName,
            p.Brand,
            p.Description,
            p.PurchasePrice,
            pp.Price AS ActualPrice,
            pp.Volume,
            SUM(p.Quantity) AS TotalPurchaseQuantity,
            SUM(p.Dollars) AS TotalPurchaseDollars
        FROM purchases AS p
        JOIN purchase_prices AS pp ON p.Brand = pp.Brand
        WHERE p.PurchasePrice > 0
        GROUP BY
            p.VendorNumber,
            p.VendorName,
            p.Brand,
            p.Description,
            p.PurchasePrice,
            pp.Price,
            pp.Volume
    ),
    SalesSummary AS (
        SELECT
            s.VendorNo,
            s.Brand,
            SUM(s.SalesQuantity) AS TotalSalesQuantity,
            SUM(s.SalesDollars) AS TotalSalesDollars,
            SUM(s.SalesPrice) AS TotalSalesPrice,
            SUM(s.ExciseTax) AS TotalExciseTax
        FROM sales AS s
        GROUP BY s.VendorNo, s.Brand
    )
    SELECT
        ps.VendorNumber,
        ps.VendorName,
        ps.Brand,
        ps.Description,
        ps.PurchasePrice,
        ps.ActualPrice,
        ps.Volume,
        ps.TotalPurchaseQuantity,
        ps.TotalPurchaseDollars,
        ss.TotalSalesQuantity,
        ss.TotalSalesDollars,
        ss.TotalSalesPrice,
        ss.TotalExciseTax,
        fs.FreightCost
    FROM PurchaseSummary AS ps
    LEFT JOIN SalesSummary AS ss
        ON ps.VendorNumber = ss.VendorNo
        AND ps.Brand = ss.Brand
    LEFT JOIN FreightSummary AS fs
        ON ps.VendorNumber = fs.VendorNumber
    ORDER BY ps.TotalPurchaseDollars DESC
    """, con)
    return vendor_sales_summ

def cleaning_data(df):
    df['Volume']=df['Volume'].astype('float64')
    df['VendorName']=df['VendorName'].str.strip()
    df.fillna(0,inplace=True)
    df['Profit']=df['TotalSalesDollars']-df['TotalPurchaseDollars']
    df['ProfitMargin']=(df['Profit']/df['TotalSalesDollars'])*100
    df['StockTurnover']=(df['TotalSalesQuantity']/df['TotalPurchaseQuantity'])
    df['S2PRatio']=(df['TotalSalesDollars']/df['TotalPurchaseDollars'])
    return df

if __name__=="__main__":
    connect=sqlite3.connect('inventory.db')
    logging.info('Creating the Vendor Summary Table....')
    summary=create_ven_summ(connect)
    logging.info(summary.head())
    logging.info('Cleaning the Data...')
    clean=cleaning_data(summary)
    logging.info(clean.head())
    logging.info('Ingestion of the Data...')
    ingestion(clean,'vendor_sales_summ',connect)
    clean.to_csv("vendor_sales_summary.csv",index=False)
    logging.info('Completed')
