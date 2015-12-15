#include "Format.h"

#include <iostream>
#include <string>

using namespace std;

//  string zero(unsigned) - puts in a zero if a number is less than 10
string zero(unsigned num)
{
    if(num < 10) { return "0"; }
    return "";
}

//  unsigned prompt(string&, unsigned) - asks user to confirm if input is correct
unsigned prompt(string input = "this", unsigned max = 3)
{
    unsigned a = max;
    //  Makes sure that the input is correct (and that a is in range)
    while(a >= max)
    {
        cout << "Is " << input << " correct? ";
        cin >> a;
        if(a >= max) 
        { 
            cout << "Error: incorrect input. Please enter a number less "
                << "than " << max << "." << endl;
        }

    }
    return a;
}

//  unsigned promptNav(unsigned) - checks the user's navigational input
unsigned promptNav(unsigned max)
{
    unsigned a = max;
    while(a >= max)
    {
        cout << "Where would you like to go? ";
        cin >> a;
        if(a >= max)
        {
            cout << "Error: Please enter a correct option or 0 to leave."
                << endl;
        }
    }
    return a;
}
