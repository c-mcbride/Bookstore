#pragma once
#include "Node.h"
#include "Book.h"
#include "TextBook.h"
#include "Account.h"

class InventoryList
{
private:
    Node* head;
    Node* tail;
    int numberOfBooks;
public:
    InventoryList();

    ~InventoryList();
    //Unimplement Destructor

    void addBook(Node* headPointer);
    //Adds a book to the linked list inventory

    void mostExpensive();
    //Searches the List of the most expensive book

    void leastExpensive();
    //Displays Least Expensive title

    void averageCost();
    //Creates an Average cost for all items in the inventory

    void printSpacers();
    //Used in formatting Output

    Node* getHeadPtr();
    //void removeBook();
    //Removes Book from the list

    void findBookTitle(string bookToFind);
    //Finds a book base on title. 

    void findBookISBN(int bookToFind); 
    //Finds a book using the ISBN

    double findBookISBNSell(int bookToFind);
    
    void removeStock(double ISBN);
    //Removes 1 item for the stock

    virtual void printList();
    //Virtual Function Prints the appropriate class output
};
