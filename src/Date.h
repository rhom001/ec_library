/// Date header file

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date
{
    private:
        unsigned month;
        unsigned day;
        unsigned year;
    public:
        Date();
        Date(unsigned, unsigned, unsigned);
        Date(Date&);
        ~Date();
        bool operator<(const Date&) const;
        //  Accessors
        unsigned getMonth();
        unsigned getDay();
        unsigned getYear();
        string print(unsigned display = 0);
        //  Mutators
        void setMonth(unsigned);
        void setDay(unsigned);
        void setYear(unsigned);
        void setDate();

    private:
        //  Private helper functions
        bool checkMonth(unsigned);
        bool checkDay(unsigned);
        bool checkYear(unsigned);
};

#endif  //  DATE_H
