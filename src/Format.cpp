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
