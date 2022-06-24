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
	string fileloc = "";
		cout << "Enter path to mp3 file:\t";
		getline(cin, fileloc);
			FILE* ifile;
			cout << "Opening File: " << fileloc << endl;
			ifile = fopen(fileloc.c_str(), "r+");
			if (ifile)
			{
				if (!checkmp3(fileloc))
				{
					cout << "ERROR! File Is Not An MP3 and Can Not Be Read. Please Only Use MP3 Files" << endl;
					cin.get();
					fclose(ifile);
					return 0;
				}
				else
				{
					cout << "File " << fileloc << " Opened Successfully" << endl;
					int readloc = getsize(ifile) - 128;
					int filesize = getsize(ifile);
					string tag = Header(ifile, readloc);
					if (tag == "TAG")
					{
						cout << "File Has A Valid MP3 Tag And Will Be Read Now" << endl << endl;
						readloc += 3;
						MP3Tag tag;
						ReadMP3(ifile, tag);
						cout << "You May Now Edit the File's Tags" << endl;
						cout << "0: Exit Program" << endl;
						cout << "1. Edit Artist" << endl;
						cout << "2. Edit Title" << endl;
						cout << "3. Edit Album" << endl;
						cout << "4. Edit Year" << endl;
						cout << "5. Edit Comment" << endl;
						cout << "6. ReRead Info" << endl << endl;
						short r, reboot = 0;
						while (reboot < 1)
						{
							cout << "Please Enter Your Choice And Then Press Enter: ";
							cin >> r;
							switch (r)
							{
							case 0:
								fclose(ifile);
								return (0);
								break;
							case 1:
								char artist[31];
								cout << "Enter Desired Artist Name" << endl;
								cin.ignore();
								cin.getline(artist, 31);
								WriteArtist(ifile, filesize, artist);
								break;
							case 2:
								char title[31];
								cout << "Enter Desired Title" << endl;
								cin.ignore();
								cin.getline(title, 31);
								WriteTitle(ifile, filesize, title);
								break;
							case 3:
								char album[31];
								cout << "Enter Desired Album Title" << endl;
								cin.ignore();
								cin.getline(album, 31);
								WriteAlbum(ifile, filesize, album);
								break;
							case 4:
								char year[5];
								cout << "Enter Desired Release Year" << endl;
								cin.ignore();
								cin.getline(year, 5);
								WriteYear(ifile, filesize, year);
								break;
							case 5:
								char comment[31];
								cout << "Enter Desired Comments" << endl;
								cin.ignore();
								cin.getline(comment, 31);
								WriteComment(ifile, filesize, comment);
								break;
							case 6:
								cout << endl;
								ReadMP3(ifile, tag);
								break;
							default:
								cout << "The Number You Entered Is Not A Valid Option. Please Try Again" << endl;
								break;
							}
						}
						cin.get();
						fclose(ifile);
						return (0);
					}
					else
					{
						cout << "File Is Not Tagged With Information. Please Try A Different MP3" << endl;
						cin.get();
						fclose(ifile);
						return 0;
					}
				}
			}
			else
			{
				cout << "Error Opening File. Press The Enter Key To Exit" << endl;
				cin.get();
				return 0;
			}
			cin.get();
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

