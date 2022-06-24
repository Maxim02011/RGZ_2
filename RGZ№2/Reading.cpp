#include "reading.h"

int getsize(FILE* file)
{
	int loc = ftell(file);
	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	fseek(file, loc, SEEK_SET);
	return size;
}

string ReadYear(FILE* file, int readloc)
{

	char magic[5];
	fseek(file, readloc, SEEK_SET);
	fread(magic, 1, 4, file);
	magic[4] = '\0';
	string str(magic);
	return str;
}
string ReadThirty(FILE* file, int readloc)
{

	char magic[30];
	fseek(file, readloc, SEEK_SET);
	fread(magic, 1, 30, file);
	string str(magic);
	return str;
}
void ReadMP3(FILE* file, MP3Tag tag)
{

	int readloc = getsize(file) - 125;
	tag.Title = ReadThirty(file, readloc);
	readloc += 30;
	tag.Artist = ReadThirty(file, readloc);
	readloc += 30;
	tag.Album = ReadThirty(file, readloc);
	readloc += 30;
	tag.Year = ReadYear(file, readloc);
	readloc += 4;
	tag.Comment = ReadThirty(file, readloc);
	cout << "Artist: " << tag.Artist << endl;
	cout << "Title: " << tag.Title << endl;
	cout << "Album: " << tag.Album << endl;
	cout << "Year: " << tag.Year << endl;
	cout << "Comment: " << tag.Comment << endl << endl;
}




