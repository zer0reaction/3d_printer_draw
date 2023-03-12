// Main file for all the interactions with user

#include <iostream>
#include <string>
#include "headers/main.h"
#include "lib/log.cpp"
#include "lib/gcode.cpp"

using namespace std;

int main()
{
	Log("Launch");
	Greeting();
	CommandLine();
}



void Greeting()												// Greets the user, shows current version etc
{
	string version = "alpha 0.2";
	cout << "You are using 3D Printer Draw, version " << version << endl;
	cout << "Type \"-help\" for available commands" << endl;
}

void CommandLine()											// For command input
{
	string s = "";
	
	// Running while the user input is not -exit
	while(s != "-exit")
	{
		cout << ">> ";
		getline(cin, s);


		
		// Processing the input
		if(s.substr(0, 5) == "-exit")
		{
			Log("Exit");

			exit(0);
		}

		// Displaying help
		else if(s.substr(0, 5) == "-help")
		{
			Log("Help command");
		
			cout << "This is the list of available commands: " << endl;
			cout << "-exit			Exits the program" << endl;
			cout << "-help			Display available commands" << endl;
			cout << "-testfile		Creating a debug file with starting commands" << endl;
			cout << "-l 			Adding a letter to a testfile" << endl;
			cout << "-m \"text\"		Adds a message to a testfile" << endl;
		}

		// Making a .gcode file for test purposes
		else if(s == "-testfile")
		{
			cout << "Generating a testfile..." << endl;

			AddCommand("home");
			AddCommand("absolute");
			AddCommand("move", "-", "-", "10");
			AddCommand("move", "100", "130", "-");

			cout << "Generating complete!" << endl;
		}

		else if(s.substr(0, 2) == "-l")
		{
			DrawLetter(s[3]);
			cout << "Written letter " << s.substr(8, 1) << endl;
		}

		else if(s.substr(0, 2) == "-m")
		{
			int pos = 4;				// Current character
			string message = "";

			while(s[pos] != '"')
			{
				DrawLetter(s[pos]);
				message += s[pos];
				pos++;
			}

			cout << "Written message: " << message << endl;
		}
	}
}
