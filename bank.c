#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct info {
	char phone[50];
	char ac[50];
	char password[50];
	float balance;
};

int main(){
	struct info info,inf;
	char ufile[50],phone[50],password[50];
	FILE *fp,*fptr;
	int opt,choice;
	int amount;
	char cont = 'y';
	printf("\nWelcome to Min's Online Banking System! Please select your preferred operation!");
	beginning:
	printf("\n\n1.Register an account");
	printf("\n2.Login to an account");

	printf("\n\nPlease enter your choice:\t");
	scanf("%d",&opt);
	if(opt == 1){
		system("clear");
		printf("\nEnter your name:\t");
		scanf("%s",info.ac);
		printf("Enter your phone number:\t");
		scanf("%s",info.phone);
		printf("Enter your new password:\t");
		scanf("%s",info.password);
		info.balance=0;
		stpcpy(ufile,info.phone);
		fp=fopen(strcat(ufile,".dat"),"w");
		fwrite(&info,sizeof(info),1,fp);
		if(&fwrite != 0){
			printf("Account is registered successfully! \nWe will return you back to the main page.");
			goto beginning;
		}
	}
	else if(opt == 2){
		system("clear");
		printf("\nPlease enter your Phone Number:\t");
		scanf("%s",phone);
		printf("Please enter your Password:\t");
		scanf("%s",password);
		fp = fopen(strcat(phone,".dat"),"r");
		if(fp == NULL){ 
			printf("Account number not registered");
			printf("We will return you back to the main page.\nPlease try again.");
			goto beginning;
		}
		else {
			fread(&info,sizeof(struct info),1,fp);
			fclose(fp);
			if(!strcmp(password,info.password)){
				while(cont == 'y'){
				system("clear");
				printf("\n\tWelcome %s",info.ac);
				printf("\n1. Balance inquiry");
				printf("\n2. Deposit");
				printf("\n3. Withdraw");
				printf("\n4. Online Trasnfer");
				printf("\n5. Change Password");
				printf("\n6. Exit Program\n\n");
				printf("Option:\t");
				scanf("%d",&choice);
				switch (choice){
					case 1:
						printf("Your current balance is $%.2f.",info.balance);
						break;

					case 2:
						system("clear");
						printf("Enter amount to be added($):\t");
						scanf("%d",&amount);
						info.balance += amount;
						fp = fopen(phone,"w");
						fwrite(&info,sizeof(struct info),1,fp);
						if(&fwrite !=0) printf("\n\nYou have depostied $%d.",amount);
						fclose(fp);
						break;

					case 3:
						system("clear");
						printf("Enter withdrawl amount:\t");
						scanf("%d",&amount);
						if(amount>info.balance) printf("\nSorry insufficeint balance");
						else {
							info.balance -= amount;
						fp = fopen(phone,"w");
						fwrite(&info,sizeof(struct info),1,fp);
						if(&fwrite !=0) printf("\n\nYou have withdrawn $%d",amount);
						fclose(fp);
						}
						break;
					
					case 4:
						printf("Please enter the phone number to trasnfer balance:\t");
						scanf("%s",phone);
						printf("Enter the amount to transfer:\t");
						scanf("%d",&amount);
						if(amount > info.balance) printf("\nSorry insufficent balance");
						else {
							fptr = fopen(strcat(phone,".dat"),"r");
							if(fptr==NULL) printf("Sorry number is not registered");
							else {
								fread(&inf,sizeof(struct info),1,fptr);
								fclose(fptr);
								inf.balance += amount;
								fptr = fopen(phone,"w");
								fwrite(&inf,sizeof(struct info),1,fptr);
								if(&fwrite != 0){
									printf("Your trasfer is completed. You have trasnfered $%d to %s",amount,inf.phone);
									fclose(fptr);
									info.balance -= amount;
									strcpy(ufile,info.phone);
									fp = fopen(strcat(ufile,".dat"),"w");
									fwrite(&info,sizeof(struct info),1,fp);
									fclose(fp);
								}
							}
						}
						break;
					case 5:
						printf("\n\nPlease enter your old password:\t");
						scanf("%s",password);
						if(!strcmp(password,info.password)){
							printf("\n\nPlease enter your new password:\t");
							scanf("%s",password);
							strcpy(info.password,password);
							strcpy(ufile,info.phone);
							fp = fopen(strcat(ufile,".dat"),"w");
							fwrite(&info,sizeof(struct info),1,fp);
							fclose(fp);	
							printf("\nPassword succesfullly changed");
						}else printf("\nSorry your password is wrong");
					case 6: 
						break;
					default:
					break;
				}
				printf("\n\nDo you want to continue?[y/n]:\t");
				scanf("%s",&cont);
				}
			}
			else {
				printf("Invalid password");
			}	
		}
		printf("\n\nThank you for your time with Min's Online Banking System!!\n\n");
	}
	
	return 0;
}