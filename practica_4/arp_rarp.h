#ifndef ARP_RARP_H
#define ARP_RARP_H

// #include <iostream>

// #include "helpers.h"

using namespace std;

class ARP_RARP{
public:
  ARP_RARP();
  void initField(string field, string representation);
  void showData();
  int getHardwareSize();
  int getProtocolSize();

private:
  string hardware;
  string protocol;
  int hardwareAddressSize;
  int protocolAddrssSize;
  string operationCode;
  string hardwareAddressReceiver;
  string hardwareAddressSender;
  string protocolAddressSender;
  string protocolAddressReceiver;
  string data;
};

#endif
