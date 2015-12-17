#include "Admin.h"

#include <iostream>
#include <string>

//  Empty Constructor
User::User()
{}

//  Default Constructor
User::User(string& name, string& pass, bool obj, bool use)
: username(name), password(pass), modObject(obj), modUser(use) 
{}

//  Destructor
User::~User()
{}

//  Accessors
//  string getUsername() - gets username
string User::getUsername()
{
    return this->username;
}

//  string getPassword() - gets password
string User::getPassword()
{
    return this->password;
}

//  unsigned getPrivy() - gets account privilege
unsigned User::getPrivy()
{
    unsigned privy = 0;
    if(this->modObject) { privy++; }
    if(this->modUser) { privy++; }
    return privy;
}

//  bool checkPassword(string&) - checks if password is correct
bool User::checkPassword(string& attempt)
{
    //  Checks to make sure password and input are the same size
    if(attempt.size() != password.size())
    {
        return false;
    }
    //  Checks the password
    for(unsigned i = 0; i < attempt.size(); ++i)
    {
        if(password.at(i) != attempt.at(i))
        {
            return false;
        }
    }
    return true;
}

//  Mutators
//  void setUsername(string&) - sets new username for a User
void User::setUsername(string& name)
{
    this->username = name;
    return;
}

//  void setPassword(string&) - sets new password for a User
void User::setPassword(string& pass)
{
    this->password = pass;
    return;
}

//  void setPrivyObj(bool) - sets object addition/modification privilege
void User::setPrivyObj(bool obj)
{
    this->modObject = obj;
    return;
}

//  void setPrivyUse(bool) - sets object deletion, user account addition,
//      modification, deletion
void User::setPrivyUse(bool use)
{
    this->modUser = use;
    return;
}

//  void add() - used for adding information into a user
void User::add()
{
    string name, pass;
    bool obj = false;
    bool use= false;
    cout << "When creating a new account, please note that usernames and "
        << "passwords are case sensitive. Also do not put any spaces in "
        << "either the username or password." 
        << "Creating new account..." << endl
        << "User: ";
    cin >> name;
    unsigned check = prompt(name);
    while(check == 2)
    {
        cout << "User: ";
        cin >> name;
        check = promptYN(name);
    }
    if(check == 1)
    {
        this->setUsername(name);
        check = 2;
    }
    while(check == 2)
    {
        cout << "Password: ";
        cin >> pass;
        check=promptYN(pass);
    }
    if(check == 1) 
    { 
        this->setPassword(pass);
        check = 2;
    }
    if(check != 0)
    {
        cout << "Can " << name << " add and modify information? ";
        check = promptYN();
        if(check == 1) { obj = true; }
    }
    if(check != 0)
    {
        this->setPrivyObj(obj);
        cout << "Can " << name << " add and delete other user accounts? ";
        check=promptYN();
    }
    if(check != 0)
    {
        if(check == 1) { use = true; }
        this->setPrivyUse(use);
    }
    return;
}

//  void modify() - allows a user to change their password or create new
//      a new account if they have the privilege to
void User::modify()
{
    cout << this->getUsername() << " Account Menu" << endl
        << "1) Change password" << endl;
    //  Add other account modification later
    unsigned check = promptNav(1);
    if(check == 1)
    {
        string pass;
        cout << "Current password: ";
        cin >> pass;
        bool attempt = checkPassword(pass) ;
        while(!attempt)
        {
            cout << "Please enter your current password."
                << "Current password: ";
            cin >> pass;
            attempt = checkPassword(pass);
        }
        cout << "New password: ";
        cin >> pass;
        attempt = false;
        while(!attempt)
        {
            cout << "Confirm new password: ";
            string confirm;
            cin >> confirm;
            if(pass == confirm) { attempt = true; }
        }
        this->setPassword(pass);
        cout << "Password has been changed successfully!" << endl;
    }
    return;
}

//  void remove() - clears out the user account into a guest account
void User::remove()
{
    string blank = "";
    this->setUsername(blank);
    this->setPassword(blank);
    this->setPrivyObj(false);
    this->setPrivyUse(false);
    return;
}
