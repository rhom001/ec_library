#include "Format.h"
#include "Admin.h"
#include <iostream>
#include <string>
using std::string;
using namespace std;

void ClearScreen()
{
	cout << "\033[2J\033[1;1H";
}

void generic_menu()
{
	cout<<"1. Song"<<endl;
	cout<<"2. Album"<<endl;
	cout<<"3. Series"<<endl;
	cout<<"4. Roles"<<endl;
	cout<<"5. Search"<<endl;
}

void generic_guestmenu(bool& b_exit)
{
	int choice;
	generic_menu();
	cout<<"6. Log in"<<endl;
	cout<<"7. Sign up"<<endl;
	cout<<"8. Exit"<<endl;
	cout<<"Please enter your choice(1-8): ";
	cin >>choice;
	cout<<endl;
	switch(choice)
	{
	case 1:
		//Song
		cout<<"I do nothing atm"<<endl;
		break;
	case 2:
		//Album
		cout<<"I do nothing atm"<<endl;
		break;
	case 3:;
		//Series				
		cout<<"I do nothing atm"<<endl;
		break;
	case 4:
		//Roles
		cout<<"I do nothing atm"<<endl;
		break;
	case 5:
		//seach
		cout<<"I do nothing atm"<<endl;
		break;
	case 6:
		//login
		login();
		break;
	case 7:
		//signup
		cout<<"I do nothing atm"<<endl;
		break;
	case 8:
		{
		cout<<"Goodbye"<<endl;
		b_exit = true;
		break;
		}
	default:
		cout<<"Invalid Input: Please choose between options: 1 - 8."<<endl;
		break;
	}
}

void generic_usermenu()
{
	generic_menu();
	cout<<"6. User Settings"<<endl;
		
}

void generic_adminmenu()
{
	generic_usermenu();
	cout<<"7. Administration"<<endl;

}

void login() //Login Menu
{
	string user_input,pass_input;
	bool user_validation = false;
	ClearScreen();
	cout<<"-----------------------------------------------------"<<endl;

	while (user_validation == false)
	{
		cout<<"Enter your username ('R' or 'r to return to main menu): ";
		cin>>user_input;
		if(user_input== "R"||user_input=="r")
		{
			ClearScreen();
			cout<<"Returning to main menu ..."<<endl;
			return;
		}
		cout<<"Enter your password: ";
		cin>>pass_input;
		
		//check if valid user
		//for(unsigned i=0;i<user_list.size();i++)
		//{
		//	cout<<"check "<<i<<endl;
		//	user_validation = user_list[i].check(user_input,pass_input);
		//	if(user_validation ==true)
		//	{
		//		//assign user
		//		run();
		//		return;
		//	}
		//}
		
		//if user ...
		
		//if admin ...
		
		
		cout<<"Not a valid Username or Password!"<<endl;
	}
}

// string zero(unsigned) - puts in a zero if a number is less than 10
string zero(unsigned num)
{
	string temp="";
	if(num < 10) 
	{ 
		temp = num;
		return temp; 
	}
	return temp;;
}


// unsigned prompt(string&, unsigned) - asks user to confirm if input is correct
unsigned prompt(string input, unsigned max)
{
	unsigned a;
	cout << "Is " << input << " correct? ";
	cin >> a;
	cout << endl;
	// Makes sure that the input is correct (and that a is in range)
	while(a > max)
	{
		cout << "Error: incorrect input. Please enter a number at most "
		<< max << "." << endl;
		cout << "Is " << input << " correct? ";
		cin >> a;
		cout << endl;
	}
	return a;
}
// unsigned promptNav(unsigned) - checks the user's navigational input
unsigned promptNav(unsigned max)
{
	unsigned a;
	cout << "Where would you like to go? ";
	cin >> a;
	while(a > max)
	{
		cout << "Error: Please enter a correct option or 0 to leave."
		<< endl;
		cout << "Where would you like to go? ";
		cin >> a;
	}
	return a;
}
// unsigned promptYN(char) - checks the user's yes/no response
unsigned promptYN(string input)
{
	char ans;
	cout << "Is " << input << " correct? ";
	cin >> ans;
	if((ans == 'y') || (ans == 'Y') || (ans == '1')) { return 1; }
	else if((ans == 'n') || (ans == 'N') || (ans == '2')) { return 2; }
	else if(ans == '0') { return 0; }
	cout << "Error: please enter 'y', 'Y', 'n', 'N', or '0', '1', '2'."
	<< endl;
	return promptYN();
}
