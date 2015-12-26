#include "Admin.h"
#include "Date.h"
//  #include "Format.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//  Constructors and destructors
//  Song() - empty constructor
Song::Song()
: title("")
{
    subtitle = "";
    release = new Date();
    id = 1000;
}

//  Song(string, Date*, unsigned) - default constructor with title, release Date
//      and id number
Song::Song(string name, Date* d, unsigned num)
: title(name), release(d), id(num)
{ subtitle = ""; }

//  ~Song() - destructor
Song::~Song()
{
    //  Cleans out the Role vector
    while(roles.size() > 0)
    {
        roles.pop_back();
    }
    //  Cleans out the Album vector
    while(albums.size() > 0)
    {
        albums.pop_back();
    }
}

//  Accessors
//  void print() - prints out the contents of the Song object
void Song::print()
{
    return;
}

//  Mutators
//  void add() - adds content to an empty Song object
void Song::add()
{
    return;
}

//  void modify() - allows user to modify content of a Song object
void Song::modify()
{
    return;
}

//  void remove() - removes all content of a Song object
void Song::remove()
{
    return;
}
