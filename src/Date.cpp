#include "Date.h"
using namespace std; 

Date::Date()
{
    cout << "Enter the year the book was published: "; cin >> year;
    cout << "Enter the month the book was published :" ; cin >> month;
    cout << "Enter the day the book was published: "; cin >> day;
    cout << endl;
}//Constructor 

Date::~Date() {};//Unimplemented Destructor

void Date::output()
{
    cout << "Published Date: " << month << "/" << day << "/" << year;
}