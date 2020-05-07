#ifndef IPV4_H
#define IPV4_H

#include "ICMPv4.h"

// IPv4 Protocol
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
#define ICMP "ICMPv4"

using namespace std;

struct service{
  string priority;
  string retard;
  string performance;
  string reliavility;
};

class IPv4{
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
  ICMPv4 icmpv4;
  void setField(string &data, string field, int * fpos);
public:
  IPv4();
  IPv4(string &data, int *fposition);
  void showData();
  string getProtocol();
};

#endif
