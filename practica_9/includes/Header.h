#ifndef HEADER_H
#define HEADER_H

// Header Fields
#define ADDRESS_SENDER "address sender"
#define ADDRESS_RECEIVER "address receiver"
#define HEADER_CODE "header code"

// Header Protocol codes
#define ARP_CODE "0806"
#define RARP_CODE "8035"
#define IPV4_CODE "0800"
#define IPV6_CODE "86DD"

using namespace std;

class Header{
public:
  Header();
  Header(string &data, int * position);
  void showData();
  string getType();

private:
  string addressSender;
  string addressReceiver;
  string type;
  int payloadSize;
  void setField(string &data, string field, int * fpos);
};

#endif
