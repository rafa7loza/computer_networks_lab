#include <iostream>
#include <fstream>
#include <string>

#include "helpers.h"
#include "IPv6.h"

using namespace std;

void setField(IPv6 *obj,  string field, string block, int &position, int bits);

int main(){

  char ch;
  string type="";
  int number, byte;
  string fileName = "ethernet_ipv6_nd.bin";

  IPv6 ipv6;
  int position = 0;

  ifstream file(fileName,ios::binary | ios::in);

  string datagram;

  if(file.is_open()){

    cout << "\n\n\t\tAnálisis de un paquete ARP/RARP" << endl;
    cout<<"\nNombre Archivo Abierto: "<<fileName<<endl;

    byte = 0;
    while(file.get(ch)){
      number = ch;
      if(number < 0) number += 256;
      if(byte >= 14) datagram += binToString(number);


      if(byte == 0)
      cout << "\nDireccion de destino: ";
      else if(byte == 6)
      cout << "\nDireccion de origen: ";
      else if(byte == 12){
        cout << "\nTipo: ";
        type += hexToString(number);
      }else if(byte == 14){
        cout << "\nDatos: ";
      }

      cout << hexToString(number);

      if(byte != 5 && byte != 11 && byte != 13) cout << "-";

      if(byte == 13){
        type += hexToString(number);

        if(type == "0800") cout << ": IPv4";
        else if(type == "0806") cout << ": ARP";
        else if(type == "8035") cout << ": RARP";
        else if(type == "86DD") cout << ": IPv6";
      }

      ++byte;
    }

    file.close();

  }

  cout << endl << endl;

  if(type == IPV6_CODE){
    setField(&ipv6, IPV6_VERSION, datagram, position, BITS_4);
    setField(&ipv6, IPV6_CLASS, datagram, position, BYTE);
    setField(&ipv6, IPV6_FLOW_LABEL, datagram, position, BITS_20);
    setField(&ipv6, IPV6_PAYLOAD_LEN, datagram, position, BYTES_2);
    setField(&ipv6, IPV6_NEXT_HEADER, datagram, position, BYTE);
    setField(&ipv6, IPV6_HOP_LIMIT, datagram, position, BYTE);
    setField(&ipv6, IPV6_SOURCE_ADDRESS, datagram, position, BYTES_16);
    setField(&ipv6, IPV6_DESTINATION_ADDRESS, datagram, position, BYTES_16);

    ipv6.showData();

  }



  cout<<endl;

  return 0;

}

void setField(IPv6 *obj,  string field, string block, int &position, int bits){
  obj->initField(field, block.substr(position, bits));
  position += bits;
}
