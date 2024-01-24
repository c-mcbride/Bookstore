#pragma once
#include <iostream>
#include "Date.h"

using namespace std; 

/*Main book class, used as the base class for textbook. */

class Book
{
private:
	string title;
	string fullName;
	Date* publicationDate;
	double price; 
	bool inStock = false;
	int numberInStock = 0;
	int ISBN;
public:
	Book();
	//Default constructor, prompts user for data 

	Book(string title, string fullName, int numberInStock, int ISBN, double price);
	//Parameterized constructor 

	string getTitle();
	//Getter for title

	string getAuthor();
	//Getter for author

	int getISBN(); 
	//Getter for ISBN 

	int getNumberInStock();
	//Getter for number in stock

	double getPrice(); 
	//Getter for book price

	void setTitle(string title);
	//Setter for title

	void setAuthor(string name);
	//Setter for author

	void setISBN(int ISBN);
	//Setter for ISBN

	bool isInStock();
	//Returns true of the book is instock

	void addStock(int stockAmount);
	//Adds stock based on the argument

	void subtractStock(int stockAmount);
	//Removes specified amount

    virtual void output();
	//Outputs information based on the class that is used

	~Book();
};

