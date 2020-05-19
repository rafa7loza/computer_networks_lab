#include <iostream>
#include <string>

#include "helpers.h"
#include "Header.h"
#include "IPv4.h"
#include "IPv6.h"

using namespace std;

int main(){

  int position = 0;
  char fileName[] = "paquetes_redes/ipv6_icmpv6_destination_unreachable.bin";

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
  }

  cout<<endl;

  return 0;

}
