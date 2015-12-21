/// Date class definition
#include "Format.h"
#include "Date.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//  Date(unsigned, unsigned, unsigned) = default Date constructor
Date::Date(unsigned m, unsigned d, unsigned y)
: month(m), day(d), year(y)
{
    //  Checks if month is less than 1 or greater than 13
    if(month < 1) { month = 1; }
    else if(month > 12) { month = 12; }
    //  Checks if day is less than 32 for months 1, 3, 5, 7, 8, 10, 12; checks 
    //      if day is less than 31 for months 4, 6, 9, 11; checks if month 2 is
    //      less than 30 days for leap year, else days is less than 29; checks 
    //      if days are less than 1
    if((day > 31) && (((month <= 7) && ((month % 2) == 1)) || 
        ((month >= 8) && ((month % 2) == 0)))) { day = 31; }
    else if((day > 30) && (((month < 7) && ((month % 2) == 1)) ||
        ((month > 8) && ((month %2) == 0)))) { day = 30; }
    else if((day > 29) && (month == 2) && ((year % 4) == 0)) { day = 29; }
    else if((day > 28) && (month == 2) && ((year % 4) > 0)) { day = 28; }
    else if(day < 1) { day = 0; }
    //  Checks if year is less than 2008
    if(year > 2008) { year = 2008; } 
    //  Checks if year is greater than current year + 1       
}

//  ~Date() - Date destructor
Date::~Date()
{}

//  bool &operator <(const Date&) const- overloads the less than sign for the 
//      Date object
bool Date::operator <(const Date &d) const
{
    if(month < (this->month))
    {
        if(day < (this->day))
        {
            if(year < (this->year))
            {
                return true;
            }
        }
    }
    return false;
}
//  Public accessors
//  unsigned getMonth() - Returns the month
unsigned Date::getMonth()
{
    return month;
}

//  unsigned getDay() - Returns the day
unsigned Date::getDay()
{
    return day;
}

//  unsigned getYear() - Returns the year
unsigned Date::getYear()
{
    return year;
}

//  string print(unsigned) - Prints out the date in a certain format determined 
//      by the display unsigned integer
string Date::print(unsigned display)
{
    string date;
    string m, d, y;
    stringstream ss;
    ss << month << ' ' << day << ' ' << year;
    ss >> m >> d >> y;
    while(display > 3)      //  If display is not a choice, loop until correct
    {
        cout << "Error: incorrect date format" << endl;
        cin >> display;
    }
    if(display == 0)        //  Date: month/day/year
    {
        date = zero(month) + m+ "/" + zero(day) + d+ "/" + y;
    }
    else if(display == 1)   //  Date: month-day-year
    {
        date = zero(month) + m+ "-" + zero(day) + d+ "-" + y;
    }
    else if(display == 2)   //  Date: year/month/day
    {
        date = y+ "/" + zero(month) + m+ "/" + zero(day) + d;
    }
    else if (display == 3)  //  Date: year-month-day
    {
        date = y+ "-" + zero(month) + m+ "-" + zero(day) + d;
    }
    return date;
}

//  Public mutators
//  void setMonth(unsigned) - Sets the month
void Date::setMonth(unsigned m)
{
    while(!(checkMonth(m)))
    {
        cout << "The month " << m << " does not exist." << endl 
            << "Please put in a correct month." << endl;
        cin >> m;
    }
    month = m;
    //  cout << "Month has been changed successfully to " << m << endl;
    return;
}

//  void setDay(unsigned) - Sets the day
void Date::setDay(unsigned d)
{
    while(!(checkDay(d)))
    {
        cout << "The day " << d << " does not exist." << endl
            << "Please put in a correct day." << endl;
        cin >> d;
    }
    day = d;
    //  cout << "Day has been successfully changed to " << d << endl;
    return;
}

//  void setYear(unsigned) - Sets the year
void Date::setYear(unsigned y)
{
    while(!(checkYear(y)))
    {
        cout << "The year " << y << " does not exist." << endl
            << "Please put in a correct year." << endl;
        cin >> y;
    }
    year = y;
    //  cout << "Year has been successfully changed to " << y << endl;
    return;
}

//  Private helper functions
//  bool checkMonth(unsigned) - Checks if month is less than 13 and greater than
//  0
bool Date::checkMonth(unsigned m)
{
    if((m < 1) || (m > 12))
    {
        return false;
    }
    return true;
}

//  bool checkDay(unsigned) - Checks if day is valid for the month
bool Date::checkDay(unsigned d)
{
    //  Checks if day is greater than 0
    if(d < 0) { return false; }
    //  Checks for months 1, 3, 5, 7, 8, 10, 12
    else if((day > 31) && (((this->month <= 7) && ((month % 2) == 1)) ||
        ((this->month >= 8) && ((month % 2) == 0)))) { return false; }
    //  Checks for months 4, 6, 9, 11
    else if((day > 30) && (((this->month < 7) && ((month % 2) == 0)) ||
        ((this->month > 8) && ((month % 2) == 1)))) { return false; }
    //  Checks for month 2 and leap year
    else if((day > 29) && ((this->month == 2) && ((this->year % 4) == 0)))
    { return false; }
    //  Checks for month 2 and not leap year
    else if((day > 28) && ((this->month == 2) && ((this->year % 4) > 0)))
    { return false; }
    //  Otherwise day is correct
    return true;
}

//  bool checkYear(unsigned) - Checks if the year is valid
bool Date::checkYear(unsigned y)
{
    //  Checks if year is less than 2008
    if(y < 2008) { return false; }
    //  Checks if year is greater than this year + 1
    return true;
}
