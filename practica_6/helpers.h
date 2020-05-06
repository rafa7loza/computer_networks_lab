#ifndef HELPERS_H
#define HELPERS_H

#define BITS_3 3
#define BITS_4 4
#define BITS_13 13
#define BITS_20 20
#define BYTE 8
#define BYTES_2 16
#define BYTES_4 32
#define BYTES_6 48
#define BYTES_16 128


#define HARDWARE "hardware"
#define PROTOCOL "protocol"
#define HARDWARE_SIZE "hardwareAddressSize"
#define PROTOCOL_SIZE "protocolAddrssSize"
#define OPERATION_CODE "operationCode"
#define HARDWARE_ADDR_RECEIVER "hardwareAddressReceiver"
#define HARDWARE_ADDR_SENDER "hardwareAddressSender"
#define PROTOCOL_ADDR_RECEIVER "protocolAddressReceiver"
#define PROTOCOL_ADDR_SENDER "protocolAddressSender"

#define ARP_CODE "0806"
#define RARP_CODE "8035"
#define IPV4_CODE "0800"
#define IPV6_CODE "86DD"

// IPv6 Fields

#define IPV6_VERSION "version"
#define IPV6_CLASS "traffic class"
#define IPV6_FLOW_LABEL "flow label"
#define IPV6_PAYLOAD_LEN "payload length"
#define IPV6_NEXT_HEADER "next header"
#define IPV6_HOP_LIMIT "hop limit"
#define IPV6_SOURCE_ADDRESS "source address"
#define IPV6_DESTINATION_ADDRESS "destination address"

// ICMPv6 Fields

#define ICMPV6_TYPE "icmpv6 data"
#define ICMPV6_CODE "icmpv6 code"
#define ICMPV6_CHECKSUM "icmpv6 checksum"
#define ICMPV6_OTHER "icmpv6 other"
#define ICMPV6 "ICMPv6"

#define debug(s) cout << " ** Debug: " << s << " **" << endl;

using namespace std;

string hexToString(int num);
string binToString(int num);
int binToDec(string binary);
string getIpAddress(string binary);
string getMACAddress(string binary);
string getIPv6Address(string binary);


#endif
