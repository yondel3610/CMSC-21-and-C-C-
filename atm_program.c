/*
Exer 2 but this it actually works (bcs the one i did sa lab doesn't work) like wtf man fuck sublime i can't see shit in that text editor
fucking 10 minutes just to find out wala akong semi-colon sa isang function prototype ko this is ppure bullshit istg
i mean kasalanan ko rin kasi di ako nag-aral masyado sa functions but i'm ranting so i don't fucking care even if this is a skill issue
fuck sublime
*/

#include <stdio.h>
#include <stdlib.h>

//function prototypes
void menu_screen();
void check_bal(int balance);
int withdraw(int balance);
int deposit(int balance);
int change_pin(int pin);
int pin_check(int pin);

int main(){
	int choice;
	int balance = 0; //assume centavos are not considered
	int pin = 1234; //assume pin

	while (1){
		menu_screen();
        printf("Choice: "); //user input
		scanf("%d", &choice);

        while (getchar() != '\n'); //input buffer

        if (choice == 5) {
            printf("Program terminated.");
            break; //end program when user enters 5
        }
        
        if(!pin_check(pin)){
				continue;
			}//if pin

		switch(choice){ //switch case for 1-4, no need for if != 5 condition
				case 1: //check bal
					check_bal(balance);
					break;
				case 2: //deposit 
					balance = deposit(balance); //to capture returned value from the functions
					break;
				case 3: //withdraw
					balance = withdraw(balance); //to capture returned value from the functions
					break;
				case 4: //change pin
					pin = change_pin(pin); //to capture returned value from the functions
					break;
				default: 
					printf("Invalid choice please try again.");
					break;	
			}//switch
	}//while
	return 0;
}//main

void menu_screen(){
	printf("\n*********************************\n");
	printf("Welcome to Maze Bank!\n");
	printf("*********************************\n");
	//list of functions
	printf("[1] Check Balance\n");
	printf("[2] Deposit\n");
	printf("[3] Withdraw\n");
	printf("[4] Change PIN\n");
	printf("[5] End Transaction\n");
}

void check_bal(int balance){
	printf("Current Balance: %d\n", balance); //no '&' in printf statements
}

int withdraw(int balance){
	int withdrawAmount;

    printf("Current balance: %d\n", balance); //display current bal
	printf("Withdrawal amount: ");
	scanf("%d", &withdrawAmount);
    while (getchar() != '\n'); //input buffer

    if (balance < withdrawAmount) { //check for insufficient balance
		printf("Insufficient balance!");
        return balance; //return unchanged balance
	}

	balance -= withdrawAmount; //deduct from current balance
    printf("Updated balance: %d\n", balance);
	return balance; //return updated balance
}

int deposit(int balance) {
    int amount;
    printf("Current balance: %d\n", balance); //check balance
    printf("Enter deposit amount: "); //enter deposit
    scanf("%d", &amount);

    while (getchar() != '\n'); //input buffer

    balance += amount; //update value
    printf("Updated Balance: %d\n", balance);
	return balance; //return updated balance
}

int change_pin(int pin){
	int old_pin, new_pin;
    printf("Enter your 4-digit PIN: ");
    scanf("%d", &old_pin);
    while (getchar() != '\n'); //input buffer

    if (old_pin != pin){
    	printf("Invalid PIN!");
        return pin;
    }

    printf("Enter your 4-digit PIN: ");
    scanf("%d", &old_pin);
    while (getchar() != '\n'); //input buffer 

    printf("PIN successfully changed!");
    return(new_pin);
}

int pin_check(int pin){
	int pin_input;

	printf("Please enter your 4-digit PIN: ");
	scanf("%d", &pin_input);
    while (getchar() != '\n'); //input buffer

	if(pin != pin_input){
	    printf("You entered an incorrect PIN. Please try again. \n");
    }
}