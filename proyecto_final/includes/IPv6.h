#ifndef IPV6_H
#define IPV6_H

#include "helpers.h"

#define IPV6_VERSION "version"
#define IPV6_CLASS "traffic class"
#define IPV6_FLOW_LABEL "flow label"
#define IPV6_PAYLOAD_LEN "payload length"
#define IPV6_NEXT_HEADER "next header"
#define IPV6_HOP_LIMIT "hop limit"
#define IPV6_SOURCE_ADDRESS "source address"
#define IPV6_DESTINATION_ADDRESS "destination address"
#define IPV6_OTHER_DATA "ipv6 other data"
using namespace std;

struct TrafficClass{
  string priority;
  string retard;
  string performance;
  string reliavility;
};

class IPv6{
public:
  IPv6();
  IPv6(string &data, int * position);
  void setField(string &data, string field, int * fpos);
  void showData();
private:
  int version;
  TrafficClass traffic;
  long long flowLabel;
  unsigned int payloadLength;
  string nextHeader;
  unsigned int hopLimit;
  string originAddress;
  string destinationAddress;
  string otherData;
};

#endif
