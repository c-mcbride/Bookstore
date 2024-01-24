#include "Book.h"
#include <iostream>
#include <string>

using namespace std;

/*Base class book: Class stores basic information common to all books.*/

/*Default constructor builds a book object prompt by prompt*/
Book::Book() 
{
	cout << "Enter book title: ";
	cin.ignore(); //clear the input stream from \n
	getline(cin, title);

	cout << "Enter the author in the format (last name, first name): ";
	getline(cin, fullName);

	cout << "How many are in stock? "; cin >> numberInStock;
	cout << "What is the ISBN for " << title << "?: "; cin >> ISBN;
	cout << "Price: "; cin >> price;
	publicationDate = new Date(); 
}

Book::Book(string title, string fullName, int numberInStock, int ISBN, double price)
{
	this->title = title;
	this->fullName = fullName; 
	this->numberInStock = numberInStock;
	this->ISBN = ISBN;
	this->price = price; 
	inStock = true;
	publicationDate = new Date();
}
	
/*Getters and Setters Boiler Plate to access member variables*/
string Book::getTitle()
{
	return title; 
}

string Book::getAuthor()
{
	return fullName; 
}

int Book::getNumberInStock()
{
	return numberInStock;
}

int Book::getISBN()
{
	return ISBN; 
}

double Book::getPrice()
{
	return price; 
}

void Book::setTitle(string title)
{
	this->title = title; 
}

void Book::setAuthor(string name)
{
	this->fullName = name; 
}

void Book::setISBN(int ISBN)
{
	this->ISBN = ISBN;
}
					
bool Book::isInStock()
{
	return inStock;
}

void Book::addStock(int stockAmount)
{
	numberInStock = numberInStock + stockAmount;
}

//Pass stock amount by reference
void Book::subtractStock(int stockAmount)
{
	numberInStock = numberInStock - stockAmount; 
}
	
void Book::output()
{
	cout << "Book Title: " << title << endl;
	cout << "Author: " << fullName << endl;
	cout << "Number in Stock: " << numberInStock << endl;
	cout << "ISBN: " << ISBN << endl;
	cout << "Price: " << price << endl;
	publicationDate->output(); 
	cout << endl;
}

Book::~Book() {}; //Unimplemented Distructor 

	
