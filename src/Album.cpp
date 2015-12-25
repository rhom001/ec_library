#include "Admin.h"
#include "Date.h"
#include "Format.h"

#include <iostream>
#include <string>

using namespace std;

//  Constructors and destructors
//  Album() - empty constructor
Album::Album()
: title("")
{ release = new Date(5, 17, 2009); }

//  Album(string&) - default constructor with title and date
Album::Album(string name, Date* d)
: title(name), release(d)
{}

//  ~Album() - destructor
Album::~Album()
{}

//  Accessors
//  string getTitle() - gets the title of a Album
string Album::getTitle()
{ return this->title; }

//  string getDate() - gets the release date of an Album
string Album::getDate()
{ return this->release->print(); } 

//  string getTrack(unsigned) - gets the title of a song in the Album
string Album::getTrack(unsigned num)
{ return this->trackList.at(num); }

//  unsigned getSize() - returns the size of the Album
unsigned Album::getSize()
{ return this->trackList.size(); }

//  unsigned getTrackNum(string) - gets the track number of a song in the Album
unsigned Album::getTrackNum(string name)
{
    unsigned pos;
    for(pos = 0; pos < this->trackList.size(); ++pos)
    {
        if(this->trackList.at(pos).find(name) != string::npos)
        {
            return pos;
        }
    }
    return this->getSize();
}

//  void print() - prints out the information for a Album
void Album::print()
{
    cout << this->getTitle() << endl
        << "Released: " << this->getDate() << endl;
    for(unsigned i = 0; i < this-> trackList.size(); ++i)
    {
       cout << subNum(i) << this->getTrack(i) << endl;
    }
    cout << endl;
    return;
}

//  Mutators
//  void setTitle(string&) - sets the title of the Album
void Album::setTitle(string& name)
{
    this->title = name;
    return;
}
//  void setDate() - sets the release Date of the Album
void Album::setDate()
{
    unsigned check = 2;
    Date* d = new Date(this->release->getMonth(), this->release->getDay(), 
            this->release->getYear());
    while(check == 2)
    {
        cout << "Release Date" << endl;
        d->setDate();
        cout << endl;
        check = promptYN(d->print());
        //  If correct, then set the release Date to the new Date
        if(check == 1)
        {
            this->release->setMonth(d->getMonth());
            this->release->setDay(d->getDay());
            this->release->setYear(d->getYear());
        }
    }
    delete d;
    return;
}
    
//  void addTrack() - adds a song to a Album
void Album::addTrack(string& name)
{
    //  Checks to make sure that Song doesn't already appear in Album
    for(unsigned i = 0; i < this->trackList.size(); ++i)
    {
        if(this->getTrack(i) == name) { return; }
    }
    this->trackList.push_back(name);
    return;
}

//  void setTrack(unsigned, string) - modifies a song title for a Album
void Album::setTrack(unsigned num, string name)
{
    unsigned check = 1;
    if(name.empty()) { check = 2; }
    
    //  Asks user if name is left blank
    while(check == 2)
    {
        cout << "What is the new name for " << trackList.at(num) << "? "
            << endl;
        getline(cin, name);
        check = promptYN(name);
        if(check == 0)  { return; }        
    }

    //  Sets the name of the track
    this->trackList.at(num) = name;
    return;
}

//  void removeTrack(unsigned) - removes a song from a Album
void Album::removeTrack(unsigned num)
{
    this->trackList.erase(trackList.begin()+num);
    return;
}

//  void swapTrack(unsigned, unsigned) - swaps two songs in a Album
void Album::swapTrack(unsigned t1, unsigned t2)
{
    string s1 = this->trackList.at(t1);
    //  string s2 = this->trackList.at(t2);
    this->trackList.at(t1) = this->trackList.at(t2);
    this->trackList.at(t2) = s1;
    return;
}

//  void add() - adds to an empty Album object
void Album::add()
{
    string line;
    unsigned num = this->trackList.size();
    //  Gets the Album title
    cout << "Album: ";
    getline(cin, line);
    unsigned check = promptYN(line);
    cout << endl;
    while(check == 2)
    {
        getline(cin, line);
        cout << "Album: ";
        getline(cin, line);
        check = promptYN(line);
        cout << endl;
    }
    //  Sets the Album title
    if(check == 1)
    {
        this->title = line;
        check = 2;
    }
    //  Sets the Album release date
    while(check == 2)
    {
        this->release->setDate();
        check = promptYN();
        cout << endl;
    }
    if(check == 1)
    {
        //  Release Date was already set in previous prompt
        check = 2;
    }
    //  Gets all of the songs in the Album
    while(check == 2)
    {
        getline(cin, line);
        ++num;
        
        //  Gets the song name for the Album
        cout << "Song " << num << ": ";
        getline(cin, line);
        unsigned checkT = promptYN(line);
        while(checkT == 2)
        {
            getline(cin, line);
            cout << "Song " << num << ": ";
            getline(cin, line);
            checkT = promptYN(line);
        }
        if(checkT == 1)
        {
            this->addTrack(line);
        }
        //  Checks if user is done adding songs to Album
        check = promptYN("that all");
        cout << endl;
    }
    return;
}

//  void modify() - modifies a Album object
void Album::modify()
{
    unsigned max = 6;
    unsigned check = max;
    string line;
    //  Album modification menu
    while(check != 0)
    {
        cout << this->getTitle() << " Menu" << endl
            << "1) Change album title" << endl  //  Works
            << "2) Change release date" << endl //  Works
            << "3) Add a song" << endl          //  Works
            << "4) Change a song" << endl       //  Works
            << "5) Remove a song" << endl       //  Works
            << "6) Swap song order" << endl;    //  Works
        check = promptNav(max);
        if(check == 1)      //  Changes the Album title
        {
            check = 2;
            while(check == 2)
            {
                getline(cin, line);
                cout << "What would you like to change " 
                    << this->getTitle() << " to? " << endl;
                getline(cin, line);
                check = promptYN(line);
            }
            if(check == 1) { this->setTitle(line); }
        }
        else if(check == 2) //  Changes the Album release Date
        {
            while(check == 2)
            {
                cout << "What would you like to change " << this->getDate()
                    << " to? " << endl;
                this->setDate();
                check = promptYN(this->getDate());
            }
            //  if(check == 1) { date has already been set }
        }

        else if(check == 3) //  Adds a song to the Album
        {
            check = 2;
            while(check == 2)
            {
                getline(cin, line);
                cout << "What song would you like to add? " << endl;
                getline(cin, line);
                check = promptYN(line);
            }
            if(check == 1) { this->addTrack(line); }
        }
        //  Displays track list
        else if((check == 4) || (check == 5) || (check == 6))
        {
            unsigned choice = check;
            check = 2;
            unsigned mod = this->trackList.size();
            unsigned modSwap = mod;
            while(check == 2)
            {
                //   Shows all songs in the album
                this->print();
                mod = promptNav(this->trackList.size());
                cout << endl;

                if(mod == 0) { return; }
                --mod;
                
                if(choice == 4)     //  Allows user to modify a song
                {
                    unsigned tCheck = 2;
                    while(tCheck == 2)
                    {
                        getline(cin, line);
                        cout << "What would you like to change \""
                            << this->getTrack(mod) << "\" to? " << endl;
                        getline(cin, line);
                        tCheck = promptYN("\""+line+"\"");
                    }
                }
                else if(choice == 5) //  Allows user to delete song
                {
                    cout << "You will delete \"" << this->getTrack(mod) 
                        << "\"." << endl;
                }
                else if(choice == 6)    //  Allows user to swap order
                {
                    cout << "What other song do you want to switch \""
                        << this->getTrack(mod) << "\" with? " << endl;
                    unsigned tCheck = 2;
                    while(tCheck == 2)
                    {
                        modSwap = prompt(this->trackList.size());
                        if(modSwap == 0) { return; }
                        --modSwap;
                        line = "\"";
                        line += this->getTrack(modSwap);
                        line += "\"";
                        tCheck = promptYN(line);
                    }
                }
                check = promptYN();
            }
            if(check == 1)
            {
                if(choice == 4) { setTrack(mod, line); }
                else if(choice == 5) { removeTrack(mod); }
                else if(choice == 6) { swapTrack(mod, modSwap); }
            }
        }
        cout << endl;
    }
    return;
}

//  void remove() - empties a Album object
void Album::remove()
{
    string blank = "";
    this->setTitle(blank);
    //  Date cannot be cleared so will stay until changed otherwise
    this->trackList.clear();
    return;
}
