// A library to operate with all the gcode stuff

#include <fstream>
using namespace std;

void DrawSegment(int n);

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
	// Spacing between letters is added automatically (5mm)
	// This code assumes that z is 10mm up before running
	// x is left-right
	// y is up-down

	// LETTERS TO ADD:
	// FGHIJKLMNOPQRSUVWXYZ

	if(l == 'a')
	{
		DrawSegment(5);
		DrawSegment(6);
		DrawSegment(1);
		DrawSegment(2);
		DrawSegment(3);
		DrawSegment(7);
		DrawSegment(0);
	}

	else if(l == 'b')
	{
		DrawSegment(6);
		DrawSegment(5);
		DrawSegment(7);
		DrawSegment(3);
		DrawSegment(4);
		DrawSegment(0);
	}

	else if(l == 'c')
	{
		DrawSegment(7);
		DrawSegment(5);
		DrawSegment(4);
		DrawSegment(0);
	}

	else if(l == 'd')
	{
		DrawSegment(2);
		DrawSegment(3);
		DrawSegment(4);
		DrawSegment(5);
		DrawSegment(7);
		DrawSegment(0);
	}

	else if(l == 'e')
	{
		DrawSegment(1);
		DrawSegment(2);
		DrawSegment(6);
		DrawSegment(7);
		DrawSegment(5);
		DrawSegment(4);
		DrawSegment(0);
	}

	else if(l == 'h')
	{
		DrawSegment(6);
		DrawSegment(5);
		DrawSegment(7);
		DrawSegment(3);
		DrawSegment(0);
	}

	else if(l == 'l')
	{
		DrawSegment(6);
		DrawSegment(5);
		DrawSegment(0);
	}

	else if(l == 'o')
	{
		DrawSegment(5);
		DrawSegment(7);
		DrawSegment(3);
		DrawSegment(4);
		DrawSegment(0);
	}

	else if(l == 'w')
	{
		DrawSegment(3);
		DrawSegment(4);
		DrawSegment(5);
		DrawSegment(0);
	}

	else if(l == 'r')
	{
		DrawSegment(5);
		DrawSegment(7);
		DrawSegment(0);
	}

	else if (l == '-')		// for making a space
	{
		AddCommand("move", "2.5", "-", "-");
	}

	AddCommand("absolute");
}

void DrawSegment(int n)
{
	// Starts at z=10
	// 5x10 letters should do it...
	AddCommand("absolute");
	AddCommand("move", "-", "-", "10");
	AddCommand("relative");

	if(n == 1)
	{
		AddCommand("move", "-", "-", "-10");
		AddCommand("move", "5", "-", "-");
		AddCommand("move", "-", "-", "10");
		AddCommand("move", "-5", "-", "-");
	}
	else if(n == 2)
	{
		AddCommand("move", "5", "-", "-");
		AddCommand("move", "-", "-", "-10");
		AddCommand("move", "-", "-5", "-");
		AddCommand("move", "-", "-", "10");
		AddCommand("move", "-", "5", "-");
		AddCommand("move", "-5", "-", "-");
	}
	else if(n == 3)
	{
		AddCommand("move", "5", "-5", "-");
		AddCommand("move", "-", "-", "-10");
		AddCommand("move", "-", "-5", "-");
		AddCommand("move", "-", "-", "10");
		AddCommand("move", "-5", "10", "-");
	}
	else if(n == 4)
	{
		AddCommand("move", "5", "-10", "-");
		AddCommand("move", "-", "-", "-10");
		AddCommand("move", "-5", "-", "-");
		AddCommand("move", "-", "-", "10");
		AddCommand("move", "-", "10", "-");
	}
	else if(n == 5)
	{
		AddCommand("move", "-", "-5", "-");
		AddCommand("move", "-", "-", "-10");
		AddCommand("move", "-", "-5", "-");
		AddCommand("move", "-", "-", "10");
		AddCommand("move", "-", "10", "-");
	}
	else if(n == 6)
	{
		AddCommand("move", "-", "-", "-10");
		AddCommand("move", "-", "-5", "-");
		AddCommand("move", "-", "-", "10");
		AddCommand("move", "-", "5", "-");
	}
	else if(n == 7)
	{
		AddCommand("move", "-", "-5", "-");
		AddCommand("move", "-", "-", "-10");
		AddCommand("move", "5", "-", "-");
		AddCommand("move", "-", "-", "10");
		AddCommand("move", "-5", "5", "-");
	}
	else if(n == 0)
	{
		AddCommand("move", "7.5", "-", "-");

	}

	AddCommand("absolute");

}
