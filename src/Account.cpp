#include "Account.h"
#include <iostream>

using namespace std;

double Account::taxRate = 0.07; //TN tax rate

//Default constructor
Account::Account()
{
	this->balance = 0;
}

//Parameterized constructor with starting balance as an argument
Account::Account(double balance)
{
	this->balance = balance; 
}

//Getter for balance
double Account::getBalance()
{
	return balance;
}

//Add funds to the account
void Account::addFunds(double funds)
{
	balance = balance + funds; 
}

/*
* Function for conducting a transaction. After the price is returned from inventory list
* It is passed in as an argument. Uses the tax rate to determine the final sale value.
* Also, it makes change based on the amount tendered. If enough money is not tendered, the 
* function returns -1
*/
double Account::transaction(double price)
{
	cout << "Price before tax: " << price << endl;
	double tax = price * taxRate; 
	double totalPrice = price + tax; 

	cout << "Total price: " << totalPrice << endl;
	double amountTendered;
	cout << "Enter the amount tendered: " << endl;
	cin >> amountTendered;

	if (amountTendered >= totalPrice)
	{
		double change = amountTendered - totalPrice; 
		return change;
	}
	else
	{
		return -1; 
	}
}

Account::~Account() {}; //Unimplemented Destructor

void Account::output()
{
	cout << "Balance: " << balance << endl;
}
