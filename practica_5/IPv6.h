#ifndef IPV6_H
#define IPV6_H

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
private:
  int version;
  TrafficClass traffic;
  long long flowLabel;
  unsigned int payloadLength;
  string nextHeader;
  unsigned int hopLimit;
  string originAddress;
  string destinationAddress;
};

#endif
