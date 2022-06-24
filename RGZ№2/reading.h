#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "struct.h"
using namespace std;

int getsize(FILE* file);
string ReadThirty(FILE* file, int readloc);
string ReadYear(FILE* file, int readloc);
void ReadMP3(FILE* file, MP3Tag tag);
