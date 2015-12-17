#include <iostream>

using namespace std;

//  string zero(unsigned) - Returns a leading zero for date
string zero(unsigned);

//  unsigned prompt(string&, unsigned) - checks the user's choice against 
//      the number of choices available.
unsigned prompt(string input = "this", unsigned max = 3);

//  unsigned promptNav(unsigned) - checks the user's navigation choice
unsigned promptNav(unsigned);

//  unsigned promptYN(char) - checks for a user's yes/no answer
unsigned promptYN(string input = "this");
