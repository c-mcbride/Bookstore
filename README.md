## BookStore Documentation
Bookstore is a basic program for managing a university type bookstore. It includes features to create and record information about books/textbooks. There is also functionality to maintain an inventory list of all the books in the shop. Included is an account with the ability to update the bookstore balance as books are sold.
## Getting Started/Adding Your First Book
When you run the program in your editor, an account an inventory list will be created for you. It is recommended that you add one or more books before exploring other features of the program. To add a book
1. Run the program and select 1 to add a book.
2. From there you must enter if it is a traditional fiction/nonfiction book or a textbook
3. You will be prompted to type in a title, author, enter a price and ISBN identification number. It is very important that each title has a unique ID number. This is the most reliable way to perform search functions in the system. If a duplicate id number is entered, the existing one will be overridden by the latest book.
## Features
Once you have added one or more books, the other features can be used.
*Search for a book-You can search for a book by title or by ISBN. Note* searching by ISBN is more reliable. Search by title IS CASE SENSITIVE
*Buy a book-You can buy a book using the title or ISBN. Makes changes and updates the stores bank account and stock numbers accordingly.
*Display Inventory-Displays the linked list of the book store's Inventory
*Bookstore Stats-Uses linked list to display either the most expensive, cheapest, or average book cost
*View Account Balance-Shows the bookstores balance




## Important Function Descriptions
class InventoryList
The InventoryList is implemented using linked list. Each node in the list contains a pointer to a book object. This approach was used instead of storing book objects directly so that virtual functions and inheritance can be used. Because of this, InventoryList is a friend class to node, so that it can access the information pointed to by the book pointers in the node class.
InventoryList()
//Default constructor for list, head/tail pointers set to null

InventoryList::addBook(Node* headPointer)
//You pass in the current headpointer of the linked list and a new node is added

InventoryList::findBookTitle(string bookToFind)

InventoryList::findBookTitle(inte bookToFind)
//Overloaded definition, finds book based on the parameter

double InventoryList::findBookISBNSell(int bootToFind)
//Enter book ISBN, returns the price of the book

InventoryList::removesStock(double ISBN)
//Removes 1 book stock unit

InventoryList::printList()
//Traverses linked list pointer by pointer and outputs each books information

class Account
Mains bookstore balance and has static variable taxrate
double transaction(double price)
//Takes in a book price, adds tax and makes change based on the amount tendered. It returns change if the transaction is valid, returns -1 if not enough money is given.

class Book
Has data members title, fullName, Publication date, price, numberInStock and ISBN. Also has been implemented with all of the getters/setters.
Book()
//Default constructor prompts the user to enter all of the information

Book(string title, string fullName, int numberInStock, int ISBN, double price)
//Parameterized version of the default constructor

virtual void output()
//Virtual function used to output the correct information for either a book or textbook which is a child class of book.

class Textbook
Child class of book, however it adds private member variables course and subject

## How to Run the Program

To run the BookStore application, follow these steps:

### Prerequisites

Ensure you have the following installed:
- A C++ compiler like `g++`.
- `make` (optional, for building the project).
- `git` (to clone the repository).
- For Windows users, ensure you have WSL (Windows Subsystem for Linux) or MinGW installed and configured.

### Cloning the Repository

First, clone the repository to your local machine using git:

```bash
git clone https://github.com/yourusername/BookStore.git
```
Navigate to the cloned project's directory:
```bash
cd BookStore
```

Compile the project using the following command:
```bash
g++ -o BookStoreApp *.cpp -std=c++11
```
This command compiles all '.cpp' files in the directory and creates an executable named 'BookStoreApp'. 

###Running the Application

After building the project, run the executable using:
```bash
./BookStoreApp
```
Follow the on-screen prompts to interact with the program


