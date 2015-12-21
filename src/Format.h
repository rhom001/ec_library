#ifndef _FORMAT_H__
#define _FORMAT_H__

#include <string>
using std::string;

void ClearScreen();

void generic_menu();

void generic_guestmenu(bool& b_exit);

void generic_usermenu();

void generic_adminmenu();

void login();

// string zero(unsigned) - Returns a leading zero for date
string zero(unsigned);		
	
// unsigned prompt(string&, unsigned) - checks the user's choice against
// the number of choices available.
unsigned prompt(string input = "this", unsigned max = 3);
// unsigned promptNav(unsigned) - checks the user's navigation choice
unsigned promptNav(unsigned);
// unsigned promptYN(char) - checks for a user's yes/no answer
unsigned promptYN(string input = "this");

#endif
