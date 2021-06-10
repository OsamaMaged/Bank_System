#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef char string;
#define MAX_Users 10
typedef struct {
	string name[10];
	string pw[10];
	uint16 balance;
	
}account;

/* COMPILED USING WINDOWS POWERSHELL (gcc compiler) */
int main()
{	FILE *file;
	file= fopen("acc.txt","a+");
    account user;
	account users[MAX_Users];
	
    int length = 255;
    char txt[length];
    int ind=0;
	
    while(fgets(txt, length, file))
    {
        strcpy(user.name,txt);
        fgets(txt, length, file);
        strcpy(user.pw,txt);
        fgets(txt, length, file);
        user.balance = atoi(txt);
        users[ind]=user;
        ind++;
    }	
	uint8 i=0;
	int ch;
	uint16 money;
	string Name[10],password[10];
	string Name2[10];
	printf("Please enter your user name and password\n");
	scanf("%s %s",Name,password);
	strcat(Name,"\n");
	 strcat(password,"\n");
	for(i=0; i< MAX_Users;i++)
	{	
		if(!(strcmp(users[i].name, Name)))
		{	while(strcmp(users[i].pw, password)) //cmp return 0 if true 1 if false password
			{
				printf("Wrong password, Try again\n");
				scanf("%s",password);
				strcat(password,"\n");
			}
			printf("Please choose your operation\n");
			do{	printf("[1]: Add [2]: Withdraw [3]: Transfer\n");
				scanf(" %d",&ch);
			}while((ch>3)||(ch<1));
			if(ch==1)
			{	user=users[i];
				printf("Please enter amount of money you want to add\n");
				scanf(" %hi",&money);
				printf("Your balance was: %d\n",users[i].balance);	
				users[i].balance = (users[i].balance + money);
				printf("Your balance now: %d\n",users[i].balance);
				
			}
			else if(ch==2)
			{
				printf("Please enter amount of money you want to withdraw\n");
				scanf(" %hi",&money);	
				users[i].balance = users[i].balance - money;
				printf("Your balance now: %d\n",users[i].balance);
			}
			else if(ch==3)
			{
				printf("Please enter amount of money you want to transfer\n");
				scanf(" %hi",&money);
				printf("Please enter the second account's username\n");
				scanf(" %s",Name2);
				strcat(Name2,"\n");
				uint8 x=0;
				for(x=0; x< MAX_Users;x++)
				{if(!(strcmp(users[x].name, Name2)))
						break;
				}
				if(x==MAX_Users)
				{printf("Second account doesn't exist!\n");goto END;}
				else
				{	users[x].balance = (users[x].balance + money);
					users[i].balance = (users[i].balance - money);
					printf("Done, Your balance now: %d\n",users[i].balance);

				}
			}
			break;
			
		}
	}
	if(i==(MAX_Users))
	{	uint8 flag[3];
		printf("This username is not exist do you want to sign up (yes or no)?\n");
		scanf(" %s",&flag);
		if(!(strcmp(flag,"yes")))	{
			printf("Please enter your new Account username and password\n");
			scanf("%s %s",user.name,user.pw);
			strcat(user.name,"\n");
			strcat(user.pw,"\n");
			printf("Please enter balance\n");
			scanf(" %d",&user.balance);
			users[ind]=user;
			ind++;
			printf("Welcome to our bank\n");
			}
		else {
			printf("No problem, You are welcomed at any time\n");
		}
			
	}
	fclose(fopen("acc.txt", "w"));
    for(int i =0;i<ind;i++){
    fprintf(file, "%s",users[i].name);
    fprintf(file, "%s",users[i].pw);
    fprintf(file, "%d\n",users[i].balance);
    }
    fclose(file);
	END:
	return 0;
}