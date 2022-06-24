#pragma once

#include <iostream>
#include <fstream>
#include "struct.h"
using namespace std;

void WriteArtist(FILE* file, int filesize, char Artist[]);
void WriteTitle(FILE* file, int filesize, char Title[]);
void WriteAlbum(FILE* file, int filesize, char Album[]);
void WriteYear(FILE* file, int filesize, char Year[]);
void WriteComment(FILE* file, int filesize, char Comment[]);



