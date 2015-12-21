#include "Format.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//  string tab(unsigned) - creates a tab of a certain amount of spaces
string tab(unsigned num)
{
    string line;
    for(unsigned i = 0; i < num; ++i)
    {
        line += ' ';
    }
    return line;
}

//  string zero(unsigned) - puts in a zero if a number is less than 10
string zero(unsigned num)
{
    if(num < 10) { return "0"; }
    return "";
}

//  string subNum(unsigned) - puts a tabbed list number for a vector/list
string subNum(unsigned num, unsigned tNum, unsigned lv)
{
    //  Adds one to the iterator
    ++num;
    stringstream ss;
    ss << num;
    
    //  Creates the tabbed list number
    string sub;
    string line = tab(tNum * lv) + zero(num);
    ss >> sub;
    line += sub;
    line += ") ";
    return line;
}

//  unsigned prompt(string&, unsigned) - asks user to confirm if input is 
//      correct
unsigned prompt(unsigned max)
{
    unsigned a;
    cout << "Option: ";
    cin >> a;
    cout << endl;

    //  Makes sure that the input is correct (and that a is in range)
    while(a > max)
    {
        cout << "Error: incorrect input. Please enter a number at most "
            << max << "." << endl;
        cout << "Option:  ";
        cin >> a;
        cout << endl;
    }
    return a;
}

//  unsigned promptNav(unsigned) - checks the user's navigational input
unsigned promptNav(unsigned max)
{
    unsigned a;
    cout << "Where would you like to go? ";
    cin >> a;
    cout << endl;

    while(a > max)
    {
        cout << "Error: Please enter a correct option or 0 to leave."
            << endl;

        cout << "Where would you like to go? ";
        cin >> a;
    }
    return a;
}

//  unsigned promptYN(char) - checks the user's yes/no response
unsigned promptYN(string input)
{
    char ans;
    cout << "Is " << input << " correct? ";
    cin >> ans;
    if((ans == 'y') || (ans == 'Y') || (ans == '1')) { return 1; }
    else if((ans == 'n') || (ans == 'N') || (ans == '2')) { return 2; }
    else if(ans == '0') { return 0; }
    cout << "Error: please enter 'y', 'Y', 'n', 'N', or '0', '1', '2'."
        << endl;
    return promptYN();
}
