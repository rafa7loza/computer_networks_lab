#include <iostream>
#include <string>
// #include <unistd.h>
// #include <fcntl.h>
// #include <stdlib.h>
// #include <sys/types.h>
// #include <sys/stat.h>

#include "helpers.h"
#include "IPv6.h"
#include "ICMPv6.h"
#include "Header.h"

using namespace std;

void setField(IPv6 *obj,  string field, string block, int &position, int bits);
string readPackage(char * fileName);

int main(){

  int position = 0;
  char fileName[] = "ipv6_icmpv6_destination_unreachable.bin";

  cout << "\n\tReading datagram from: " << fileName << endl << endl;
  string datagram = readPackage(fileName);

  // cout << datagram << endl;

  Header header = Header(datagram, &position);
  header.showData();

  if(header.getType() == IPV6_CODE){
    IPv6 ipv6;
    setField(&ipv6, IPV6_VERSION, datagram, position, BITS_4);
    setField(&ipv6, IPV6_CLASS, datagram, position, BYTE);
    setField(&ipv6, IPV6_FLOW_LABEL, datagram, position, BITS_20);
    setField(&ipv6, IPV6_PAYLOAD_LEN, datagram, position, BYTES_2);
    setField(&ipv6, IPV6_NEXT_HEADER, datagram, position, BYTE);
    setField(&ipv6, IPV6_HOP_LIMIT, datagram, position, BYTE);
    setField(&ipv6, IPV6_SOURCE_ADDRESS, datagram, position, BYTES_16);
    setField(&ipv6, IPV6_DESTINATION_ADDRESS, datagram, position, BYTES_16);

    if(ipv6.getNextHeader() == ICMPV6){
      ipv6.initField(ICMPV6, datagram.substr(position));
    }

    ipv6.showData();

  }

  cout<<endl;

  return 0;

}

void setField(IPv6 *obj,  string field, string block, int &position, int bits){
  obj->initField(field, block.substr(position, bits));
  position += bits;
}

string readPackage(char * fileName){
  int fileDescription, fsize, i;
  unsigned char * bfr;
  string datagram;

  fileDescription = open_file(fileName);
  fsize = getFileSize(fileDescription);
  bfr = new unsigned char[fsize];
  read(fileDescription, bfr, fsize);
  close(fileDescription);

  for(i=0; i<fsize; ++i)
    datagram += decToBin(bfr[i]);

  return datagram;
}
