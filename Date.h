#pragma once
#include <iostream>
using namespace std;

//Basic date class containing year, month and day
class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date(); 
    //Destructor: Not implemented 
    ~Date();
    //Output date info
    void output(); 
};

