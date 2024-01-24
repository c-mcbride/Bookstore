// Califf McBride YYG532
// CPSC 5010 Final Project: Bookstore

#include <iostream>
#include "Book.h"
#include "InventoryList.h"
#include "Account.h"

/*Main user interface for book store. Uses switch statements to pick between 6 options*/
int main()
{
    bool exit = false;
    bool statsExit = false;
    InventoryList newList;
    Account newAccount; 

    while (!exit)
    {
        cout << "Please select the desired option: " << endl;
        cout << "1 - Add a book " << endl; 
        cout << "2 - Search for a Book " << endl;
        cout << "3 - Buy a Book " << endl;
        cout << "4 - Display Inventory" << endl;
        cout << "5 - Bookstore Stats" << endl;
        cout << "6 - View Store Bank Account Balance" << endl;
        cout << "0 - Exit" << endl;

        int choice; //What do they pick?
        cin >> choice; 

        switch (choice)
        {
            //Adds a book to the linked list at the head
            case 1:
            {
                cout << "Add a book " << endl;
                newList.addBook(newList.getHeadPtr());
                break;
            }
            //Searches the linked list to see if the entered book is contained within
            case 2:
            {
                cout << "1- Search by title " << endl;
                cout << "2- Search by ISBN " << endl;
                bool validChoice = false; 
                int searchChoice;

                while (!validChoice)
                {
                    cin >> searchChoice;

                    if (searchChoice == 1 || searchChoice == 2)
                    {
                        validChoice = true;
                        break;
                    }

                    else
                    {
                        cout << "Invalid Choice....try again";
                    }
                }
                
                if (searchChoice == 1)
                {
                    cout << "Enter the title of the book you would like to search: " << endl;
                    string bookToSearch;
                    cin >> bookToSearch;
                    newList.findBookTitle(bookToSearch);
                    break;
                }
                else if (searchChoice == 2)
                {
                    cout << "Enter the ISBN of the book you would like to find: " << endl;
                    int bookToSearch;
                    cin >> bookToSearch;
                    newList.findBookISBN(bookToSearch);
                    break;
                }
            }
            //Buy a book
            case 3: 
            {
                int bookToFind;
                cout << "Enter the ISBN of the book: " << endl;
                cin >> bookToFind;

                //Get the price of the book
                double bookPrice = newList.findBookISBNSell(bookToFind);

                if (bookPrice == -1)
                {
                    cout << "Sorry we don't have any of that book" << endl;
                    break; 
                }
                else
                {
                    double change = newAccount.transaction(bookPrice); //Account class handles transaction

                    if (change == -1)
                    {
                        cout << "That is not enough money....." << endl;
                        break; 
                    }
                    else
                    {
                        cout << "Change: " << change << endl;
                        newList.removeStock(bookToFind); //Removes 1 Book
                        newAccount.addFunds(bookPrice); //Add money to the bank account
                        break;
                    }
                }
            }
            //Prints each node in the linked list to display inventory
            case 4:
            {
                newList.printList();
                break;
            }
            //Different stats can be viewed, mainly most expensive, cheapest and average book cost for the store
            case 5:
            {
                while (!statsExit)
                {
                    cout << "What stat would you like to see? " << endl;
                    cout << "1-Most Expensive Book: " << endl;
                    cout << "2-Cheapest Book: " << endl;
                    cout << "3-Average Cost: " << endl; 
                    cout << "0-Exit"; 
                    int statsChoice;
                    cin >> statsChoice;

                    switch (statsChoice)
                    {
                        case 1:
                        {
                            newList.mostExpensive();
                            break; 
                        }

                        case 2:
                        {
                            newList.leastExpensive();
                            break; 
                        }

                        case 3:
                        {
                            newList.averageCost();
                            break; 
                        }
                        case 0:
                        {
                            cout << "Exiting to main menu............" << endl;
                            statsExit = true;
                            break; 
                        }
                    }
                }
                break; //Return control back to the main menu 
            }
            //Displays account balance
            case 6:
            {
                newAccount.output();
                break; 
            }
            //Exit the list
            case 0:
            {
                cout << "Thank you for using Bookstore Manager 2023. Have a nice day!";
                exit = true;
                break;
            }
        }
    }
}


