#include <stdio.h> #include <windows.h> #include <time.h>

int main() { int pin=1234,option,enteredPin,count=0,amount=1; float balance=5000; int continueTransaction=1; time_t now; time(&now); printf("\n"); printf("\t\t\t\t\t %s",ctime(&now)); printf("\n\t\t\t=======================Welcome to ATM=======================");

while(pin != enteredPin){
    printf("\nPlease enter your pin : ");
    scanf("%d",&enteredPin);
    if(enteredPin !=pin){
        Beep(610,320);
        printf("Invalid pin!!!");
    }
    count++;
    if(count==3 && enteredPin!=pin){
        return 0;
    }
}
while(continueTransaction !=0){
printf("\n\t\t\t====================*Available Transactions================");
printf("\n\n\t\t1.Withdrawal");
printf("\n\t\t2.Deposit");
printf("\n\t\t3.Check Balance");
printf("\n\n\tPlease select an option : ");
scanf("%d",&option);
switch(option){
    case 1:
    while(amount % 500 !=0){
        printf("\n\t\tEnter the amount :");
        scanf("%d",&amount);
        if(amount % 500 !=0)
        printf("\n\tThe amount must be multiples of 500");
    }
    if(balance < amount){
        printf("\n\t Sorry insufficient balance");
        amount=1;
        break;
    }
    else{
        balance -=amount;
        printf("\n\t\tYou have withdrawn Rs.%d  your new balance is Rs.%f",amount,balance);
        amount=1;
        break;
    }
    case 2:
    printf("\n\t\t Please enter the amount : ");
    scanf("%d",&amount);
    balance+=amount;
    printf("\n\t\t You have deposited Rs.%d  your new balance is Rs.%f",amount,balance);
    amount=1;
    break;
    
    case 3:
    printf("\n\t\t Your balance is Rs.%f",balance);
    break;
    
    default:
    beep(610,320);
    printf("\n\t\t Invalid option!!");
}
printf("\n\n\t\t Do you wish to perform another Transaction? press 1[yes],0[no]");
scanf("%d",&continueTransaction);
}
printf("\n\t\t        Thank you for banking");
return 0;
           }
