#ifndef IPV6_H
#define IPV6_H

#include "ICMPv6.h"

// IPv6 Fields
#define IPV6_VERSION "version"
#define IPV6_CLASS "traffic class"
#define IPV6_FLOW_LABEL "flow label"
#define IPV6_PAYLOAD_LEN "payload length"
#define IPV6_NEXT_HEADER "next header"
#define IPV6_HOP_LIMIT "hop limit"
#define IPV6_SOURCE_ADDRESS "source address"
#define IPV6_DESTINATION_ADDRESS "destination address"

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
  void initField(string field, string representation);
  void showData();
  string getNextHeader();
private:
  int version;
  TrafficClass traffic;
  long long flowLabel;
  unsigned int payloadLength;
  string nextHeader;
  unsigned int hopLimit;
  string originAddress;
  string destinationAddress;
  ICMPv6 icmpv6;
};

#endif
