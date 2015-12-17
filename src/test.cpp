#include "Date.h"
#include "Admin.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    //  Tests the Date class
    Date* d = new Date(5, 5, 1994);
    cout << "My birthday is " << d->print(1) << endl;

    //  Tests the Role class
    string c = "Rin-chan";
    string v = "Kagamine Rin";
    Role* r1 = new Role(c, v);
    r1->print();

    Role* r2 = new Role();
    r2->add();
    r2->print();
    return 0;
}
