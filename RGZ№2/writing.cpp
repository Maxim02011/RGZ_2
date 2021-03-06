#include "writing.h"

void WriteArtist(FILE* file, int filesize, char Artist[])
{
	int writeloc = filesize - 95;
	fseek(file, writeloc, SEEK_SET);
	fwrite(Artist, 1, 30, file);
	cout << Artist << " set as The Artist" << endl;
}
void WriteTitle(FILE* file, int filesize, char Title[])
{
	int writeloc = filesize - 125;
	fseek(file, writeloc, SEEK_SET);
	fwrite(Title, 1, 30, file);
	cout << Title << " set as The Title" << endl;
}
void WriteAlbum(FILE* file, int filesize, char Album[])
{
	int writeloc = filesize - 65;
	fseek(file, writeloc, SEEK_SET);
	fwrite(Album, 1, 30, file);
	cout << Album << " set as The Album" << endl;
}
void WriteYear(FILE* file, int filesize, char Year[])
{
	int writeloc = filesize - 35;
	fseek(file, writeloc, SEEK_SET);
	fwrite(Year, 1, 4, file);
	cout << Year << " set as The Release Year" << endl;
}
void WriteComment(FILE* file, int filesize, char Comment[])
{
	int writeloc = filesize - 31;
	fseek(file, writeloc, SEEK_SET);
	fwrite(Comment, 1, 30, file);
	cout << Comment << " set as The Comment" << endl;
}
