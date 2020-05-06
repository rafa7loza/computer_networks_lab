#ifndef ICMPV4_H
#define ICMPV4_H

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
