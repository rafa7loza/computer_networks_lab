#include <iostream>
#include <string>

#include "helpers.h"
#include "Header.h"
#include "IPv4.h"

using namespace std;

int main(){

  int position = 0;
  char fileName[] = "ethernet_ipv4_udp_dns.bin";

  cout << "\n\tReading datagram from: " << fileName << endl << endl;
  string datagram = readPackage(fileName);

  Header header = Header(datagram, &position);
  header.showData();

  if(header.getType() == IPV4_CODE){
    IPv4 ipv4 = IPv4(datagram, &position);
    ipv4.showData();
  }

  cout<<endl;

  return 0;

}
