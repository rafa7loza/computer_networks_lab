#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <math.h>

#define BITS_3 3
#define BITS_4 4
#define BITS_13 13
#define BYTE 8
#define BYTES_2 16
#define BYTES_4 32


#define VERSION "version"
#define HEADER_LENGTH "length_header"
#define SERVICE_TYPE "service"
#define TOTAL_LENGTH "length_total"
#define IDENTIFIER "id"
#define FLAGS "flags"
#define FRAGMENT_POSITION "fr_position"
#define TTL "ttl"
#define PROTOCOL "prot"
#define CHECKSUM_HEADER "chksm_header"
#define ADDRESS_ORIGIN "addr_o"
#define ADDRESS_DEST "addr_d"

using namespace std;

string hexToString(int num);
string binToString(int num);
int binToDec(string binary);
string getAddress(string binary);

#endif
