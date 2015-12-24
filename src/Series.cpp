#include "Format.h"
#include "Admin.h"

#include <iostream>
#include <string>

//  Constructors and destructors
//  Series() - empty constructor
Series::Series()
{}

//  Series(string&) - default constructor with title
Series::Series(string& name)
: title(name)
{}

//  ~Series() - destructor
Series::~Series()
{}

//  Accessors
//  string getTitle() - gets the title of a Series
string Series::getTitle()
{ return this->title; }

//  string getTrack(unsigned) - gets the title of a song in the Series
string Series::getTrack(unsigned num)
{
    return this->trackList.at(num);
}

//  void print() - prints out the information for a Series
void Series::print()
{
    cout << this->getTitle() << endl;
    for(unsigned i = 0; i < this-> trackList.size(); ++i)
    {
       cout << subNum(i) << this->getTrack(i) << endl;
    }
    cout << endl;
    return;
}

//  Mutators
//  void setTitle(string&) - sets the title of the Series
void Series::setTitle(string& name)
{
    this->title = name;
    return;
}

//  void addTrack() - adds a song to a Series
void Series::addTrack(string& name)
{
    //  Checks to make sure that Song doesn't already appear in Series
    for(unsigned i = 0; i < this->trackList.size(); ++i)
    {
        if(this->getTrack(i) == name) { return; }
    }
    this->trackList.push_back(name);
    return;
}

//  void setTrack(unsigned, string) - modifies a song title for a Series
void Series::setTrack(unsigned num, string name)
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

//  void removeTrack(unsigned) - removes a song from a Series
void Series::removeTrack(unsigned num)
{
    this->trackList.erase(trackList.begin()+num);
    return;
}

//  void swapTrack(unsigned, unsigned) - swaps two songs in a Series
void Series::swapTrack(unsigned t1, unsigned t2)
{
    string s1 = this->trackList.at(t1);
    //  string s2 = this->trackList.at(t2);
    this->trackList.at(t1) = this->trackList.at(t2);
    this->trackList.at(t2) = s1;
    return;
}

//  void add() - adds to an empty Series object
void Series::add()
{
    string line;
    unsigned num = this->trackList.size();
    //  Gets the Series title
    cout << "Series: ";
    getline(cin, line);
    unsigned check = promptYN(line);
    cout << endl;
    while(check == 2)
    {
        getline(cin, line);
        cout << "Series: ";
        getline(cin, line);
        check = promptYN(line);
        cout << endl;
    }
    //  Sets the Series title
    if(check == 1)
    {
        this->title = line;
        check = 2;
    }
    //  Gets all of the songs in the Series
    while(check == 2)
    {
        getline(cin, line);
        ++num;
        
        //  Gets the song name for the Series
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
        //  Checks if user is done adding songs to Series
        check = promptYN("that all");
        cout << endl;
    }
    return;
}

//  void modify() - modifies a Series object
void Series::modify()
{
    unsigned max = 5;
    unsigned check = max;
    string line;
    //  Series modification menu
    while(check != 0)
    {
        cout << this->getTitle() << " Menu" << endl
            << "1) Change series title" << endl //  Works
            << "2) Add a song" << endl          //  Works
            << "3) Change a song" << endl       //  Works
            << "4) Remove a song" << endl       //  Works
            << "5) Swap song order" << endl;    //  Works
        check = promptNav(max);
        if(check == 1)      //  Changes the Series title
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
        else if(check == 2) //  Adds a song to the Series
        {
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
        else if((check == 3) || (check == 4) || (check == 5))
        {
            unsigned choice = check;
            check = 2;
            unsigned mod = this->trackList.size();
            unsigned modSwap = mod;
            while(check == 2)
            {
                //   Shows all songs in the series
                this->print();
                mod = promptNav(this->trackList.size());
                cout << endl;

                if(mod == 0) { return; }
                --mod;
                
                if(choice == 3)     //  Allows user to modify a song
                {
                    unsigned tCheck = 2;
                    while(tCheck == 2)
                    {
                        getline(cin, line);
                        cout << "What would you like to change \""
                            << this->getTrack(mod) << "\" to? " << endl;
                        getline(cin, line);
                        tCheck = promptYN(line);
                    }
                }
                else if(choice == 4) //  Allows user to delete song
                {
                    cout << "You will delete \"" << this->getTrack(mod) 
                        << "\"." << endl;
                }
                else if(choice == 5)    //  Allows user to swap order
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
                if(choice == 3) { setTrack(mod, line); }
                else if(choice == 4) { removeTrack(mod); }
                else if(choice == 5) { swapTrack(mod, modSwap); }
            }
        }
        cout << endl;
    }
    return;
}

//  void remove() - empties a Series object
void Series::remove()
{
    string blank = "";
    this->setTitle(blank);
    this->trackList.clear();
    return;
}
