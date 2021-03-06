#include "Admin.h"

#include <iostream>
#include <string>

//  Default constructor
Role::Role()
{}

//  Filled-in
Role::Role(string& name, string& actor)
: role(name), vocal(actor)
{}

//  Destructor
Role::~Role()
{}

//  Accessors
//  string getRole() - gets the character's role
string Role::getRole()
{ 
    return role; 
}

//  string getVocal() - gets the character's vocalist
string Role::getVocal()
{
    return vocal;
}

//  void print() - prints out the vocalist and their role
void Role::print()
{
    cout << this->vocal << " as " << this->role << endl;
    return;
}

//  Mutators
//  void setRole(string&) - sets a new name as a character role
void Role::setRole(string& name)
{
    role = name; 
    return;
}

//  void setVocal(string&) - sets a new name as a Vocaloid [check a list?]
void Role::setVocal(string& name)
{
    vocal = name;
    return;
}

//  void add() - adds in the role and Vocaloid
void Role::add()
{
    string line;
    unsigned check = 2;
    //  Gets the character name
    cout << "Character: ";
    //  getline(cin, line);
    getline(cin, line);
    check = promptYN(line);
    cout << endl;
    while(check == 2)
    {
        getline(cin, line);
        cout << "Character: ";
        getline(cin, line);
        check = promptYN(line);
        cout << endl;
    }
    //  Sets the character role
    if(check == 1)
    {
        this->setRole(line);
        check = 2;
    }
    //  Gets the Vocaloid    
    while(check == 2)
    {
        getline(cin, line);
        cout << "Vocaloid: ";
        getline(cin, line);
        check = promptYN(line);
        cout << endl;
    }
    //  Sets the Vocaloid
    if(check == 1) { this->setVocal(line); }
    return;
}

//  void modify() - asks if the user wants to change anything
void Role::modify()
{
    unsigned max = 2;
    unsigned check = max;
    //  Character modification menu
    while(check != 0)
    {
        cout << this->getRole() << " Menu" << endl
            << "1) Change character name" << endl
            << "2) Change Vocaloid" << endl;
        check = promptNav(max);
        string line;
        if(check == 1)
        {
            check = 2;
            while(check == 2)
            {
                getline(cin, line);
                cout << "What would you like to change " 
                    << this->getRole() << " to? ";
                getline(cin, line);
                check = promptYN(line);
            }
            if(check == 1) { this->setRole(line); }
        }
        if(check == 2)
        {
            while(check == 2)
            {
                getline(cin, line);
                cout << "What Vocaloid would you like to change " 
                    << this->getVocal() << " to? ";
                getline(cin, line);
                check = promptYN(line);
            }
            if(check == 1) { this->setVocal(line); }
        }
        cout << endl;
    }
    return;
}
        
//  void remove() - removes the Role object
void Role::remove()
{
    string blank = "";
    this->setRole(blank);
    this->setVocal(blank);
    //  delete this;
    return;
}
