#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "struct.h"
#include "reading.h"

using namespace std;
bool checkmp3(string filename);
string Header(FILE* file, int readloc);
int main()
{
	return(0);
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

