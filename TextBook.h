#pragma once
#include "Book.h"

/*
*  Textbook is a child class of book with added functionality, it also includes subject course and price
*  It also utilizes book's virtual function output to output the basic information plus the textbook specific info
*/

class TextBook :
    public Book
{
private:
    string subject; 
    string course; 
    double price;
public: 
    TextBook(string title, string fullName, int numberInStock, int ISBN, string subject, string course, double price);
    ~TextBook();
    void output(); 
};

