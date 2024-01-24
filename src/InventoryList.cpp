#include "InventoryList.h"
#include <string>

using namespace std;

/*Class to handle and display the book store's inventory*/
InventoryList::InventoryList()
{
    //Create head and tail pointer
    this->head = nullptr;
    this->tail = nullptr;
    numberOfBooks = 0;
}

/*
* Invetory list is the main function for adding books to the linked list. It takes a head pointer a parameter
* If the head pointer is a nullptr, the linked list is established
* Otherwise, the book is added to the front of the list
* It is important to note, objects can't be stored directly in this linked list because Book and Textbook 
* are different sizes.
*/
void InventoryList::addBook(Node* headPointer)
{
    int bookType;
    cout << "1-Enter Fiction or Non-Fiction Book" << endl;
    cout << "2-Enter Textbook" << endl;
    cin >> bookType;

    if (bookType == 1)
    {
        string title, fullName;
        double price;
        int numberInStock, ISBN;
        cout << "Enter book title: ";
        cin.ignore(); //clear the input stream from \n
        getline(cin, title);

        cout << "Enter the author in the format (last name, first name): ";
        getline(cin, fullName);

        cout << "How many are in stock? "; cin >> numberInStock;
        cout << "What is the ISBN for " << title << "?: "; cin >> ISBN;
        cout << "Price: "; cin >> price;

        Book* newBook = new Book(title, fullName, numberInStock, ISBN, price);

        //Create new node and put in data
        Node* bookNode = new Node(*newBook);

        //bookNode->setNext(headPointer);
        bookNode->setPrevious(nullptr);

        //Set the previous head pointer so that it points to the new node in the back
        if (headPointer == nullptr)
        {
            head = bookNode;
        }
        else
        {
            bookNode->setNext(headPointer);
            headPointer->setPrevious(bookNode);
            head = bookNode;
        }

        numberOfBooks++;
    }
    else if (bookType == 2)
    {
        string title, fullName, subject, course;
        int numberInStock, ISBN;
        double price;

        cout << "Enter book title: ";
        cin.ignore(); //clear the input stream from \n
        getline(cin, title);

        cout << "Enter the author in the format (last name, first name): ";
        getline(cin, fullName);

        cout << "How many are in stock? "; cin >> numberInStock;
        cout << "What is the ISBN for " << title << "?: "; cin >> ISBN;
        cout << "What subject? ";
        cin.ignore();
        getline(cin, subject);

        cout << "Course: ";
        getline(cin, course);

        cout << "Price: ";
        cin >> price;

        Book* newBook = new TextBook(title, fullName, numberInStock, ISBN, subject, course, price);

        //Create new node and put in data
        Node* bookNode = new Node(*newBook);

        //bookNode->setNext(headPointer);
        bookNode->setPrevious(nullptr);

        //Set the previous head pointer so that it points to the new node in the back
        if (headPointer == nullptr)
        {
            head = bookNode;
        }
        else
        {
            bookNode->setNext(headPointer);
            headPointer->setPrevious(bookNode);
            head = bookNode;
        }

        numberOfBooks++;
    }
}

//Finds a book based on a parameter and determines if the book is instock
void InventoryList::findBookTitle(string bookToFind)
{
    Node* current = head;
    bool isFound = false; 

    if (head == nullptr)
    {
        cout << "There are no books in the list. This operation is impossible...Add some books first.";
    }
    else
    {
        while (current != nullptr)
        {
            if (current->information->getTitle() == bookToFind)
            {
                cout << "We have " << bookToFind << endl;
                cout << "There are " << current->information->getNumberInStock() << "in stock. " << endl;
                isFound = true; 
                break; 
            }
            current = current->getNext();
        }
    }

    if (!isFound)
    {
        cout << "Sorry, it looks like we do not have the book: " << endl;
    }
}

//Uses the ISBN of a book to determine if the book is instock. Displays the title and the number in stock
void InventoryList::findBookISBN(int bookToFind)
{
    Node* current = head;
    bool isFound = false;

    if (head == nullptr)
    {
        cout << "There are no books in the list. This operation is impossible...Add some books first.";
    }
    else
    {
        while (current != nullptr)
        {
            if (current->information->getISBN() == bookToFind)
            {
                cout << "We have " << current->information->getTitle() << endl;
                cout << "There are " << current->information->getNumberInStock() << "in stock. " << endl;
                isFound = true;
                break;
            }
            current = current->getNext();
        }
    }

    if (!isFound)
    {
        cout << "Sorry, it looks like we do not have the book: " << endl;
    }
}

//Used to buy a book.If the book is instock it the funtion returns the price. If it isnt -1 is returned
double InventoryList::findBookISBNSell (int bookToFind)
{
    Node* current = head;
    bool isFound = false;

    if (head == nullptr)
    {
        cout << "There are no books in the list. This operation is impossible...Add some books first.";
    }
    else
    {
        while (current != nullptr)
        {
            if (current->information->getISBN() == bookToFind)
            {
                isFound = true;
                return current->information->getPrice(); 
                break;
            }
            current = current->getNext();
        }
    }

    if (!isFound)
    {
        //cout << "Sorry, it looks like we do not have the book: " << endl;
        return -1; 
    }
}

//Removes 1 book from stock after a sale
void InventoryList::removeStock(double ISBN)
{
    Node* current = head;

    while (current != nullptr)
    {
        if (current->information->getISBN() == ISBN)
        {
            current->information-> subtractStock(1);
            break;
        }
        current = current->getNext();
    }
}

//Getter for head pointer 
Node* InventoryList::getHeadPtr()
{
    return head;
}

/*
* Traverses the linked list and uses the gladiator strategy to find the most expensive book
*/

void InventoryList::mostExpensive()
{
    Node* current = head;
    if (head == nullptr)
    {
        cout << "There are no books in the list. This operation is impossible...Add some books first.";
    }
    else
    {
        double maxValue = current->information->getPrice();
        string maxTitle = current->information->getTitle();

        while (current != nullptr)
        {
            if (current->information->getPrice() > maxValue)
            {
                maxValue = current->information->getPrice();
                maxTitle = current->information->getTitle();
            }
            current = current->getNext();
        }
        printSpacers();
        cout << "The most expensive book is: " << maxTitle << endl;
        cout << "It costs: " << maxValue << endl;
        printSpacers();
    }
}

/*
* Traverses the linked listand finds the least expensive book.Uses the logic of the gladiator strategy 
* in reverse.
*/
void InventoryList::leastExpensive()
{
    Node* current = head;
    if (head == nullptr)
    {
        cout << "There are no books in the list. This operation is impossible";
    }
    else
    {
        double minValue = current->information->getPrice();
        string minTitle = current->information->getTitle();

        while (current != nullptr)
        {
            if (current->information->getPrice() < minValue)
            {
                minValue = current->information->getPrice();
                minTitle = current->information->getTitle();
            }
            current = current->getNext();
        }
        printSpacers();
        cout << "The cheapest book is: " << minTitle << endl;
        cout << "It costs: " << minValue << endl;
        printSpacers();
    }
}

void InventoryList::averageCost()
{
    Node* current = head;
    if (head == nullptr)
    {
        cout << "There are no books in the list. This operation is impossible";
    }
    else
    {
        double averageCost = 0;

        while (current != nullptr)
        {
            averageCost += current->information->getPrice();
            current = current->getNext();
        }

        averageCost = averageCost / (double)numberOfBooks;

        printSpacers();
        cout << "The average cost for a book is: " << averageCost << endl;
        printSpacers();
    }
}

void InventoryList::printList()
{
    printSpacers();
    Node* current = head;
    while (current != nullptr)
    {
        current->information->output();
        current = current->getNext();
        printSpacers();
    }
}


void InventoryList::printSpacers()
{
    cout << "------------------------------------------" << endl;
    cout << "------------------------------------------" << endl;
}
InventoryList::~InventoryList() {};



