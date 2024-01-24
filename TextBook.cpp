#include "TextBook.h"

TextBook::TextBook(string title, string fullName, int numberInStock, int ISBN, string subject, string course, double price) : Book(title, fullName, numberInStock, ISBN, price)
{
	this->subject = subject; 
	this->course = course;
}

void TextBook::output()
{
	Book::output();
	cout << "Subject: " << subject << endl;
	cout << "Course: " << course << endl;
}

TextBook::~TextBook() {};


