// A bunch of functions to automatically log some details

#include <fstream>
#include <ctime>
#include <time.h>
using namespace std;

void Log(string s)								// Logging everything
{
	// Getting time
	time_t rawtime;
	time (&rawtime);
	ofstream fout;
	
	// Adding text to log.txt
	fout.open("logs/log.txt", ios_base::app);
	fout << ctime(&rawtime) << s << endl;
	fout.close();
}
