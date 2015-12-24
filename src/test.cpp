#include "Date.h"
#include "Admin.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    /*
    //  Tests the Date class
    cout << "Date class" << endl;
    Date* d = new Date(12, 27, 2007);
    cout << "My birthday is " << d->print(1) << endl;
    cout << endl;

    unsigned month, day, year;
    cout << "What is your birthday?" << endl
        << "Month: ";
    cin >> month;
    cout << "Date: ";
    cin >> day;
    cout << "Year: ";
    cin >> year;
    Date* birthday = new Date(month, day, year);
    cout << "Your birthday is " << birthday->print() << endl;
    cout << endl;
    */
    /*
    //  Tests the Role class
    cout << "Role class" << endl;
    string c = "Rin-chan";
    string v = "Kagamine Rin";
    Role* r1 = new Role(c, v);
    r1->print();
    cout << endl;

    cout << "Time to add a new Role" << endl;
    Role* r2 = new Role();
    r2->add();
    
    cout << "The new role is ";
    r2->print();
    cout << endl;

    cout << "We will now remove " << r2->getRole() << "/" 
        << r2->getVocal() << endl;
    r2->remove();
    cout << "The role has been cleared!" << endl;
    r2->print();
    cout << endl;

    cout << "Let us now modify the first role!" << endl;
    r1->modify();
    r1->print();
    cout << endl;
    */
    /*
    //  Tests the User class
    cout << "User class" << endl;
    string username = "Guest";
    string password = "password";
    cout << "User: " << username << endl
        << "Password: " << password << endl;
    cout << endl;

    User* u1 = new User(username, password, true, false);
    u1->print();
    cout << endl;

    cout << "Adding a new User..." << endl;
    User* u2 = new User();
    u2->add();
    u2->print();
    cout << endl;

    cout << "Time to remove the second user!" << endl;
    u2->remove();
    u2->print();
    cout << endl;

    cout << "Let's change the first user" << endl;
    u1->modify();
    u1->print();
    */
    //  /*
    //  Tests the Series class
    cout << "Series class" << endl;
    string name = "Seven Deadly Sins";
    Series* s1 = new Series(name);
    string song = "Madness of Duke Venomania";
    s1->addTrack(song);
    s1->print();

    cout << "Now, let us add a new Series!" << endl;
    Series* s2 = new Series();
    s2->add();
    s2->print();

    cout << "Now we'll delete this second series..." << endl;
    s2->remove();
    s2->print();

    cout << "Then we'll modify the first series..." << endl;
    s1->modify();
    s1->print();
    //  */
    return 0;
}
