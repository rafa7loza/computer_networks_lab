#ifndef HELPERS_H
#define HELPERS_H

#define BITS_3 3
#define BITS_4 4
#define BITS_13 13
#define BYTE 8
#define BYTES_2 16
#define BYTES_4 32
#define BYTES_6 48


#define HARDWARE "hardware"
#define PROTOCOL "protocol"
#define HARDWARE_SIZE "hardwareAddressSize"
#define PROTOCOL_SIZE "protocolAddrssSize"
#define OPERATION_CODE "operationCode"
#define HARDWARE_ADDR_RECEIVER "hardwareAddressReceiver"
#define HARDWARE_ADDR_SENDER "hardwareAddressSender"
#define PROTOCOL_ADDR_RECEIVER "protocolAddressReceiver"
#define PROTOCOL_ADDR_SENDER "protocolAddressSender"

#include <iostream>

using namespace std;

string hexToString(int num);
string binToString(int num);
int binToDec(string binary);
string getIpAddress(string binary);
string getMACAddress(string binary);



#endif
