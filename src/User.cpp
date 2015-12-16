#include "Admin.h"

#include <iostream>
#include <string>

//  Default Constructor
User::User(string& name, string& pass)
: username(name), password(pass)
{}

//  Destructor
User::~User()
{}

//  Accessors
//  string getUsername() - gets username
string User::getUsername()
{
    return username;
}

//  string getPassword() - gets password
string User::getPassword()
{
    return password;
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
//  void add() - used for adding information into a user emik 
