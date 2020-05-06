#ifndef ICMPV6_H
#define ICMPV6_H

using namespace std;

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
