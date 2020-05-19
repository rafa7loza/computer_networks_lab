#include <iostream>
#include <string>

#include "helpers.h"
#include "Header.h"
#include "IPv4.h"
#include "IPv6.h"
#include "arp_rarp.h"

using namespace std;

int main(int argc, char * argv[]){

  int position = 0;

  if(argc < 1){
    cout << "No se ha especificado el archivo con el que desea trabajar." << endl;
    return 1;
  }

  char * fileName = argv[1];
  // char fileName[] = "paquetes_redes/ethernet_arp_reply.bin";

  cout << "\n\tReading datagram from: " << fileName << endl << endl;
  string datagram = readPackage(fileName);

  Header header = Header(datagram, &position);
  header.showData();

  if(header.getType() == IPV4_CODE){
    IPv4 ipv4 = IPv4(datagram, &position);
    ipv4.showData();
  }else if(header.getType() == IPV6_CODE){
    IPv6 ipv6 = IPv6(datagram, &position);
    ipv6.showData();
  }else if(header.getType() == RARP_CODE || header.getType() == ARP_CODE){
    ARP_RARP arp_rarp = ARP_RARP(datagram, &position);
    arp_rarp.showData();
  }

  cout<<endl;

  return 0;

}
