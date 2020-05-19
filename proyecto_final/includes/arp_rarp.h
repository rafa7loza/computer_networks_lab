#ifndef ARP_RARP_H
#define ARP_RARP_H

#include "helpers.h"

#define HARDWARE "hardware"
#define PROTOCOL_ARP "protocol"
#define HARDWARE_SIZE "hardwareAddressSize"
#define PROTOCOL_SIZE "protocolAddrssSize"
#define OPERATION_CODE "operationCode"
#define HARDWARE_ADDR_RECEIVER "hardwareAddressReceiver"
#define HARDWARE_ADDR_SENDER "hardwareAddressSender"
#define PROTOCOL_ADDR_RECEIVER "protocolAddressReceiver"
#define PROTOCOL_ADDR_SENDER "protocolAddressSender"
#define OTHER_DATA_ARP "other data"

using namespace std;

class ARP_RARP{
public:
  ARP_RARP();
  ARP_RARP(string &data, int * fposition);
  void setField(string &data, string field, int * fpos);
  void showData();

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
  string otherData;
};

#endif
