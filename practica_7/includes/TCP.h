#ifndef TCP_H
#define TCP_H

#include "helpers.h"

#define ORIGIN_PORT "origin port"
#define DESTINATION_PORT "destination port"
#define SEQ_NUM "sequence number"
#define ACK "acuse de recibo"
#define HEADER_LENGTH_TCP "tam cabecera tcp"
#define RESERVED "reserved"
#define FLAGS_TCP "flags tcp"
#define WINDOW_LENGTH "window length"
#define CHECKSUM_TCP "checksum tcp"
#define URGENT_POINTER "urgent pointer"
#define OTHER_CONTENT "other content"

using namespace std;

class TCP{
private:
  int fposition;
  int originPort;
  int destinationPort;
  unsigned int sequenceNum;
  unsigned int ack;
  int headerLength;
  string reserved;
  bool flags[BITS_9];
  unsigned int wlength;
  string checksum;
  unsigned urgentPointer;
  string otherContent;
public:
  TCP();
  TCP(string &data);
  void setField(string &data, string field, int *fpos);
  void showData();
};

#endif
