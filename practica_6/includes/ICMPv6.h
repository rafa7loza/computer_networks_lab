#ifndef ICMPV6_H
#define ICMPV6_H

using namespace std;

// ICMPv6 Fields
#define ICMPV6_TYPE "icmpv6 data"
#define ICMPV6_CODE "icmpv6 code"
#define ICMPV6_CHECKSUM "icmpv6 checksum"
#define ICMPV6_OTHER "icmpv6 other"
#define ICMPV6 "ICMPv6"

class ICMPv6{

public:
  ICMPv6();
  ICMPv6(string data);
  void showData();

private:
  string type;
  int typeCode;
  string error;
  int typeError;
  string checkSum;
  string otherData;
  void initField(string field, string representation);
};

#endif
