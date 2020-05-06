#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <pthread.h>
#include <unistd.h>

#include "helpers.h"
#include "IPv4_datagram.h"

using namespace std;

void setField(IPv4_datagram *obj,  string field, string block, int &position, int bits);

int main(){

  char ch;
  string type="";
  int number, byte;
  int fileSize;
  string fileName = "ethernet_ipv4_icmp_ttl.bin";

  // Information about the IPv4 datagram
  IPv4_datagram ipv4;
  int position = 0;

  ifstream file(fileName,ios::binary | ios::in);

  file.seekg(0, ios::end);
  fileSize = int(file.tellg());
  file.seekg(0, ios::beg);

  string datagram;

  if(file.is_open()){

    cout << "\t\tAnálisis de un paquete Ethernet IPv4" << endl;
    cout<<"Nombre Archivo Abierto: "<<fileName<<endl<<endl;

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

      if(byte != 5 && byte != 11 && byte != 13 && byte != fileSize-1) cout << "-";

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
  // cout << "Full binary datagram: " << datagram << endl;

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

  ipv4.showData();

  cout<<endl;

  return 0;

}

void setField(IPv4_datagram *obj,  string field, string block, int &position, int bits){
  obj->initField(field, block.substr(position, bits));
  // cout << block.substr(position, bits) << ";" << endl;
  position += bits;
}
