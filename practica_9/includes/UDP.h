#ifndef UDP_H
#define UDP_H

#include "helpers.h"

#define ORIGIN_PORT_UDP "origin port"
#define DESTINATION_PORT_UDP "destination port"
#define TOTAL_LENGHT "total length"
#define CHECKSUM_UDP "checksum udp"
#define OTHER_DATA "other data"

using namespace std;

class UDP{
private:
  int fposition;
  unsigned int originPort;
  unsigned int destinationPort;
  string length;
  string checksum;
  string otherData;

public:
  UDP();
  UDP(string &data);
  void setField(string &data, string field, int *fpos);
  void showData();
};

#endif
