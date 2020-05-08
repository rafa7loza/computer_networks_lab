#ifndef DNS_H
#define DNS_H

#include "helpers.h"

#define ONE '1'

#define ID_DNS "id dns"
#define FLAGS_DNS "flags dns"
// #define
// #define
// #define
// #define
// #define

using namespace std;

struct Flags{
  bool qr;      // 1 bit
  int opCode;   // 4 bits
  bool authAns; // 1 bit
  bool tc;      // 1 bit
  bool rd;      // 1 bit
  bool ra;      // 1 bit
  string z;     // 3 bits
  int rCode;    // 4 bits
};

class DNS{
private:
  unsigned int id;
  Flags flags;

public:
  DNS();
  DNS(string &data);
  void setField(string &data, string field, int * fpos);
  void showData();
};

#endif
