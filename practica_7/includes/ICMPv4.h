#ifndef ICMPV4_H
#define ICMPV4_H

#include <iostream>
#include <string>

// ICMPv4 Protocol
#define ICMPV4_TYPE "icmpv4_type"
#define ICMPV4_CODE "icmpv4_code"
#define ICMPV4_CHECKSUM "icmpv4_checksum"
#define ICMPV4_OTHER "icmpv4_other"

using namespace std;

class ICMPv4{
public:
  ICMPv4();
  ICMPv4(string data);
  void showData();

private:
  string type;
  int errorCode;
  string checksum;
  string otherFields;
  void initField(string field, string representation);
};

#endif
