#ifndef IPV6_H
#define IPV6_H

#include "ICMPv6.h"

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
