#include "Node.h"
#include "Book.h"

//Default constructor initializes all pointers to null
Node::Node()
{
    this->information = nullptr;
    this->next = nullptr;
    this->previous = nullptr;
}

//Intilizes a node using book pointer as data 
Node::Node(Book& bookObjectPtr)
{
    this->information = &bookObjectPtr;
    this->next = nullptr;
    this->previous = nullptr;
}

//Gets next pointer 
Node* Node::getNext()
{
    return next;
}

//Gets previous pointer 
Node* Node::getPrevious()
{
    return previous;
}

//Sets the next pointer 
void Node::setNext(Node* next)
{
    this->next = next;
}

//Sets previous pointer
void Node::setPrevious(Node* previous)
{
    this->previous = previous;
}


