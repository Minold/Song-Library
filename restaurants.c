#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//function to estimate the final cost of the expense at a restaurant
void fBH(char rname[50]){
    printf("\n\n==============Min Estimates For You=============\n");
    printf("Name of the Restaurant:  %s",rname);
    printf("\n");
    printf("Itmes:\t\t");
    printf("Quantity:\t\t");
    printf("Price:\t\t");
    printf("\n================================================\n");
}
void fBB(char iname[50], int iqt, float iprice){
    printf("%s\t\t",iname);
    printf("%d\t\t\t",iqt);
    printf("%.1f\t\t",iqt * iprice);
    printf("\n");
}
void fBFNJ(float finalp){
    float tip = 0.15 * finalp;
    float tax = 0.0625 * finalp;
    float ffinalp = finalp + tip + tax;
    printf("================================================\n");
    printf("Itme(s) total:\t%0.1f",finalp);
    printf("\nTip:\t\t%0.1f",tip);
    printf("\nTax:\t\t%0.1f",tax);
    printf("\n================================================\n");
    printf("Your Grand Total is:\t\t%0.1f\n",ffinalp);
    }
void fBFNY(float finalp){
    float tip = 0.18 * finalp;
    float tax = 0.08875 * finalp;
    float ffinalp = finalp + tip + tax;
    printf("================================================\n");
    printf("Itmes total:\t%0.1f",finalp);
    printf("\nTip:\t\t%0.1f",tip);
    printf("\nTax:\t\t%0.1f",tax);
    printf("\n================================================\n");
    printf("Your Grand Total is:\t\t%0.1f\n",ffinalp);
    }
void fBFCA(float finalp){
    float tip = 0.15 * finalp;
    float tax = 0.0725 * finalp;
    float ffinalp = finalp + tip + tax;
    printf("================================================\n");
    printf("Itmes total:\t%0.1f",finalp);
    printf("\nTip:\t\t%0.1f",tip);
    printf("\nTax:\t\t%0.1f",tax);
    printf("\n================================================\n");
    printf("Your Grand Total is:\t\t%0.1f",ffinalp);
    printf("\n");
    }
struct res{
    float iprice;
    int iqt;
    char iname[50];
};
struct orde{
    int itemn;
    char rname[50];
    struct res inam[50];
};
int main(){
    float finalp;
    int lnumber;
    int cchoice;
    printf("\n================================================================");
    printf("\nWelcome to Expense Estimator 'Min Estimates For You'!\n================================================================\n\nPlease choose your preferred operation.\n");
   do{
    //main menu
    printf("\n1. Select location.\n2. About 'Min Estimates' \n3. Exit\n");
    printf("Perferred operation: ");
    scanf("%d", &cchoice);
    if (cchoice == 1){
        printf("\nWelcome! You can now select your location!\n");
        break;
    }
    else if(cchoice == 2){
        printf("\n'Min Estimates' calculates your spending in a restaurant including tips and taxes! Our system is available on three different states across the United States.\nYou will now return to the main menu! Have a great time!\n");
        continue;
    }
    else if(cchoice ==3 ){
        printf("\nByebye and we hope to see you again!\n\n");
        exit(0);
    }
   }
   while(1);
   do{
    //location pick
    printf("\n1.New Jersey 2.New York 3.California\n");
    printf("\nPlease enter 1,2 or 3 depending on your location!: ");
    scanf("%d", &lnumber);

    switch(lnumber){
        case 1:
            printf("\nYou have selected New Jersey!\n");
            break;
        case 2:
            printf("\nYou have selected New York!\n");
            break;
        case 3:
            printf("\nYou have selected California!\n");
            break;
        default:
            printf("\nInput invalid! Returning to beginning...\n");
            continue;
    }
    break;
   }
   while(1);
   int njselection, n;
   //if new jersey,
    struct orde min;
    fgetc(stdin);
    if (lnumber == 1){
        printf("\nYou have selected New Jersey!\nIn New Jersey, the tax for food is 6.625 percent!\nTip is set at minimum of 15 percent.\nPlease enter the name of the restaurant!\n");
        printf("Name of the Restaurant:  ");
        fgets(min.rname,50,stdin);
        min.rname[strlen(min.rname)-1]=0;
        printf("Welcome to %s!", min.rname);
        printf("\nHow many items will you be ordering?: ");
        scanf("%d", &n);
        min.itemn = n;
        for (int i = 0; i < n; i++){
            fgetc(stdin);
            printf("\nName of item %d: ",i+1);
            fgets(min.inam[i].iname,50,stdin);
            min.inam[i].iname[strlen(min.inam[i].iname)-1]=0;
            printf("\nHow many %s would you like?: ",min.inam[i].iname);
            scanf("%d", &min.inam[i].iqt);
            printf("\nPlease enter the unit price of your item!: ");
            scanf("%f", &min.inam[i].iprice);
            finalp += min.inam[i].iqt * min.inam[i].iprice;
        }
        fBH(min.rname);
        for(int i =0; i< min.itemn; i++){
            fBB(min.inam[i].iname, min.inam[i].iqt,min.inam[i].iprice);
        }
        fBFNJ(finalp);
    }
      if (lnumber == 2){
        printf("\nYou have selected New York!\nIn New York, the tax for food is 8.875 percent!\nTip is set at minimum of 18 percent.\nPlease enter the name of the restaurant!\n");
        printf("Name of the Restaurant:  ");
        fgets(min.rname,50,stdin);
        min.rname[strlen(min.rname)-1]=0;
        printf("Welcome to %s!", min.rname);
        printf("\nHow many items will you be ordering?: ");
        scanf("%d", &n);
        min.itemn = n;
        for (int i = 0; i < n; i++){
            fgetc(stdin);
            printf("\nName of item %d: ",i+1);
            fgets(min.inam[i].iname,50,stdin);
            min.inam[i].iname[strlen(min.inam[i].iname)-1]=0;
            printf("\nHow many %s would you like?: ",min.inam[i].iname);
            scanf("%d", &min.inam[i].iqt);
            printf("\nPlease enter the unit price of your item!: ");
            scanf("%f", &min.inam[i].iprice);
            finalp += min.inam[i].iqt * min.inam[i].iprice;
        }
        fBH(min.rname);
        for(int i =0; i< min.itemn; i++){
            fBB(min.inam[i].iname, min.inam[i].iqt,min.inam[i].iprice);
        }
        fBFNY(finalp);
    }
    if (lnumber == 3){
        printf("\nYou have selected California!\nIn California, the tax for food is 7.25 percent!\nTip is set at minimum of 15 percent.\nPlease enter the name of the restaurant!\n");
        printf("Name of the Restaurant:  ");
        fgets(min.rname,50,stdin);
        min.rname[strlen(min.rname)-1]=0;
        printf("Welcome to %s!", min.rname);
        printf("\nHow many items will you be ordering?: ");
        scanf("%d", &n);
        min.itemn = n;
        for (int i = 0; i < n; i++){
            fgetc(stdin);
            printf("\nName of item %d: ",i+1);
            fgets(min.inam[i].iname,50,stdin);
            min.inam[i].iname[strlen(min.inam[i].iname)-1]=0;
            printf("\nHow many %s would you like?: ",min.inam[i].iname);
            scanf("%d", &min.inam[i].iqt);
            printf("\nPlease enter the unit price of your item!: ");
            scanf("%f", &min.inam[i].iprice);
            finalp += min.inam[i].iqt * min.inam[i].iprice;
        }
        fBH(min.rname);
        for(int i =0; i< min.itemn; i++){
            fBB(min.inam[i].iname, min.inam[i].iqt,min.inam[i].iprice);
        }
        fBFCA(finalp);
    }
    
    return 0;
}
