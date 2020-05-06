#ifndef IPV4_DATAGRAM_H
#define IPV4_DATAGRAM_H

// #include <iostream>

using namespace std;

struct service{
  string priority;
  string retard;
  string performance;
  string reliavility;
};

class IPv4_datagram{
private:
  string version;
  int headerLength;
  service serviceType;
  int totalLength;
  int id;
  string flags;
  int position;
  int ttl;
  string protocol;
  string checksumHeader;
  string originAddress;
  string objectiveAddress;

public:
  IPv4_datagram();
  void initField(string field, string representation);
  void showData();
};

#endif
