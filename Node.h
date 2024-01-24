#pragma once
#include "Book.h"

/*
* Node contains a pointer to a book object, this is done so to allow for the use of polymorphism
* Virtual function used for book and textbook rely on the ability to create both book and textbook variables 
* of type Book* 
*/
class Node
{
private:
    Book* information; //Node data consists of a pointer to a book
    Node* next;
    Node* previous;
public:
    Node();
    //Default constructor

    Node(Book& bookObjectPtr);
    //Constructs a node with it's data being a pointer to a book object

    Node* getNext();
    //Returns next node pointer

    Node* getPrevious();
    //Gets previous node pointer

    void setNext(Node* next);
    //Set next node

    void setPrevious(Node* previous);
    //set Previous node

    friend class InventoryList; 
    //Inventory list is allowed access to Book* information
};



