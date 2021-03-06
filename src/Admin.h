/// Admin.h - Header file for holding all classes derived from Admin class

#ifndef ADMIN_H
#define ADMIN_H

#include "Format.h"
#include "Date.h"

#include <iostream>
#include <string>
#include <vector>

//  Admin - abstract base class
class Admin
{
    private:
    public:
        //  Admin();
        //  ~Admin();
        virtual void add() = 0;
        virtual void modify() = 0;
        virtual void remove() = 0;
        virtual void print() = 0;
};

//  Role - holds character information
class Role : public Admin
{
    private:
        string role;
        string vocal;
    public:
        Role();
        Role(string&, string&);
        ~Role();
        //  Accessors
        string getRole();
        string getVocal();
        void print();
        //  Mutators
        void setRole(string&);
        void setVocal(string&);
        void add();
        void modify();
        void remove();
};

//  Series - holds series information
class Series : public Admin
{
    private:
        string title;
        vector <string> trackList;
    public:
        Series();
        Series(string&);
        ~Series();
        //  Accessors
        string getTitle();
        string getTrack(unsigned);
        void print();
        //  Mutators
        void setTitle(string&);
        void addTrack(string&);
        void setTrack(unsigned, string name="");
        void removeTrack(unsigned);
        void swapTrack(unsigned, unsigned);
        void add();
        void modify();
        void remove();
};

//  Album - holds album information
class Album : public Admin
{
    private:
        string title;
        Date* release;
        vector<string> trackList;
    public:
        Album();
        Album(string, Date*);
        ~Album();
        //  Accessors
        string getTitle();
        string getDate();
        string getTrack(unsigned);
        unsigned getSize();
        unsigned getTrackNum(string);
        void print();
        //  Mutators
        void setTitle(string&);
        void setDate();
        void addTrack(string&);
        void setTrack(unsigned, string name="");
        void removeTrack(unsigned);
        void swapTrack(unsigned, unsigned);
        void add();
        void modify();
        void remove();
};

//  Song - holds song information
class Song : public Admin
{
    private:
        string title;           //  Song title
        string subtitle;        //  English title
        Date* release;          //  Release date
        unsigned id;            //  Id number (possibly just vector index)
        vector<Role*> roles;    //  All vocalists
        vector<Album*> albums;  //  All albums
    public:
        // Constructors and destructors
        Song();
        Song(string, Date*, unsigned);
        ~Song();
        //  Accessors
        string getTitle();
        string getSub();
        Date* getDate();
        bool checkId(Date*, Album*);
        bool getRole(string, string);
        bool getAlbum(string);
        void print();
        //  Mutators
        void add();
        void modify();
        void remove();
};

//  Canon - decorator for Song, holds canonical information
class Canon : public Admin
{
    private:
        vector<Series*> series; //  Holds all series that the song is in
        int ec;                 //  EC year
    public:
        Canon();
        Canon(int);
        Canon(Series*);
        Canon(Series*, int);
        ~Canon();
        //  Accessors
        int getEc();
        void print();
        //  Mutators
        void add();
        void modify();
        void remove();
};

//  Video - decorator for Song, holds video information
class Video : public Admin
{
    private:
        Date* upload;
        vector<string> illust;
    public:
        Video();
        Video(Date*);
        ~Video();
        //  Acccesors
        void print();
	//  Mutators
        void add();
        void modify();
        void remove();
};

//  User - holds user information
class User : public Admin
{
    private:
        string username;
        string password;
        bool modObject;
        bool modUser;
    public:
        User();
        User(string&, string&, bool, bool);
        ~User();
        //  Accessors
        string getUsername();
        string getPassword();
        unsigned getPrivy();
        bool checkPassword(string&);
        void print();
        //  Mutators
        void setUsername(string&);
        void setPassword(string&);
        void setPrivyObj(bool);
        void setPrivyUse(bool);
        void add();
        void modify();
        void remove();
};

#endif  //  ADMIN_H
