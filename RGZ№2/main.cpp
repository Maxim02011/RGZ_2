#define _CRT_SECURE_NO_WARNINGS
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
	//Checks for ID3v1 Tag Header 4bytes long...
	//currently only supports v1
	//v1+ coming later
	char magic[4];
	fseek(file, readloc, SEEK_SET);
	fread(magic, 1, 4, file);
	string str(magic);
	string mag = str.substr(0, 3);
	return mag;
}

