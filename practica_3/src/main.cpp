#include <iostream>
#include <string>

#include "helpers.h"
#include "Header.h"
#include "IPv4_datagram.h"

using namespace std;

void setField(IPv4_datagram *obj,  string field, string block, int &position, int bits);

int main(){

  int position = 0;
  char fileName[] = "ethernet_ipv4_icmp_redirect.bin";

  cout << "\n\tReading datagram from: " << fileName << endl << endl;
  string datagram = readPackage(fileName);

  Header header = Header(datagram, &position);
  header.showData();

  if(header.getType() == IPV4_CODE){
    IPv4_datagram ipv4;
    setField(&ipv4, VERSION, datagram, position, BITS_4);
    setField(&ipv4, HEADER_LENGTH, datagram, position, BITS_4);
    setField(&ipv4, SERVICE_TYPE, datagram, position, BYTE);
    setField(&ipv4, TOTAL_LENGTH, datagram, position, BYTES_2);
    setField(&ipv4, IDENTIFIER, datagram, position, BYTES_2);
    setField(&ipv4, FLAGS, datagram, position, BITS_3);
    setField(&ipv4, FRAGMENT_POSITION, datagram, position, BITS_13);
    setField(&ipv4, TTL, datagram, position, BYTE);
    setField(&ipv4, PROTOCOL, datagram, position, BYTE);
    setField(&ipv4, CHECKSUM_HEADER, datagram, position, BYTES_2);
    setField(&ipv4, ADDRESS_ORIGIN, datagram, position, BYTES_4);
    setField(&ipv4, ADDRESS_DEST, datagram, position, BYTES_4);

    if(ipv4.getProtocol() == ICMP){
      ipv4.initField(ICMP, datagram.substr(position));
    }

    ipv4.showData();
  }

  cout<<endl;

  return 0;

}

void setField(IPv4_datagram *obj,  string field, string block, int &position, int bits){
  obj->initField(field, block.substr(position, bits));
  position += bits;
}
