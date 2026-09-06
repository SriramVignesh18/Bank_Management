import pandas as pd
import os
import logging
import time
from sqlalchemy import create_engine
from pathlib import Path

Path("logs").mkdir(parents=True,exist_ok=True)
logging.basicConfig(
    filename="logs/ingest-data.log",
    level=logging.DEBUG,
    format="%(asctime)s- %(levelname)s- %(message)s",
    filemode="a"
)
engine=create_engine('sqlite:///inventory.db')

def ingestion(data,tablename,engine):
    data.to_sql(tablename,con=engine,if_exists='replace',index=False)
def load_data():
    start=time.time()
    for file in os.listdir('data'):
        if '.csv' in file:
            data=pd.read_csv('data/'+file)
            logging.info(f'Ingestion of {file} in DB')
            ingestion(data,file[:-4],engine)
    end=time.time()
    diff=(end-start)/60
    logging.info("Ingestion is Completed!!!")
    logging.info(f"\n Total time taken: {diff} mins")

if __name__=="__main__":
    load_data()