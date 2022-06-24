#include <iostream>
#include <fstream>
#include <string>
#include "struct.h"
#include "reading.h"
#include "writing.h"

using namespace std;
bool checkmp3(string filename);
string Header(FILE* file, int readloc);
int main()
{
	return(0);
}


string Header(FILE* file, int readloc)
{
	char magic[4];
	fseek(file, readloc, SEEK_SET);
	fread(magic, 1, 4, file);
	string str(magic);
	string mag = str.substr(0, 3);
	return mag;
}
bool checkmp3(string filename)
{
    int filetype = filename.length() - 4;
    string filetipe = filename.substr(filetype, 4);
    if (filetipe == ".mp3")
    {
        return true;
    }
    else
    {
        return false;
    }
}

