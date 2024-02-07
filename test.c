// This is the Code used to make Bhavya International Bank with features like Opening Account , Transfering Funds , View Balance , View Account info and close Account

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>


char name[100][100];
char fatherName[100][100];
int age[100];
int count = 0;
int size = 100;
int array[100];
float Balance[100];
int search;
int key = 2004;



void openaccount();
void accountbalance();
void closeaccount();
void bankdetails();
void viewaccounts();
void addmoney();
void withdrawmoney();
void transfermoney();
void accountinfo();

int main() {
    int options;

    while(1) {
        printf("\n Welcome to Bhavya International Bank\n");
        printf("----------------------------------------\n");
        printf("Select the Desired Options from the Menu \n \n");
        printf("Press the Desired Number  \n");
        printf("1) Open New Account:\n");
        printf("2) View Account Balance:\n");
        printf("3) Add Money to your Account:\n");
        printf("4) To Withdraw money from your Account:\n");
        printf("5) To Transfer Money to another Bank Account:\n");
        printf("6) Close your Bank Account:\n");
        printf("7) View all accounts:\n");
        printf("8) Get Bank Details:\n");
        printf("9) To view your account information\n");

        scanf("%d", &options);

switch(options) {
        
    case 1:
        count++;
        openaccount();
        break;

    case 2:
        accountbalance();
        break;

    case 3:
        addmoney();
        break;

    case 4:
        withdrawmoney();
        break;

    case 5:
        transfermoney();
        break;

    case 6:
        closeaccount();
        break;

    case 7:
        viewaccounts();
        break;

    case 8:
        bankdetails();
        break;
    
    case 9 :
    accountinfo();
    break;

    default:
        printf("Invalid option. Please choose a valid option.\n");
        break;
         }

     }
    return 0;
}


void openaccount() {
    printf("Enter First Name\n");
    scanf("%s", name[count]);

    printf("Enter Father's Name\n");
    scanf("%s", fatherName[count]);

    printf("Enter Your Age: ");
    scanf("%d", &age[count]);

    srand(time(NULL));
    array[count] = rand() % (99999 - 10000 + 1) + 10000;

    printf("\n Account Successfully Opened with Account Number : %d\n", array[count]);
    Balance[count] = 0.00;

    printf("Current Account Balance - 0.00\n");
}

void closeaccount() {
    printf("Enter your 5 digit Account Number: ");
    int close;
    int index = -1;
    scanf("%d",&close);
    char confirm;
    printf("Are You Sure You want to Proceed , Enter Y/N");
    scanf(" %c",&confirm);
    if (confirm =='Y'){

    for(int i=1;i<=count;i++){
        if(array[i]==close){
             index = i;
             break;
             
        }
    }
    
    for(int i = index ; i<= count-1;i++){

        strcpy(name[i], name[i + 1]);
        strcpy(fatherName[i], fatherName[i + 1]);
        age[i] = age[i + 1];
        array[i]=array[i+1];
        Balance[i]= Balance[i+1];  
}
        printf("Account Number  '%d' closed Successfully \n",close);
        count --;

}
    else { 
        return;
    }

}


void accountbalance() {
   
    printf("To View Account Balance, Enter Your 5 digit Account Number: ");
    scanf("%d", &search);
    for (int i = 1; i <= count; i++) {
        if (array[i] == search) {
            printf("Balance for account %d is %.2f\n", search, Balance[i]);
            return; 
        }
    }
    printf("\nSorry Account not found!!!\n");
}



void bankdetails() {
    printf("Branch - Kp-16 Hostel\n");
    printf("IFSC Code - BIB000003\n");
    printf("For More Details Contact us at Hello@BIB.com\n");
}

void viewaccounts() {

    printf("Enter the 4 Digit Authentication key to Proceed - ");
    int password;
    scanf("%d",&password);

    if(key == password){

         float sum = 0;
         for(int i=1;i<=count;i++){
            sum = sum + Balance[i];
         }
         printf("Total Amount in BIB is - %.2f\n",sum);
         printf("Total Account's in BIB are - %d\n", count);

        for (int i = 1; i <= count; i++) {
        printf("> %d\n", array[i]);

    }
        
}
else {
    printf("Access Denied , Please Try Again !!");

    }
}

void addmoney(){
    printf("To Add money to your account , Please enter the 5 digit Account Number - ");
    int accnumber;
    int index = -1;
    scanf("%d",&accnumber);


    
    for(int i=1;i<=count;i++){
        if(accnumber==array[i]){
             index = i;
            break;  
        }
       

    }

    if(index!=-1){

    printf("Enter the Amount you want to Deposit in your Account Number - %d : ",accnumber);
    float addmoney;
    scanf("%f",&addmoney);
    
    if(addmoney>0.00){

    Balance[index]= addmoney;
    printf("\nAmount '%.2f.' Sucessfully Added to your Bank Account with Account Number - %d \n ",addmoney,accnumber);
    }
    
    else{
        printf("Please Enter Valid Amount");
    }

}

    if(index==-1){
        printf("\nAccount not found!!! , Please Enter the Correct Account Number\n");
    }

    
}
void withdrawmoney(){
    printf("To withdraw money from your account , Please enter the 5 digit Account Number - ");
    int accnumber;
    int index = -1;
    scanf("%d",&accnumber);


    
    for(int i=1;i<=count;i++){
        if(accnumber==array[i]){
             index = i;
             break;
            
        }
    }

    if(index!=-1){

    printf("Enter the Amount you want to withdraw from your Account Number - %d : ",accnumber);
    int withdrawmoney;
    scanf("%d",&withdrawmoney);
    
    int x = Balance[index];
    if(withdrawmoney>x){
        printf("Insufficient Balance");
        return;
    }
    Balance[index]= x-withdrawmoney;
   
    printf("\nAmount '%d' Sucessfully withdrawn from your Bank Account with Account Number - %d \n ",withdrawmoney,accnumber);
    }



    if(index==-1){
        printf("\nAccount not found!!! , Please Enter the Correct Account Number\n");
    }  
}

void transfermoney(){
    int fromacc;
    int toacc;
    int index1 = -1;
    int index2 = -1;

    printf("To Transfer Funds , Please Enter Your 5 digit Account Number : ");
    scanf("%d",&fromacc);


    for(int i =1 ; i<=count;i++){
        if(array[i]==fromacc){
            index1 = i;
        }
        
    }
    
    
    if(index1!=-1){

    printf("Enter the Account Number you want to Transfer to : ");
    scanf("%d",&toacc);

    
    if(fromacc==toacc){
        printf("You cannot Transfer funds to your Account , Please Enter the Correct Account Number");
    }

    else {

     for(int i =1;i<=count;i++){
        if(array[i]==toacc){
            index2 = i;
        }
        
    }

    if(index2!=-1){
   
    
    
    printf("Enter the Amount you want to Transfer from your Bank Accout : ");
    int amount;
    scanf("%d",&amount);

    if(Balance[index1]<amount){
        printf("Insufficient Balance");
        return;
    }
    
    Balance[index1] = Balance[index1]-amount;
    Balance[index2] = Balance[index2] + amount;
    printf("\nAmount %d Succesfully credited to Account Number : %d",amount,toacc);
    }



    else{
        printf("\nSorry Account Number Not found!!! , Please Check the Account Number Mentioned\n");

    }
}

    } 
    else{
        printf("\nSorry Account Number Not found!!! , Please Check the Account Number Mentioned\n");
    }
    
}
void accountinfo(){
    printf("Enter the 5 digit Account Number to view your Details - ");
    int accountnumber;
    int index = -1;
    int i =1;
    scanf("%d",&accountnumber);

    for( i=1;i<=count;i++){
        if(array[i]==accountnumber){
            index = i;

        printf("\nThe Balance for your account Number %d is : %.2f \n",accountnumber,Balance[i]);
        printf("Account Holder Name - %s\n", name[index]);
        printf("Father's Name - %s\n", fatherName[index]);
        printf("Account Holder Age - %d\n" , age[index]);

        break;
        }
    }
    if(index==-1){
        printf("Account Not  Found! Please Enter a Valid Account Number");
    }
}















