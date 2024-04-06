#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
void createacc();
void createdacc();
void login();
void steps();
void logout();
void delacc();
void fixed_dep();
void loan();
void balance1();
void balance2();
void balance3();
void balance4();
void withdraw();
void transfered();
void transfered2();
void det();
void details();
int main2();
struct registration
{
	char username[20];
	char password[20];
	char fname[20];
	char lname[20];
	char fathername[20];
	char mothername[20];
	int date,month,year;
	char city[20];
	char phno[10];
	int money;
	int withd_mon;
	char personname[20];
	char accno[15];
	int tran_mon;
};
int main()
{
	system("cls");
	system("color 04");
    int op;
	printf("\n");
    printf("\t\t\tWELCOME TO BANK MANAGEMENT SYSTEM\t\t");
	printf("\n 1)Create an Account \n \n 2)Login \n \n 3)Contact Us \n \n 4)Exit \n \n Please Make an Option::");
    scanf("%d",&op);
    k:
    do
    {
	switch(op)
	{
	  case 1:
	  	system("cls");
	  	createacc();
	  	break;
	  case 2:
	  	system("cls");
	  	login();
	  	break;
	  case 3:
	  	steps();
	  	break;
	  case 4:
	  	exit(7);
	  	break;
	  default:
	  	printf("Something is Wrong");
	  	goto k;
	}
	printf("\n\n*******************************************************\n");
	printf("*******************************************************\n\n");		
	}while(op!=4);
	return 0;
}
void createacc()
{
	system("cls");
	system("color 03");
	FILE *fp;
	struct registration R1;
	fp=fopen("C:/Users/sarwa/OneDrive/Desktop/C-lang/project_file.txt","w+");
	if(fp == NULL)
	{
        printf("Error opening file.\n");
        return;
    }
    printf("\nenter first name : ");
    scanf("%s",R1.fname);
    printf("\nenter last name : ");
    scanf("%s",R1.lname);
    printf("\nenter the father name : ");
    scanf("%s",R1.fathername);
    printf("\nenter the mother name : ");
    scanf("%s",R1.mothername);
    printf("\nenter date of birth : ");
    scanf("%d/%d/%d",&R1.date,&R1.month,&R1.year);
    int k=((R1.date>=0 && R1.date<=31) && (R1.month>=1 && R1.date<=12) && (R1.year>=1950));
    do
    {
    printf("\nenter phone number : ");
    scanf("%s",R1.phno);
    printf("\nenter the city : ");
    scanf("%s",R1.city);
    printf("\nenter the username  : ");
    scanf("%s",R1.username);
    printf("\nenter the password : ");
    scanf("%s",R1.password);
    FILE *ca;
    ca=fopen("C:/Users/sarwa/OneDrive/Desktop/C-lang/Create_Accno.txt","r");
    printf("\n");
    fscanf(ca,"%s",R1.accno);
    int y;
    for(y=0;y<10;y++)
    {
    	Sleep(100);
    	printf(".");
	}
	system("cls");
	system("color 0e");
	printf("/***Your ACCOUNT is CREATED***/");
	printf("\nYour Account Number is %s",R1.accno);
	printf("\nEnter the minimum amount to Account Completion:");
	scanf("%d",&R1.money);
	FILE *fn;
    fn=fopen("C:/Users/sarwa/OneDrive/Desktop/C-lang/amt.txt","w");
	if(fn==NULL)
	{
		printf("\nError in File opening");
		return ;
	}
	fprintf(fn,"%d",R1.money);
	fclose(fn);
    printf("\nTHANKS FOR YOUR SUPPORT TO US!!");
    fwrite(&R1,sizeof(R1),1,fp);
    fclose(ca);
    fclose(fp);
    createdacc(R1);
	}while((k=1));
}
void createdacc(struct registration R1)
{
	printf("\nLoading");
	int j;
	for(j=0;j<6;j++)
	{
		Sleep(100);
		printf(".");
	}
	system("cls");
	printf("ACCOUNT CREATED SUCCESSFULLY...\n\n");
	int o;
	for(o=0;o<6;o++)
	{
		system("color 06");
		Sleep(100);
	}
	main2(R1);	
}
int main2(struct registration R1)
{
	system("cls");
	system("color 03");
	FILE *fp;
	fp=fopen("C:/Users/sarwa/OneDrive/Desktop/C-lang/project_file.txt","rb");
	if(fp==NULL)
	{
		printf("\nerror in opening file");
    }
	int opt;
	g:
	do
	{
		printf("\n************");
		printf("\n 1)Check my Balance \t \t 2)Transfer Money \n 3)Withdraw Money \t \t 4)Fixed Deposit \n 5)Loan \t \t \t 6)Log out \n 7)Delete Account \t \t 8)Exit \nPlease Make an Option::");
        scanf("%d",&opt);
	switch(opt)
	{
	  case 1:
	  	system("cls");
	  	balance1(R1);
	  	break;
	  case 2:
	  	system("cls");
	  	transfered2(R1);
	  	break;
	  case 3:
	  	system("cls");
	  	withdraw(R1);
	  	break;
	  case 4:
	  	system("cls");
	  	fixed_dep(R1);
	  	break;
	  case 5:
	  	system("cls");
	  	loan(R1);
	  	break;
	  case 6:
	  	system("cls");
	  	logout();
	  	break;
	  case 7:
	  	system("cls");
	  	delacc(R1);
	  	break;
	  case 8:
	  	system("cls");
	    exit(0);
	    break;
	  default:
	  	printf("Something went Wrong");
	  	goto g;
	}
	printf("\n\n*******************************************************\n");
	printf("*******************************************************\n");
	printf("*******************************************************\n\n");
	}while(opt!=8);
	fclose(fp);
	return 0;
}
void login()
{
	system("cls");
	system("color 05");
	char username[30];
	char password[20];
	FILE *fp;
	struct registration R1;
	fp=fopen("C:/Users/sarwa/OneDrive/Desktop/C-lang/project_file.txt","rb");
    printf("\nPLEASE LOGIN\n");
    printf("\nenter username:");
    scanf("%s",username);
    printf("\nenter password:");
    int i=0;
    char ch;
    while(1)
	{
        ch=getch(); // getch() reads a single character without echoing it to the console
        if(ch==13)
		{ // ASCII value of Enter key
            break;
        }
        
        if(ch=='\b' && i>0)
		{ // ASCII value of Backspace key
            printf("\b \b"); // Erase the character from console
            i--;
        }
        else if(ch!='\b')
		{
            password[i++]=ch;
            printf(" "); // Print ' ' instead of the actual character
        }
    }
    printf("\n");
    password[i]='\0'; // Null-terminate the password string
    while(fread(&R1,sizeof(R1),1,fp))
    {
		if(strcmp(username,R1.username)==0 && strcmp(password,R1.password)==0)
		{
			int l;
			for(l=0;l<8;l++)
			{
				Sleep(100);
				printf(".");
			}
			system("cls");
			system("color 02");
			printf("LOGIN SUCCESSFUL..");
			int h;
			FILE *fn;
           fn=fopen("C:/Users/sarwa/OneDrive/Desktop/C-lang/amt.txt","r");
           while(fscanf(fn,"%d",&h)==1)
	      {
	      	 R1.money=h;
		     printf("\nAmount is : %d",R1.money);
	      }    
	        fclose(fn);
			char d;
			printf("\nWant to Check Your Details???");
			scanf("%s",&d);
			if(d=='Y' || d=='y')
			{
				det(R1);
			}
			else
			{
				printf("\nOk");
				exit(8);
			}
		}
	 else
		{
		printf("\nEither Password or Username is Incorrect \t \t AGAIN LOGIN....");
		int f;
		for(f=0;f<7;f++)
		{
			Sleep(100);
			printf(".");
		}
		login();
	    }
	}
	fclose(fp);
}
void delacc(struct registration R1)
{
	FILE *fp;
	fp=fopen("C:/Users/sarwa/OneDrive/Desktop/C-lang/project_file.txt","w+");
	R1.money=0;
	int i,j,k,l,m,n;
	for(i=0;i<sizeof(R1.fname);i++)
	{
		R1.fname[i]='\0';
	}
	for(j=0;j<sizeof(R1.lname);j++)
	{
		R1.lname[j]='\0';
	}
	for(k=0;k<sizeof(R1.phno);k++)
	{
		R1.phno[k]='\0';
	}
	for(l=0;l<sizeof(R1.accno);l++)
	{
		R1.accno[l]='\0';
	}
	for(m=0;m<sizeof(R1.username);m++)
	{
		R1.username[m]='\0';
	}
	for(n=0;n<sizeof(R1.password);n++)
	{
		R1.password[n]='\0';
	}
	printf("\nAccount Deleted Successfully");
	int o;
	for(o=0;o<20;o++)
	{
		Sleep(100);
		printf(".");
	}
	main();
	fclose(fp);
}
void withdraw(struct registration R1)
{
	int y;
    for(y=0;y<7;y++)
	{
		Sleep(100);
		printf(".");
	}
	system("cls");
	system("color 0f");
	struct registration R3;
    do
    {	
    printf("\nenter how much you have:%d",R1.money);
    printf("\nenter how much you have to withdraw:");
    scanf("%d",&R3.withd_mon);
		int u;
        printf("\nWant to transfer your Money?");
        scanf("%d",&u);
        switch(u)
        {
        	case 1:
        		system("cls");
        		transfered(R1,R3);
        		break;
        	case 2:
        		system("cls");
        		balance2(R1,R3);
        		break;
        	default:
        		break;	
		}
	}while(R1.withd_mon<=R1.money);
}
void transfered(struct registration R1,struct registration R3)
{
	system("cls");
	system("color 01");
	FILE *fp;
	struct registration R2;
	fp=fopen("C:/Users/sarwa/OneDrive/Desktop/C-lang/project_file.txt","rb");
	if(fp == NULL)
	{
        printf("Error opening file.\n");
        return;
    }
    char p[15];
    FILE *fd;
    fd=fopen("C:/Users/sarwa/OneDrive/Desktop/C-lang/Acc_no.txt","r"); 
    printf("\n");
    fscanf(fd," %s",p);
    printf("Enter Person name for whom you wanted to Transfer Amount:");
    scanf("%s",R2.personname);
    x:
    printf("Account Number of That Person:");
    scanf("%s",R2.accno);
    printf("Money that you want to Transfer:");
    scanf("%d",&R2.tran_mon);
    if(strcmp(R2.accno,p)==0)
    {
        int v;	
        for(v=0;v<11;v++)
        {
        	R2.accno[v]='X';
		}
        printf("\nYOUR Amount has been Successfully Transfered to %s",R2.accno);
    }
    else
    {
    printf("\nTransfer Error.Please give the Correct Account number..");
    goto x;
    }
    fclose(fd);
    fclose(fp);
    int w;
    printf("\nWant to check your balance?");
    scanf("%d",&w);
    while(getchar()!='\n');
    switch(w)
    {
    	case 1:
    		system("cls");
    		balance3(R1,R2,R3);
    		break;
    	case 2:
    		printf("\nOK");
    		break;
    	default:
    		printf("\nGive Correct option");
    		transfered(R1,R3);
	}
}
void balance1(struct registration R1)
{
	system("cls");
	system("color 07");
	int c;
	for(c=0;c<5;c++)
	{
		Sleep(100);
		printf(".");
	}
	FILE *fp;
	fp=fopen("C:/Users/sarwa/OneDrive/Desktop/C-lang/project_file.txt","rb");
	if(fp==NULL)
	{
		printf("\nerror in opening file");
	}
	printf("\nMy Account Balance is:%d",R1.money); 
	char t4;
	printf("\nWant to see the Details??");
	scanf("%s",&t4);
	if(t4=='Y' || t4=='y')
	{
		details(R1);
	}
}
void balance2(struct registration R1,struct registration R3)
{
	system("color 02");
	if(R1.money>=R3.withd_mon)
	{
		R1.money=R1.money-R3.withd_mon;
	    printf("\nCurrent Balance: %d",R1.money);
	}
	else
	printf("\nNot valid");
	char t3;
	printf("\nWant to see the Details??");
	scanf("%s",&t3);
	if(t3=='Y' || t3=='y')
	{
		details(R1);
	}
}
void balance3(struct registration R1,struct registration R2,struct registration R3)
{
	system("color 06");
	if(R1.money>=R3.withd_mon && R3.withd_mon>=R2.tran_mon)
	{
		R1.money=R1.money-R3.withd_mon;
	    printf("\nCurrent Balance: %d",R1.money);
	}
	else if(R1.money>=R3.withd_mon && R3.withd_mon<R2.tran_mon)
	{
	    R1.money=R1.money-R3.withd_mon-R2.tran_mon;
	    printf("\nCurrent Balance: %d",R1.money);	
	}
	else
	printf("\nNot Valid");
	char t2;
	printf("\nWant to see the Details??");
	scanf("%s",&t2);
	if(t2=='Y' || t2=='y')
	{
		details(R1);
	}
}
void transfered2(struct registration R1)
{
	system("cls");
	system("color 05");
	FILE *fp;
	struct registration R2;
	fp=fopen("C:/Users/sarwa/OneDrive/Desktop/C-lang/project_file.txt","rb");
	if(fp == NULL)
	{
        printf("Error opening file.\n");
        return;
    }
    char p[15];
    FILE *fd;
    fd=fopen("C:/Users/sarwa/OneDrive/Desktop/C-lang/Acc_no.txt","r");
    printf("\n");
    fscanf(fd,"%s",p);
    printf("\nEnter Person name for whom you wanted to Transfer Amount:");
    scanf("%s",R2.personname);
    y:
    printf("\nAccount Number of That Person:");
    scanf("%s",R2.accno);
    printf("\nMoney that you want to Transfer:");
    scanf("%d",&R2.tran_mon);
    if(strcmp(R2.accno,p)==0)
    {
        int b;	
        for(b=0;b<11;b++)
        {
        	R2.accno[b]='X';
		}
        printf("\nYOUR Amount has been Successfully Transfered to %s",R2.accno);
    }
    else
    {
    printf("\nTransfer Error.Please give the Correct Account number..");
    goto y;
    }
    fclose(fd);
    fclose(fp);
    int z;
    printf("\nWant to check your balance?");
    scanf("%d",&z);
    while(getchar()!='\n');
    switch(z)
    {
    	case 1:
    		system("cls");
    		balance4(R1,R2);
    		break;
    	case 2:
    		printf("\nOK");
    		break;
    	default:
    		printf("\nGive Correct option");
    		transfered2(R1);
	}
}
void balance4(struct registration R1,struct registration R2)
{
	system("color 07");
	if(R1.money>=R2.tran_mon)
	{
		R1.money=R1.money-R2.tran_mon;
	    printf("\nCurrent Balance: %d",R1.money);
	}
	else
	printf("\nNot Valid");
	char t1;
	printf("\nWant to see the Details??");
	scanf("%s",&t1);
	if(t1=='Y' || t1=='y')
	{
		details(R1);
	}
}
void fixed_dep(struct registration R1)
{
	int t,r;
	if(R1.money>0 && R1.money<=10000)
	{
		t=3;
		printf("\nTime Period:%d years",t);
	}
	else if(R1.money>10000 && R1.money<=30000)
	{
		t=5;
		printf("\nTime Period:%d years",t);
	}
	else if(R1.money>30000 && R1.money<=75000)
	{
		t=7;
		printf("\nTime Period:%d years",t);
	}
	else if(R1.money>75000 && R1.money<=100000)
	{
		t=8;
		printf("\nTime Period:%d years",t);
	}
	else if(R1.money>100000 && R1.money<=500000)
	{
		t=10;
		printf("\nTime Period:%d years",t);
	}
	else if(R1.money>500000)
	{
		t=12;
		printf("\nTime Period:%d years",t);
	}
	if(t>=0 && t<=3)
	{
		r=2;
		printf("\nRate of Interest per Annum:%d\n",r);
	}
	else if(t>3 && t<=7)
	{
		r=3;
		printf("\nRate of Interest per Annum:%d\n",r);
	}
	else if(t>7 && t<=10)
	{
		r=5;
		printf("\nRate of Interest per Annum:%d\n",r);
	}
	else if(t>10 && t<=20)
	{
		r=7;
		printf("\nRate of Interest per Annum:%d\n",r);
	}
	int l;
	for(l=0;l<20;l++)
	{
		Sleep(100);
		printf(".");
	}
	printf("\n");
	int D;
	D=100*t;
	int h;
	for(h=0;h<t;h++)
	{
		Sleep(D);
		printf(".");
	}
	system("cls");
	system("color 03");
	int I;
	I=(R1.money*t*r)/100;
	R1.money=R1.money+I;
	printf("\nCurrent Balance:%d",R1.money);
	char k;
	printf("\nWant to see your Details?");
	scanf("%s",&k);
	if(k=='Y' || k=='y')
	{
		int p;
	  for(p=0;p<10;p++)
	  {
		  Sleep(100);
		  printf(".");
	  }
	  details(R1);
    }
}
void loan(struct registration R1)
{
	int opt;
	printf("\n1)Money Loan\t\t2)Gold Loan\nEnter one Option:");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:
			printf("\nMoney Loan:");
			int loan_am;
			int O;
			FILE *fl;
           fl=fopen("C:/Users/sarwa/OneDrive/Desktop/C-lang/loan1.txt","r");
           while(fscanf(fl,"%d",&O)==1)
	      {
		     printf("\nLTV is : %d",O);
	      }    
	        fclose(fl);
	        loan_am=(R1.money*O)/100;
	        printf("\nYour Loan has been Sanctioned.");
	       printf("\n%d amount has credited into your Account",loan_am);
	        R1.money=R1.money+loan_am;
	     int t;
	     if(loan_am>0 && loan_am<=10000)
	     {
		    t=3;
		    printf("\nTime Period:%d years",t);
	     }
	     else if(loan_am>10000 && loan_am<=30000)
	     {
		    t=5;
		   printf("\nTime Period:%d years",t);
	     }
	     else if(loan_am>30000 && loan_am<=75000)
	     {
		    t=7;
		    printf("\nTime Period:%d years",t);
	     }
	      else if(loan_am>75000 && loan_am<=100000)
	    {
		   t=8;
		   printf("\nTime Period:%d years",t);
	    }
	    else if(loan_am>100000 && loan_am<=500000)
	    {
	    	t=10;
	    	printf("\nTime Period:%d years",t);
	    }
	     else if(loan_am>500000)
    	{
	    	t=12;
	    	printf("\nTime Period:%d years",t);
	    }
	     int r;
	     if(t>=0 && t<=3)
	     {
		  r=3;
		  printf("\nRate of Interest per Annum:%d\n",r);
	     }
	    else if(t>3 && t<=7)
	    {
		r=5;
		printf("\nRate of Interest per Annum:%d\n",r);
	    }
	     else if(t>7 && t<=10)
	    {
	    	r=7;
		  printf("\nRate of Interest per Annum:%d\n",r);
	     }
	    else if(t>10 && t<=20)
	    {
	    	r=9;
	    	printf("\nRate of Interest per Annum:%d\n",r);
	   }
	     int h;
	   for(h=0;h<20;h++)
	    {
		   Sleep(100);
		   printf(".");
	    }
	    printf("\n");
	    int D;
	    D=100*t;
	     int j;
	    for(j=0;j<t;j++)
	    {
		   Sleep(D);
	    	printf(".");
	    }
	     system("cls");
	    system("color 06");
	     int I;
	     I=(loan_am*t*r)/100;
	       int L;
	      L=loan_am+I;
	     R1.money=R1.money-L;
	       printf("\nCurrent Balance:%d",R1.money);
	     char k;
	      printf("\nWant to see your Details?");
	     scanf("%s",&k);
	     if(k=='Y' || k=='y')
	    {   
	     	int p;
	      for(p=0;p<10;p++)
	     {
		    Sleep(100);
		    printf(".");
	     }
	     details(R1);
         }
	     break;
	    case 2:
	    	printf("\nGold Loan:");
	    	int gl;
	    	printf("\nEnter the price of Gold:");
	    	scanf("%d",&gl);
	    	int V;
			FILE *fg;
           fg=fopen("C:/Users/sarwa/OneDrive/Desktop/C-lang/loan2.txt","r");
           while(fscanf(fg,"%d",&V)==1)
	      {
		     printf("\nLTV is : %d",V);
	      }    
	        fclose(fg);
	    	int l_am=(gl*V)/100;
	    	printf("\nYour Loan has been Sanctioned.");
	       printf("\n%d amount has credited into your Account",l_am);
	    	R1.money=R1.money+l_am;
	     int T;
	     if(l_am>0 && l_am<=10000)
	     {
		    T=1;
		    printf("\nTime Period:%d years",T);
	     }
	     else if(l_am>10000 && l_am<=30000)
	     {
		    T=2;
		   printf("\nTime Period:%d years",T);
	     }
	     else if(l_am>30000 && l_am<=75000)
	     {
		    T=3;
		    printf("\nTime Period:%d years",T);
	     }
	      else if(l_am>75000 && l_am<=100000)
	    {
		   T=5;
		   printf("\nTime Period:%d years",T);
	    }
	    else if(l_am>100000 && l_am<=500000)
	    {
	    	T=6;
	    	printf("\nTime Period:%d years",T);
	    }
	     else if(l_am>500000)
    	{
	    	T=10;
	    	printf("\nTime Period:%d years",T);
	    }
	     int R;
	     if(T>=0 && T<=3)
	     {
		  R=1;
		  printf("\nRate of Interest per Annum:%d\n",R);
	     }
	    else if(T>3 && T<=7)
	    {
		R=2;
		printf("\nRate of Interest per Annum:%d\n",R);
	    }
	     else if(T>7 && T<=10)
	    {
	    	R=3;
		  printf("\nRate of Interest per Annum:%d\n",R);
	     }
	    else if(T>10 && T<=20)
	    {
	    	R=5;
	    	printf("\nRate of Interest per Annum:%d\n",R);
	   }
	    int H;
	   for(H=0;H<20;H++)
	    {
		   Sleep(100);
		   printf(".");
	    }
	    printf("\n");
	    int d;
	    d=100*T;
	     int J;
	    for(J=0;J<T;J++)
	    {
		   Sleep(D);
	    	printf(".");
	    }
	     system("cls");
	    system("color 06");
	     int i;
	     i=(l_am*T*R)/100;
	       int l;
	      l=l_am+i;
	     R1.money=R1.money-l;
	       printf("\nCurrent Balance:%d",R1.money);
	     char K;
	      printf("\nWant to see your Details?");
	     scanf("%s",&k);
	     if(K=='Y' || K=='y')
	    {   
	     	int P;
	      for(P=0;P<10;P++)
	     {
		    Sleep(100);
		    printf(".");
	     }
	     details(R1);
         }
         break;
        default:
        	loan(R1);
	}
	
}
void steps()
{
	system("cls");
	system("color 75");
	FILE *fh;
    fh=fopen("C:/Users/sarwa/OneDrive/Desktop/C-lang/follow.txt","r");
    char word[500];
    if(fh==NULL)
	{
        printf("\nError opening file");
        return ;
    }
    while(fgets(word,500,fh))
	{
        printf("%s",word);
    }
    fclose(fh);
    int j;
    printf("\n");
    for(j=0;j<50;j++)
    {
    	Sleep(1000);
    	printf(".");
	}
    main();
}
void details(struct registration R1)
{
	system("cls");
	system("color 06");
	int y;
	for(y=0;y<11;y++)
    {
        R1.accno[y]='X';
	}
	printf("\nName : %s %s",R1.fname,R1.lname);
    printf("\nAccount Number : %s",R1.accno);
    printf("\nPhone number : %s",R1.phno);
    printf("\nUsername  : %s",R1.username);
    printf("\nPassword : %s",R1.password);
    printf("\nAmount in Account : %d",R1.money);
	FILE *fn;
    fn=fopen("C:/Users/sarwa/OneDrive/Desktop/C-lang/amt.txt","w");
	if(fn==NULL)
	{
		printf("\nError in File opening");
		return ;
	}
	fprintf(fn,"%d",R1.money);
	fclose(fn);
	int k;
    for(k=0;k<15;k++)
    {
    	Sleep(1000);
    	printf(".");
	}
	main2(R1);
}
void det(struct registration R1)
{
	system("cls");
	system("color 04");
	int j;
	for(j=0;j<11;j++)
    {
        R1.accno[j]='X';
	}
	printf("\nName : %s %s",R1.fname,R1.lname);
	printf("\nAccount Number : %s",R1.accno);
    printf("\nPhone number : %s",R1.phno);
    printf("\nUsername  : %s",R1.username);
    printf("\nPassword : %s",R1.password);
    printf("\nAmount in Account : %d",R1.money);
    int k;
    for(k=0;k<15;k++)
    {
    	Sleep(1000);
    	printf(".");
	}
    main2(R1);
}
void logout()
{
	system("cls");
	system("color 06");
	int o;
	for(o=0;o<30;o++)
	{
	    Sleep(100);
		printf(".");	
	}
	system("cls");
	system("color 04");
	printf("\nLOGGED OUT SUCCESSFULLY..\n");
	exit(7);
}
