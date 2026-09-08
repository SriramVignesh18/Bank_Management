import os
import pickle
import streamlit as st
from streamlit_option_menu import option_menu
st.set_page_config(page_title="Multiple Disease Predictor",layout="wide")
st.markdown("""
<style>
.stApp{
background-color:#FFF8F0;
}
h1{
color:#5B2C2C;
font-weight:700;
}
[data-testid="stSidebar"]{
background-color:#5B2C2C;
}
[data-testid="stSidebar"] *{
color:white;
}
.stTextInput input{
background-color:#FFFFFF;
color:#2D2D2D;
border:1px solid #D8B4A0;
border-radius:8px;
}
.stTextInput input:focus{
border:2px solid #C96F4A;
}
.stButton>button,.stFormSubmitButton>button{
background-color:#C96F4A;
color:white;
border:none;
border-radius:8px;
font-weight:600;
}
.stButton>button:hover,.stFormSubmitButton>button:hover{
background-color:#A94F32;
color:white;
}
</style>
""",unsafe_allow_html=True)
working_dir=os.path.dirname(os.path.abspath(__file__))
diabetes_model=pickle.load(open(os.path.join(working_dir,"saved_models","diabetes_model.sav"),"rb"))
heart_model=pickle.load(open(os.path.join(working_dir,"saved_models","heart_disease_model.sav"),"rb"))
parkinsons_model=pickle.load(open(os.path.join(working_dir,"saved_models","parkinsons_model.sav"),"rb"))
with st.sidebar:
    selected=option_menu("Multiple Disease Prediction System",["Diabetes Prediction","Heart Disease Prediction","Parkinsons Prediction"],menu_icon="hospital",icons=["activity","heart","person"],default_index=0,styles={"container":{"background-color":"#5B2C2C"},"icon":{"color":"#F4C7B5"},"nav-link":{"color":"white"},"nav-link-selected":{"background-color":"#C96F4A"}})
if selected=="Diabetes Prediction":
    st.title("Diabetes Prediction using ML")
    with st.form("diabetes_form"):
        col1,col2,col3=st.columns(3)
        with col1:
            pregnancies=st.text_input("Number of Pregnancies")
            skin=st.text_input("Skin Thickness")
            pedigree=st.text_input("Diabetes Pedigree Function")
        with col2:
            glucose=st.text_input("Glucose Level")
            insulin=st.text_input("Insulin Level")
            age=st.text_input("Age")
        with col3:
            bp=st.text_input("Blood Pressure")
            bmi=st.text_input("BMI")
        submit=st.form_submit_button("Diabetes Test Result")
    if submit:
        try:
            user_input=[pregnancies,glucose,bp,skin,insulin,bmi,pedigree,age]
            user_input=[float(x) for x in user_input]
            prediction=diabetes_model.predict([user_input])
            if prediction[0]==1:
                st.error("The person is diabetic")
            else:
                st.success("The person is not diabetic")
        except ValueError:
            st.warning("Please enter all values")
elif selected=="Heart Disease Prediction":
    st.title("Heart Disease Prediction using ML")
    with st.form("heart_form"):
        col1,col2,col3=st.columns(3)
        with col1:
            age=st.text_input("Age")
            trestbps=st.text_input("Resting Blood Pressure")
            restecg=st.text_input("Resting ECG")
            oldpeak=st.text_input("ST Depression")
            thal=st.text_input("Thal")
        with col2:
            sex=st.text_input("Sex")
            chol=st.text_input("Cholesterol")
            thalach=st.text_input("Maximum Heart Rate")
            slope=st.text_input("Slope")
        with col3:
            cp=st.text_input("Chest Pain Type")
            fbs=st.text_input("Fasting Blood Sugar")
            exang=st.text_input("Exercise Induced Angina")
            ca=st.text_input("Major Vessels")
        submit=st.form_submit_button("Heart Disease Test Result")
    if submit:
        try:
            user_input=[age,sex,cp,trestbps,chol,fbs,restecg,thalach,exang,oldpeak,slope,ca,thal]
            user_input=[float(x) for x in user_input]
            prediction=heart_model.predict([user_input])
            if prediction[0]==1:
                st.error("The person has heart disease")
            else:
                st.success("The person does not have heart disease")
        except ValueError:
            st.warning("Please enter all values")
elif selected=="Parkinsons Prediction":
    st.title("Parkinson's Disease Prediction using ML")
    with st.form("parkinsons_form"):
        col1,col2,col3,col4=st.columns(4)
        with col1:
            fo=st.text_input("MDVP:Fo(Hz)")
            jitter_abs=st.text_input("MDVP:Jitter(Abs)")
            shimmer=st.text_input("MDVP:Shimmer")
            apq=st.text_input("MDVP:APQ")
            rpde=st.text_input("RPDE")
            spread2=st.text_input("Spread2")
        with col2:
            fhi=st.text_input("MDVP:Fhi(Hz)")
            rap=st.text_input("MDVP:RAP")
            shimmer_db=st.text_input("MDVP:Shimmer(dB)")
            dda=st.text_input("Shimmer:DDA")
            dfa=st.text_input("DFA")
            d2=st.text_input("D2")
        with col3:
            flo=st.text_input("MDVP:Flo(Hz)")
            ppq=st.text_input("MDVP:PPQ")
            apq3=st.text_input("Shimmer:APQ3")
            nhr=st.text_input("NHR")
            spread1=st.text_input("Spread1")
            ppe=st.text_input("PPE")
        with col4:
            jitter_percent=st.text_input("MDVP:Jitter(%)")
            ddp=st.text_input("Jitter:DDP")
            apq5=st.text_input("Shimmer:APQ5")
            hnr=st.text_input("HNR")
        submit=st.form_submit_button("Parkinson's Test Result")
    if submit:
        try:
            user_input=[fo,fhi,flo,jitter_percent,jitter_abs,rap,ppq,ddp,shimmer,shimmer_db,apq3,apq5,apq,dda,nhr,hnr,rpde,dfa,spread1,spread2,d2,ppe]
            user_input=[float(x) for x in user_input]
            prediction=parkinsons_model.predict([user_input])
            if prediction[0]==1:
                st.error("The person has Parkinson's disease")
            else:
                st.success("The person does not have Parkinson's disease")
        except ValueError:
            st.warning("Please enter all values")