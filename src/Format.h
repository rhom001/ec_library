#include <iostream>

using namespace std;

//  Returns a leading zero for date
char zero(unsigned num)
{
    if(num <= 9)
    {
        return '0';
    }
    return '';
}
