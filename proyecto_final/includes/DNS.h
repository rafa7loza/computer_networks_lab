#ifndef DNS_H
#define DNS_H

#include "helpers.h"
#include "QueryDNS.h"
#include "ResponseDNS.h"

#define ZERO '0'

#define ID_DNS "id dns"
#define FLAGS_DNS "flags dns"
#define QD_COUNT "qd count"
#define AN_COUNT "an count"
#define NS_COUNT "ns count"
#define AR_COUNT "ar count"
#define OTHER_DATA_DNS "other data dns"

using namespace std;

struct Flags{
  bool qr;      // 1 bit
  int opCode;   // 4 bits
  bool authAns; // 1 bit
  bool tc;      // 1 bit
  bool rd;      // 1 bit
  bool ra;      // 1 bit
  bool z;       // 1 bits
  bool ad;      // 1 bits
  bool cd;      // 1 bits
  int rCode;    // 4 bits
};

class DNS{
private:
  int fposition=0;
  unsigned int id;
  Flags flags;
  unsigned int qdCount;
  unsigned int anCount;
  unsigned int nsCount;
  unsigned int arCount;
  string otherData;
  void * payload;

public:
  DNS();
  DNS(string &data);
  void setField(string &data, string field, int * fpos);
  void showData();
};

#endif
