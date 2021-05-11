//                                   Bank System
#include<stdio.h>
#include<conio.h>

int login(); 		         // - For Login Account
int  reg();                  // - For Create New Account
void Add(char*,char*);       // - For Addition of Two Numbers
int  Sub(char*,char*);       // - For substraction of Two Numbers
int passInput();             // - For Talking Password Carefully
int  Valid_Input(char *Inp); // - For Checking Input is Valid or Not
void Append(char *,char *);  // - For Append string
void passEncrypt(char *);    // - For Encrypt the Data
void passDecrypt(char *);    // - For Decrypt the Data
int  fpass();		         // - For Change The Password of User
int  Aadhar_num();           // - Takes only 12 digit numeric value from user
int HomePage();              // - Take Admin Choice for login or forget password
int AdminLogin();            // - Admin Login Page
int Adminfpass();            // - It provides forget password facility
void Window();               // - It is print Welcome page
void ZeroAppend(char*);      // - It is appending zeros to acc_num and password
int LengthCount();	         // - It is used for Count the length of given string
int main()
{
     char ch;
     int c=0;
     do
     {
     if(!HomePage())               // Control Moves to Homepage
     return 0;
     system("cls");
     printf("\n\n\n\t\t\t\t\t\t\t      ||-- $-$ Welcome to our Bank $-$ --||\n");
     do{
	printf("\n\n\t\t\t\t\t\t\t\t     $ - What Do You want -$\n\n");
	printf("\n\t\t\t\t\t\t\t\t       1.Login Account\n\n\t\t\t\t\t\t\t\t       2.Create New Account");
	printf("\n\n\t\t\t\t\t\t\t\t       3.Forget Password\n\n\t\t\t\t\t\t\t\t       4.Logout the System\n\n");
	printf("\n\t\t\t\t\t\t\t\t       Enter your choice : ");
	scanf(" %c",&ch);
	fflush(stdin);
	switch(ch)
	{
		case '1':
			if(login())
			{
			system("cls");
			printf("\n\n\t\t\t\t\t\t\t        ||==$==|| Login UnSuccessful ||==$==||\n");
			}
			break;
		case '2':
			if(!reg())
			printf("\n\t\t\t\t\t\t\t\t   !!!-= Registration Failed =-!!!\n");
			break;
		case '3':
			if(!fpass())
			{
			printf("\n\n\t\t\t\t\t\t\t   Something Went Wrong !!\n");
			printf("\n\t\t\t\t\t\t\t   Press Any Key\t");
			getch();
			system("cls");
			}
			printf("\n\t\t\t\t\t\t\t   !!====-$-====||-----$$$-----||====-$-====!!\n");
			break;
		case '4' :
			break;
		default:
			system("cls");
			c++;
			printf("\n\t\t\t\t\t\t\t       !!==||--$ Enter Correct Choice $--||==!!\n");
	}
	}while(ch!='4' && c<3);
     }
     while(c<=5);
     return 0;
}
int HomePage()
{
     int fl=0,c=-1;
     char ch[50];
     do
     {
     c++;
     system("cls");
     Window();
     if(c!=0)
     printf("\n\t\t\t\t\t\t\t\t       !!  Invalid Input  !!");
     printf("\n\n\t\t\t\t\t\t\t\t\t     1.Admin Login ");
     printf("\n\n\t\t\t\t\t\t\t\t\t     2.Forget Password\n\n");
     printf("\t\t\t\t\t\t\t\t\t     3.Logout\n\n");
     printf("\t\t\t\t\t\t\t\t\t     CHOICE : ");
     scanf("%2s",ch);
     if(ch[1])
     continue;
     switch(ch[0])
     {
		case '1':
			if(AdminLogin())
			fl=1;
			break;
		case '2':
			if(Adminfpass())
			c=-1;
			break;
		case '3':
			return 0;
     }
     }
     while(fl!=1 && c<3);
     if(fl==1)
     return 1;
     else
     return 0;
}
int AdminLogin()
{

     FILE *fp;
     char AdminUserName[50],AdminPass[30],ch[30];
     char FileUserName[21],FilePass[21],tmp[10]="4700";
     int fl=0,c=-1;
     do
     {
     c++;
     system("cls");
     Window();
     if(c!=0)
     printf("\n\n\t\t\t\t\t\t\t\t       !!  Invalid Credentials");
     printf("\n\n\t\t\t\t\t\t\t\t\t UserName : ");
     scanf("%s",AdminUserName);
     if(LengthCount(AdminUserName))
     continue;
     printf("\n\t\t\t\t\t\t\t\t\t Password : ");
     if(passInput(AdminPass))
     continue;
     Append(AdminUserName,AdminPass);
     ZeroAppend(AdminUserName);
     fp=fopen("DB.txt","r");

     // To Create Bank_DB.txt File At the start when System will not have Bank_DB.txt file

     if(fp==NULL)
     {
	fclose(fp);
	passEncrypt(tmp);
	fp=fopen("DB.txt","w");
	fprintf(fp,"%s\n%s",tmp,AdminUserName);
	fclose(fp);
	fp=fopen("DB.txt","r");
     }
     fscanf(fp,"%s\n%s",tmp,FileUserName);
     fclose(fp);
     if(!strcmp(AdminUserName,FileUserName))
     fl=1;
     }
     while(fl!=1 && c<3);
     if(fl!=1)
     {
     printf("\n\n\t\t\t\t\t\t\t\t\tTry After Some Time     ");
     getch();
     return 0;
     }
     return 1;
}
int Adminfpass()
{
	FILE *fp;
	char  Ukey[10],key[10]="Key1@123",UName[40],Upass[30],Tmppass[30],tmp[40];
	system("cls");
	Window();
	printf("\n\n\n\t\t\t\t\t\t\t\t\tEnter Key : ");
	if(passInput(Ukey))
	return 0;
	if(strcmp(key,Ukey))
	return 0;
	system("cls");
	Window();
	printf("\n\n\t\t\t\t\t\t\t\t    New User Name : ");
	scanf("%s",UName);
	if(LengthCount(UName))
	return 0;
	printf("\n\t\t\t\t\t\t\t\t     New Password : ");
	if(passInput(Upass))
	return 0;
	printf("\n\n\t\t\t\t\t\t\t\t Confirm Password : ");
	passInput(Tmppass);
	if(strcmp(Upass,Tmppass))
	return 0;
	Append(UName,Upass);
	ZeroAppend(UName);
	fp=fopen("DB.txt","r+");
	fseek(fp,0,SEEK_SET);
	fscanf(fp,"%s",tmp);
	rewind(fp);
	fprintf(fp,"%s\n%s",tmp,UName);
	fclose(fp);
	printf("\n\n\n\t\t\t\t\t\t\t    UserName And Passsword Changed Successfully !!");
	getch();
	return 1;
}
void ZeroAppend(char *pass)
{
     int i=0;

     while(pass[i]!='\0')
     i++;
     while(i<=40)
     {
	pass[i]='0';
	i++;
     }
     pass[i]='\0';
     passEncrypt(pass);

}
void Window()
{

printf("\n\n\n\t\t\t\t\t\t\t\t\t     Hello Admin    ");
printf("\n\n\n\t\t\t\t\t\t\t\t   Welcome To Bank Management System");
printf("\n\n\n\t\t\t\t\t\t\t\t   >>>>>>>>  ADMIN LOGIN  <<<<<<<<<\n");

}
int login()
{
	int Flag=0,pos=0,i;

/*
   Flag     - Flag will 1 if user credential will match
   pos      - Pos is used for stoing the position of curser in the file
   i        - It is used in the Loop.
*/

	char bal[65],invest[51],withdraw[51],temp_withdraw[51];

/*

bal      - It is used for storing the Balance of user from file if User will Login Successfully.
invest   - It is used for storing the Amount which is User Want to invest
Withdraw - It is used for storing the Amount which is User Want to Withdraw
temp_withdraw - To store User Balance temporary purpose to check Withdraw Amount is Less than Balance

*/

	char U_Choice,ch,pass[50]="",File_User_Data[50]="",User_Data[50]="";

/*

U_Choice - Used for Taking choice from user for balance check , credit or debit Amount
pass[50] - Store Password taken from user
File_User_Data - To store data retrived from File
User_Data      - To store data taken from user . Data is Account number and Passwprd

		 Below Taking the Credential From User for Login                         */

	FILE *fp=NULL;
	system("cls");
	printf("\n\n\n\t\t\t\t\t\t\t   !!***!! THANK YOU FOR LOGIN !!***!!\n");
	printf("\n\n\t\t\t\t\t\t\t     Account number : ");

//    Taking Account Number From User

	scanf("%s",User_Data);
	if(LengthCount(User_Data))
	return 1;
	printf("\n\t\t\t\t\t\t\t\t   Password : ");

//    Taking Password from User

	if(passInput(pass))
	return 1;

//    Appending Password to Account Number

	Append(User_Data,pass);

	ZeroAppend(User_Data);

//    Opening " Bank_Db " file in read and write Mode.

	fp=fopen("DB.txt","r+");

//    If File not exist program Return from here

	if(fp==NULL)
	{
	printf("\n\t\t\t\t\t\t\t\t   Please, create account");
	printf("\n\t\t\t\t\t\t\t\t   Press any key\n");
	getch();
	system("cls");
	return 1;
	}

//     Set Curser At Zero Location

	fseek(fp,0,SEEK_SET);

//     Taking User Data from the file to Compare with User Credential

	fscanf(fp,"%s",File_User_Data);

//     While Loop used for Traverse All the File for Checking the Credential

	while(!feof(fp))
	{

	//     Comparing Data of the File and User Data Is Matching or Not

	if(!strcmp(File_User_Data,User_Data))
	{

	//     If Data Matched means user exist and Credential are right

		pos=ftell(fp);           // Stored Position of Curser to use later
		fscanf(fp,"%s",bal);     // Balace of user stored in bal variable
		passDecrypt(bal);        // Encrypted Balance in the file is decrypted here
		ch=bal[49];
		bal[49]='\0';
		system("cls");
		printf("\n\n\t\t\t\t\t\t\t    !!--$$$ == Welcome Dear Custmer == $$$--!!\n\n");
		do
		{
		printf("\n\t\t\t\t\t\t\t\t      $- What Do You want -$\n\n");
		printf("\n\t\t\t\t\t\t\t\t      1.Check Balance\n\n\t\t\t\t\t\t\t\t      2.CASH DEPOSIT");
		printf("\n\n\t\t\t\t\t\t\t\t      3.CASH WITHDRAWAL\n\n\t\t\t\t\t\t\t\t      4.LOG OUT\n\n");
		printf("\n\t\t\t\t\t\t\t\t      Enter Your choice : ");
		U_Choice=getch();
		system("cls");
		printf("\n\n\n\t\t\t\t\t\t\t   !!====-$-====||-----$-----||====-$-====!!\n");
		switch(U_Choice)
		{
			case '1':
				Flag=0;
				printf("\n\n\t\t\t\t\t\t\t\t   Your Balance : ");

/*   In File , Balance is followed by zeros eg. 000000000000000005790
     To Avoid initial Zeros while Displaying Balace this for loop is used  */

				for(i=0;bal[i]!='\0';i++)
				{
				if(Flag==0 && bal[i]=='0')
				continue;
				else
				Flag=1;
				printf("%c",bal[i]);
				}

//   To simply print 0 INR Balance if Balalace Containing All Zeros

				if(Flag==0)
				printf(" 0");
				printf(" INR\n\n\t\t\t\t\t\t\t\t   Press any key\n\n\t\t\t\t\t\t\t\t   ");
				getch();
				break;
			case '2':
				printf("\n\n\t\t\t\t\t\t\t\t   Credit Amount = ");
				scanf("%s",&invest);

//  Here We Call Valid_Input function to check user input is number or not

				if(Valid_Input(invest))
				{
				printf("\n\t\t\t\t\t\t\t\t   %s INR Credited Successfully!!",invest);
				Add(bal,invest);
				}
				printf("\n\n\t\t\t\t\t\t\t\t   Press any key\n\n\t\t\t");
				getch();
				break;
			case '3':

				printf("\n\n\t\t\t\t\t\t\t\t   Withdraw Amount = ");
				scanf("%s",withdraw);

// Here Also We check withdraw Amount is Number or not

				if(Valid_Input(withdraw))
				{
// We store User_Balance Amount in temp_withdraw Character_Array

				for(i=0;bal[i]!='\0';i++)
				temp_withdraw[i]=bal[i];
				temp_withdraw[i]='\0';

// Here we check withdraw balance is greater than or less than the User Balace

				if(Sub(temp_withdraw,withdraw)){

				// If Withdraw Amount Less than User Balance then only We withdraw Balance
					Sub(bal,withdraw);
					printf("\n\t\t\t\t\t\t\t\t   %s INR Debited Sucessfully!!",withdraw);
				}
				else
				{
					printf("\n\t\t\t\t\t\t\t\t   Insufficient Balance");
				}
				}
				printf("\n\n\t\t\t\t\t\t\t\t   Press any key\n\n\t\t\t");
				getch();
				break;

		}
		system("cls");
		printf("\n\t\t\t\t\t\t\t\t|| ===--===||-----$-----||===--===||\n\n");
		}while(U_Choice!='4');
		Flag=1;
		bal[49]=ch;
 // Previously We saved position of cursor that we useing here to store balance at same Position

		fseek(fp,pos,SEEK_SET);

 // Encrypting Balance again to store Encrypted balance in file

		passEncrypt(bal);
		fprintf(fp,"\n%s",bal);
		fclose(fp);
		system("cls");
		printf("\n\n\t\t\t\t\t\t\t   ||---|| Thank you for come in our Bank ||---||\n");
		break;
	}

 /*
    Users Account number and passwords are at odd lines of file so
    we are scanning line two times for ignore Unnecessary even positions
 */

	fscanf(fp,"%s",File_User_Data);
	fscanf(fp,"%s",File_User_Data);
	}

 // If File Will end and credential will not match then flag remains zero

	if(Flag==0)
	return 1;
	else
	return 0;
}

int reg()
{
	FILE *fp;
	char pass[50],tmpPass[50],ch,acc_num[50],A_num[13];
/*
 pass    - it is used for store password taken from user
 tmpPass - it is used for store password taken by user for confirmation of password
 ch      - Taking confirmation choice from the user to create account or not
 acc_num - To Store Account number
*/

	char Start_Bal[65]="0000000000000000000000000000000000000000000000000";
	int fl=0,flag=0,f=0;
	system("cls");
	printf("\n\n\t\t\t\t\t\t\t     !!====-$-====||-----$-----||====-$-====!!\n");
	printf("\n\n\t\t\t\t\t\t\t\t   Really Do You Want open Account !!!\n\n");
	printf("\t\t\t\t\t\t\t\t   1.Yes\n\n\t\t\t\t\t\t\t\t   2.No\n\n\t\t\t\t\t\t\t\t   Enter a choice : ");
	ch=getch();
	system("cls");
	if(ch!='1')
	return 0;

	// Open File For read and Write

	fp=fopen("DB.txt","r+");
	fseek(fp,0,SEEK_SET);    // Set file_Curser at location zero
	fscanf(fp,"%s",acc_num); // to scan 1st line which having last Account number
	passDecrypt(acc_num);    // Decrypt Account number
	Add(acc_num,"1");        // Here Add 1 to last account number to generate next account number
	passEncrypt(acc_num);
	fseek(fp,0,SEEK_SET);    // Again Set Curser to Zero
	fprintf(fp,"%s",acc_num);// At first line save generated password for generate next account number
	fclose(fp); 		 // Close the File
	system("cls");
	passDecrypt(acc_num);
	printf("\n\n\t\t\t\t\t\t\t   !! Thank you for being a member of our bank !!\n\n");

//  If password and Confirmation password are not matched then for repeating password do-while loop used
	do
	{
	if(flag==0)
	{
	printf("\n\t\t\t\t\t\t\t   Your Account number is %s\n\n",acc_num);
	printf("\t\t\t\t\t\t\t   Enter your Aadhaar no : ");
	   if(!Aadhar_num(A_num))
	   {
		system("cls");
		printf("\n\t\t\t\t\t\t\t   !! Thank you for being a member of our bank !!\n\n");
		printf("\n\t\t\t\t\t\t\t   !! Note : Enter 12 Digit Aadhar number !!\n");
		continue;
	   }
	   flag=1;
	}
	else
	{
	printf("\n\t\t\t\t\t\t\t   Your Account number is %s\n\n",acc_num);
	printf("\t\t\t\t\t\t\t   Enter your Aadhaar no : %s%s",A_num,"");
	}
	printf("\n\n\t\t\t\t\t\t\t     Enter your Password : ");
	if(!passInput(pass))                       // Taking password
	{
	printf("\n\n\t\t\t\t\t\t\t   Confirm Your Password : ");
	if(!passInput(tmpPass))                   // Taking password for confirmation
	f=1;
	}
	else
	f=0;

// Here Check entered password and confirm password are equal or not

	if(!strcmp(pass,tmpPass) && f==1)
	{
	fl=1;
	system("cls");

// To Show Account is Successfully Created

	printf("\n\n\t\t\t\t\t\t\t   !!!--Your Account has been sucessfully Created--!!!\n");
	printf("\n\t\t\t\t\t\t\t   NOTE : Don't forgot your Account number and Password\n");
	printf("\n\t\t\t\t\t\t\t\t    Account number = \" %s \"\n\n\t\t\t\t\t\t\t\t\t   Passwod = \" %s \"\n",acc_num,pass);
    Append(acc_num,pass);     // Append pass to acc_num to store in file
	ZeroAppend(acc_num);

// Open File for Storing Account number and Balance as a Zero balance
	Append(Start_Bal,A_num);
	passEncrypt(Start_Bal);
	fp=fopen("DB.txt","a+");
	// New Account no and balance stored in File
	fprintf(fp,"\n%s\n%s",acc_num,Start_Bal);
	fclose(fp);
	printf("\n\t\t\t\t\t\t\t   Press any key if remembered Acc_no and password\t");
	getch();
	system("cls");
	}
	else{

// If passwords are not Matched then this Execute

	system("cls");
	printf("\n\n\n\t\t\t\t\t\t\t   =====!!-PASSWORD NOT MATCHED-!!====\n\n");
	printf("\n\t\t\t\t\t\t\t   Please enter password again carefully\n\n");
	}
	}while(fl!=1);  // if password is matched then flag becomes 1 and and condition fails
	printf("\n\n\t\t\t\t\t\t\t   !!====-$-====||-----$$$-----||====-$-====!!\n");
	return 1;
}

int passInput(char *Pass)
{
	int i=0;
	char ch1;
	ch1=getch();
	for(i=0;ch1!=13 && i < 19;i++)
	{
		Pass[i]=ch1;
		printf("*");
		ch1=getch();
	}
	Pass[i]='\0';
	if(i>=18)
	return 1;
	else
	return 0;
}

// This function takes two string containing digits only and perform additon operation like additon of two numbers

void Add(char *n1,char *n2)
{
	int i=0,Len1=-1,Len2=-1,rem=0;
	while(n1[Len1+1]!='\0')     // Here , We Count length of string_One
	Len1++;
	while(n2[Len2+1]!='\0')     // Here , We Count length of string_Two
	Len2++;
	while(Len2!=-1)  // this loop Iterate upto length of 2nd strings become -1
	{
		// Here for Adding digits check addition of digit is less than 10

		if( ( i= (n1[Len1] + n2[Len2] - 96 + rem) ) <=9 )
		{
			n1[Len1]=48+i;  // 48 is bcoz ascii value of numbers start from 48 and i is value want to add
			rem=0;          // e.g 48 + 5 = 53 which assign as 5 in string bcoz 53 is ascii value of 5
		}
		else
		{
		/* If Addition of digits greater than 9 then we substract 10 by that value
		 and value aasign e.g value=15 then 48 + (15-10) =53 which is 5
		 and set rem=1 to add in next number */

			n1[Len1]=48+(i-10);
			rem=1;
		}
		Len2--;
		Len1--;

	}
/*
   When string_2 ends means 2nd number ends and remaidner=1 then for add it to next digit
   while loop is used but may be after adding remainder next remainder can be generate
   so untill remainder =0 loops iterate and check for 1st number is also not finish i.e 1st_string
*/
	while(rem!=0 && Len1!=-1)
	{
		if( (i=(n1[Len1]+rem-48))<=9){
			n1[Len1]=48+i;
			rem=0;
		}
		else
		{
			n1[Len1]=48;
			rem=1;
		}
		Len1--;
	}
}

// As Additon of Two Numeric_Strings , Here Substration is performs

int Sub(char *n1,char *n2)
{
	int i=0,Len1=48,Len2=-1,Borrow=0;
	while(n2[Len2+1]!='\0')
	Len2++;
	while(Len2!=-1)
	{
		if( ( i= (n1[Len1] - n2[Len2] - Borrow ) ) >=0 )
		{
			n1[Len1]=48+i;
			Borrow=0;
		}
		else
		{
			n1[Len1]=48+( ( n1[Len1] + 10 ) - n2[Len2] ) - Borrow ;
			Borrow=1;
		}
		Len2--;
		Len1--;

	}
	while(Borrow!=0 && Len1!=-1)
	{
		if( (i=(n1[Len1] - 48 - Borrow)) >=0){
			n1[Len1]=n1[Len1]-Borrow;
			Borrow=0;
		}
		else
		{
			n1[Len1]=48+9;
			Borrow=1;
		}

		Len1--;
		Len2--;
	}
	if(Borrow==0)
	return 1;
	else
	return 0;
}

// Here if entered char will not between 0 to 9 then it display Invalid input

int Valid_Input(char *Inp)
{
	int Flag=0,i=0;
	for(i=0;Inp[i]!='\0';i++)
	{
		if(Inp[i]<48 || Inp[i]>57 || i>=30)
		{
			Flag=1;
			printf("\n\t\t\t\t\t\t\t   Invalid_Input , Something Went Wrong!!");
			break;
		}
	}
	if(Flag==1)
	return 0;
	else
	return 1;
}

// For Concat two strings Append function is derived

void Append(char *str1,char *str2)
{
	int i=0,j=0;
	while(str1[i]!='\0')
	i++;
	while(str2[j]!='\0')
	{
	str1[i]=str2[j];
	i++;
	j++;
	}
	str1[i]='\0';
}

/*

 This Function Take a string to Encrypt
 And add length of string and 2 * (location + length of String)
 to the character and change it's value so it will be not easily readable
 Here By adding key If ASCII value of character cross 122 then (value -122)
 add in 32 so value becomes in between Ascii 33 to Ascii 122

*/

void passEncrypt(char *passE)
{
	int i=0,key=0,value=0,tmp=0;
	while(passE[key]!='\0')
	key++;
	while(passE[i]!='\0' && passE[i]!='\n')
	{
		value=(i+key);
		if((tmp=passE[i]+value)>122)
		passE[i]=33+tmp-122;
		else
		passE[i]=passE[i]+value;
		i++;
	}
}

/*
 As In Encryption value is added ,To make it's original value ,Here
 create key same as Encryption using string length and position of character and substrat
 key from the encrypted value so it becomes original
 As In Encryption if Encrypted value cross 122 then add extra value to 33
 here passD[i]- value less than 33 then value greater than 33 we leave it and less than 33 value store
 and we sustract it from 122 and get original Value
*/

void passDecrypt(char *passD)
{
	int i=0,key=0,value=0,tmp=0;
	while(passD[key]!='\0')
	key++;
	while(passD[i]!='\0' && passD[i]!='\n')
	{
		value=(i+key);
		if((tmp=passD[i]-value)<=33)
		passD[i]=122-(33-tmp);
		else
		passD[i]=passD[i]-value;
		i++;
	}
}
int Aadhar_num(char *pass)
{
	char ch;
	int c=0;
	while(c!=12)
	{
		ch=getch();
		if(ch>=48 && ch <= 57)
		pass[c]=ch;
		else
		{
			return 0;
		}
		printf("%c",ch);
		c++;
	}
	pass[c]='\0';
	return 1;
}
int fpass()
{
	FILE *fp=NULL;
	char A_num[13],key[30],File_Data[65],Acc_num[60],key1[10]="Key2@123",pass[50],tmp_pass[50];
	int i=0,j=0,fl=1,pos;
	system("cls");
	printf("\n\n\t\t\t\t\t\t\t   ==||---||==$ Welcome to our Bank $==||---||==\n");
	printf("\n\n\t\t\t\t\t\t\t   Enter the Key : ");
	if(passInput(key))
	return 0;
	if(strcmp(key,key1))
	return 0;
	printf("\n\n\t\t\t\t\t\t\t   Enter Account Number : ");
	scanf("%s",Acc_num);
    while(Acc_num[i]!='\0')
    i++;
	if(i>18 || i<4)
	return 0;
    i=0;
	printf("\n\t\t\t\t\t\t\t   Enter Your Aadhaar number : ");
	if(!Aadhar_num(A_num))
	return 0;
	fp=fopen("DB.txt","r+");
	if(fp==NULL)
	return 0;
	fseek(fp,0,SEEK_SET);
	fscanf(fp,"%s",File_Data);
	fscanf(fp,"%s",File_Data);
	while(!feof(fp))
	{
		j=0;
		fl=0;
		i=0;
		pos=ftell(fp);
		fscanf(fp,"%s",File_Data);
		passDecrypt(File_Data);
		for(i=0;i<Acc_num[i]!='\0' ;i++)
		{
			if(File_Data[i]!=Acc_num[i])
			{
			fl=1;
			break;
			}
		}
		fscanf(fp,"%s",File_Data);
		if(fl==1)
		continue;
		passDecrypt(File_Data);
		for(i=49;File_Data[i]!='\0';i++)
			{
			if(A_num[j]!=File_Data[i])
			{
				fl=1;
				break;
			}
			j++;

		}
		if(fl==0)
		break;
	}
	if(fl==0)
	{
		fl=-1;
		do
		{
		system("cls");
		printf("\n\n\t\t\t\t\t\t\t   !!====-$-====||-----$$$-----||====-$-====!!\n");
		if(fl!=-1)
		printf("\n\n\t\t\t\t\t\t\t\t !!  Passwords Not Matched !!\n");
		fl=0;
		printf("\n\n\t\t\t\t\t\t\t     Enter New Password : ");
		  if(!passInput(pass))
		  {
		    printf("\n\n\t\t\t\t\t\t\t     Confirm New Password : ");
		    if(!passInput(tmp_pass))
		    {
		    if(!strcmp(pass,tmp_pass))
		    fl=1;
		    }
		  }
		}
		while(fl!=1);
		fseek(fp,pos,SEEK_SET);
		Append(Acc_num,pass);
		ZeroAppend(Acc_num);
		fprintf(fp,"\n%s",Acc_num);
		printf("\n\n\n\t\t\t\t\t\t\t     Passsword Changed Successfully !!\t");
	}
	else
	{
	printf("\n\n\t\t\t\t\t\t\t   Sorry This Account is Invalid!!\n");
	printf("\n\t\t\t\t\t\t\t   Press Any Key\t");
	}
	fclose(fp);
	getch();
	system("cls");
	return 1;
}
int LengthCount(char *username)
{
	int i=0;
	while(username[i]!='\0' && i<18)
	i++;
	if(i>=18)
	return 1;
	return 0;
}
