#pragma once

/*
* This class handles the stores funds. Contains balance and static variable taxRate
* Contains function for buying a book, adding funds and getting the balance
*/
class Account
{
private: 
	double balance;
	static double taxRate; //TN tax rate 7%
public:
	Account();
	//Default Constructor

	Account(double balance);
	//Start with a specific balance

	double getBalance();
	//getter for balance

	void addFunds(double funds);
	//Update balance after transaction

	double transaction(double price); 
	//Performs transaction: returns change and updates balance and stock value 

	void output();

	~Account(); 
};

