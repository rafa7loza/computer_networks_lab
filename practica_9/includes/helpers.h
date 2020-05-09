#ifndef HELPERS_H
#define HELPERS_H

#include <cassert>
#include <iostream>
#include <string>

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>

#define BITS_3 3
#define BITS_4 4
#define BITS_9 9
#define BITS_13 13
#define BITS_20 20
#define BYTE 8
#define BYTES_2 16
#define BYTES_4 32
#define BYTES_6 48
#define BYTES_16 128

#define debug(s) cout << " ** Debug: " << s << " **" << endl;

using namespace std;

string decToHex(int num);
string decToBin(int num);
string binToHex(string binary);
int binToDec(string binary);
string getIpAddress(string binary);
string getMACAddress(string binary);
string getIPv6Address(string binary);
int open_file(char * str);
int getFileSize(int fd);
string readPackage(char * fileName);
void printHexData(string &binary);

#endif
