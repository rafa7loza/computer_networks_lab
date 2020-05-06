#ifndef HELPERS_H
#define HELPERS_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>

#define BITS_3 3
#define BITS_4 4
#define BITS_13 13
#define BITS_20 20
#define BYTE 8
#define BYTES_2 16
#define BYTES_4 32
#define BYTES_6 48
#define BYTES_16 128

using namespace std;

string hexToString(int num);
string binToString(int num);
int binToDec(string binary);
string getAddress(string binary);

#endif
