#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
long int bal,invest,withdraw,acc_num=4700,pos=0;
char name[30],ch[30],copy[30];
void login();
void reg();
int main()
{
	int ch;
	clrscr();
	printf("\n====|||||==$ Welcome to our Bank $==||||====\n");
	do{
		printf("\n$-What Do You want-$\n\n");
		printf("1.Login Account\n2.Create New Account\n3.Exit\n\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				login();
				break;
			case 2:
				reg();
				break;
			default:
				printf("\nWrong choice\n");
		}
	   }while(ch!=3);
	return 7;
}
void login()
{
	int choice,f=0;
	char pass[20];
	FILE *fp;
	clrscr();
	printf("\n|||***- THANK YOU FOR LOGIN -***|||\n");
	printf("\n  Account number = ");
	scanf("%s",name);
	printf("\tPassword = ");
	scanf("%s",pass);
	strcat(name," ");
	strcat(name,pass);
	strcat(name,"\n");
	fp=fopen("Bank_DB.txt","r+");
	if(fp==NULL)
	{
	printf("Please, create account");
	printf("\nPress any key\n");
	getch();
	clrscr();
	return ;
	}
	fseek(fp,0,SEEK_SET);
	fgets(ch,20,fp);
	while(!feof(fp))
	{
	if(!strcmp(ch,name))
	{
		f=1;
		pos=ftell(fp);
		fgets(ch,20,fp);
		bal=atol(ch);
		clrscr();
		printf("\n====||||-- Welcome Dear Custmer --||||====\n\n");
		do
		{
		printf("\n$-What Do You want-$\n\n");
		printf("1.Check Balance\n2.CASH DEPOSIT\n3.CASH WITHDRAWAL\n4.LOG OUT\n");
		printf("\nEnter Your choice:");
		scanf("%d",&choice);
		clrscr();
		switch(choice)
		{
			case 1:
				printf("\nYour Balance = %ld INR",bal);
				printf("\nPress any key\n");
				getch();
				break;
			case 2:
				printf("\nEnter Amount = ");
				scanf("%ld",&invest);
				if((bal+invest) > 214748384)
				{
				printf("Your whole Amount is going upto \"20 Crore\"");
				printf("\nPlease Don't Exceed Bank Limit");
				}
				else
				{
				printf("%ld INR Credited Successfully!!",invest);
				bal=bal+invest;
				}
				printf("\nPress any key\n");
				getch();
				break;
			case 3:
				printf("\nEnter Amount =");
				scanf("%ld",&withdraw);
				if(withdraw<=bal)
				{
					bal=bal-withdraw;
					printf("%ld INR Debited Sucessfully!!",withdraw);
				}
				else
				{
					printf("Insufficient Balance");
				}
				printf("\nPress any key\n");
				getch();
				break;
		}
		clrscr();
		printf("===--===||-----$-----||===--===\n\n");
		}while(choice!=4);
		fseek(fp,pos,SEEK_SET);
		fprintf(fp,"%012ld",bal);
		fclose(fp);
		clrscr();
		printf("\n||---|| Thank you for come in our Bank ||---||\n\n");
		break;
	}
	fgets(ch,20,fp);
	fgets(ch,20,fp);
	}
	if(f==0)
	{clrscr();
	printf("Invalid Credits !!\n\n");
	}
}
void reg()
{
	FILE *fp;
	char pass[20],start[20]="000000000000";
	fp=fopen("Bank_DB.txt","r");
	if(fp==NULL)
	{
		fclose(fp);
		fp=fopen("Bank_DB.txt","w");
		fprintf(fp,"%ld\nAbove Last Acc_no",acc_num);
	}
	else
	{
	fclose(fp);
	fp=fopen("Bank_DB.txt","r+");
	fseek(fp,0,SEEK_SET);
	fscanf(fp,"%s",copy);
	acc_num=atoi(copy)+1;
	fseek(fp,0,SEEK_SET);
	fprintf(fp,"%ld",acc_num);
	}
	fclose(fp);
	clrscr();
	printf("!! Thank you for being a member of our bank !!\n\n");
	printf("Your Account number is %ld\n",acc_num);
	printf("Enter your Password:");
	scanf("%s",pass);
	clrscr();
	printf("\n!!!--Your Account has been sucessfully Created--!!!\n");
	printf("\nNOTE : Don't forgot your Account number and Password\n");
	printf("\n\t Account number = \"%ld\"\n\t\tPasswod = \"%s\"\n",acc_num,pass);
	fp=fopen("Bank_DB.txt","a+");
	fprintf(fp,"\n%ld %s\n%s",acc_num,pass,start);
	fclose(fp);
	printf("\nPress any key if remembered Acc_no and password\n");
	getch();
	clrscr();
}
