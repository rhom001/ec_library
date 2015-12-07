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
        Admin();
        ~Admin();
        virtual void add() = 0;
        virtual void modify() = 0;
        virtual void remove() = 0;
        virtual void print() = 0;
};

//  Song - holds song information
class Song: public Admin
{
    private:
        string title;           //  Song title
        string subtitle;        //  English title
        Date* release;          //  Release date
        vector<Role*> roles;    //  All vocalists
        vector<Album*> albums;  //  All albums
    public:
        // Constructors and destructors
        Song(string, Date*);
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
class Canon: public Admin
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
class Video: public Admin
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

//  Album - holds album information
class Album: public Admin
{
    private:
        string title;
        Date* release;
        vector<string> trackList;
    public:
        Album(string, Date*);
        ~Album();
        //  Accessors
        string getTitle();
        unsigned getTrack(string);
        void print();
        //  Mutators
        void add();
        void modify();
        void remove();
};

//  Series - holds series information
class Series: public Admin
{
    private;
        string title;
        vector <string> seriesList;
    public:
        Series(string);
        ~Series();
        //  Accessors
        string getTitle();
        void print();
        //  Mutators
        void add();
        void modify();
        void remove();
};

//  Role - holds character information
class Role: public Admin
{
    private:
        string role;
        string vocal;
    public:
        Role(string, string);
        ~Role();
        //  Accessors
        string getRole();
        string getVocal();
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
        User(string, string);
        ~User();
        //  Accessors
        string getUsername();
        string getPassword();
        //  Mutators
        void add();
        void modify();
        void remove();
};

#endif  //  ADMIN_H
