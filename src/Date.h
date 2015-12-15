/*  
    Date header file
*/

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class Date
{
    private:
        unsigned month;
        unsigned day;
        unsigned year;
    public:
        Date(unsigned, unsigned, unsigned);
        ~Date();
        bool operator<(const Date&) const;
        //  Accessors
        unsigned getMonth();
        unsigned getDay();
        unsigned getYear();
        string print(unsigned);
        //  Mutators
        void setMonth(unsigned);
        void setDay(unsigned);
        void setYear(unsigned);

    private:
        //  Private helper functions
        bool checkMonth(unsigned);
        bool checkDay(unsigned);
        bool checkYear(unsigned);
};

#endif  //  DATE_H
