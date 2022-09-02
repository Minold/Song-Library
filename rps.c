#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int pscore = 0,nhscore = 0;
void checkOptions(int usr,int comp){
	// 1 = scissor 2= paper 3=rock
	if(usr == comp){
		system("clear");
		printf("|    Its a tie       |\n");
	}
	else if(usr == 1){
		if(comp == 2){
			system("clear");
			printf("|      You Won :)    |\n");
			printf("| You : Scissor      |\n");
			printf("| Computer : Paper   |\n");
			pscore++;
			
		}
		else {
			system("clear");
			printf("|     You Lose :(    |\n");
			printf("| You : Scissor      |\n");
			printf("| Computer : Rock    |\n");
			nhscore++;
		}
	}
	else if(usr == 2){
		if(comp == 1){
			system("clear");
			printf("|      You Lose :(   |\n");
			printf("| You : Paper        |\n");
			printf("| Computer : Scissor |\n");
		    nhscore++;
		}
		else {
			system("clear");
			printf("|     You Won :)     |\n");
			printf("| You : Paper        |\n");
			printf("| Computer : Rock    |\n");
			pscore++;
		}
	}
	else if(usr == 3){
		if(comp == 1){
			system("clear");
			printf("|      You Won :)    |\n");
			printf("| You : Rock        |\n");
			printf("| Computer : Scissor |\n");
			pscore++;
		}
		else {
			system("clear");
			printf("|     You Lose :(    |\n");
			printf("| You : Rock         |\n");
			printf("| Computer : Paper    |\n");
			nhscore++;
		}
	}
	else if(usr == 4){
		system("clear");
		printf(" --------------------\n");
		if(pscore > nhscore)
		printf("|      You Won :)    |\n");
		else if (pscore < nhscore)
		printf("|     You Lose :(    |\n");
		else 
		printf("|      Its a tie     |\n");
		printf("|     Final Score    |\n");
		printf("| You : %d            |\n",pscore);
		printf("| Computer: %d        |\n",nhscore);
		printf(" --------------------\n");
		printf("\a");
	}
	else {
		printf("\n Invalid Option");
	}

}
int main() {
int choice,cchoice;
srand(time(0));
system("clear");
printf("\t\t\t\tWelcome to Min's RPS GAME!");
while(choice != 4){
printf("\nChoose Your Move!: ");
printf("\n1.Scissor");
printf("\n2.Paper");
printf("\n3.Rock");
printf("\n4.Quit\n");
printf("Your Choice: ");
scanf("%d",&choice);

cchoice = (rand() % 3) + 1;
checkOptions(choice,cchoice);
}


}