// A library to operate with all the gcode stuff

#include <fstream>
using namespace std;

void AddCommand(string command, string x = "", string y = "", string z = "")	// Adding a command to output file
{
	ofstream fout;
	fout.open("output/file.gcode", ios_base::app);



	// Homes axes
	if(command == "home")							
	{
		fout << "G28 ; home all axes\n";
		Log("Homed all axes");
	}

	// Moves printer head to specified location, use "-" to keep the dimension the same
	else if(command == "move")
	{
		Log("New move: " + x + " " + y + " " + z);
		fout << "G01 ";

		if(x != "-")
		{
			fout << "X" << x << " ";
		}
		if(y != "-")
		{
			fout << "Y" << y << " ";
		}
		if(z != "-")
		{
			fout << "Z" << z << " ";
		}

		fout << endl;
	}

	// Switch to absolute system of coordinates
	else if(command == "absolute")
	{
		Log("Switching to absolute system of coordinates");
		fout << "G90\n";
	}

	// Switch to relative system of coordinates
	else if(command == "relative")
	{
		Log("Switching to relative system of coordinates");
		fout << "G91\n";
	}

	fout.close();
}

// Draws a letter with a pencil
void DrawLetter(char l)
{
	AddCommand("absolute");
	AddCommand("move", "-", "-", "10");
	AddCommand("relative");

	// Starting point of the letter is in the top left corner
	// All the letters are 20x10 mm in size
	// Spacing between letters is added automatically
	// This code assumes that z is 10mm up before running
	// x is left-right
	// y is up-down
	if(l == 'l')
	{
		AddCommand("move", "-", "-", "-10");
		AddCommand("move", "-", "-20", "-");
		AddCommand("move", "10", "-", "-");
		AddCommand("move", "-", "-", "10");
		AddCommand("move", "2", "20", "-");
	}

	AddCommand("absolute");
}
