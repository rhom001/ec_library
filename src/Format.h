#ifndef FORMAT_H
#define FORMAT_H

#include <iostream>
#include <string>

using namespace std;

//  string tab(unsigned) - Returns a custom tab space
string tab(unsigned);

//  string zero(unsigned) - Returns a leading zero
string zero(unsigned);

//  string subNum(unsigned) - Returns a list number for a vector or list
string subNum(unsigned, unsigned tNum = 3, unsigned lv = 1);

//  unsigned prompt(string&, unsigned) - checks the user's choice against 
//      the number of choices available.
unsigned prompt(unsigned max = 1);

//  unsigned promptNav(unsigned) - checks the user's navigation choice
unsigned promptNav(unsigned);

//  unsigned promptYN(char) - checks for a user's yes/no answer
unsigned promptYN(string input = "this");

#endif  //  FORMAT_H
