#include <iostream>
#include <fstream>
#include <string>

#include "helpers.h"
#include "arp_rarp.h"

using namespace std;

void setField(ARP_RARP *obj,  string field, string block, int &position, int bits);

int main(){

  char ch;
  string type="";
  int number, byte;
  string fileName = "ethernet_arp_reply.bin";

  ARP_RARP arp_rarp;
  int position = 0;

  ifstream file(fileName,ios::binary | ios::in);

  string datagram;

  if(file.is_open()){

    cout << "\t\tAnálisis de un paquete ARP/RARP" << endl;
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

  setField(&arp_rarp, HARDWARE, datagram, position, BYTES_2);
  setField(&arp_rarp, PROTOCOL, datagram, position, BYTES_2);
  setField(&arp_rarp, HARDWARE_SIZE, datagram, position, BYTE);
  setField(&arp_rarp, PROTOCOL_SIZE, datagram, position, BYTE);
  setField(&arp_rarp, OPERATION_CODE, datagram, position, BYTES_2);
  setField(&arp_rarp, HARDWARE_ADDR_SENDER, datagram, position, BYTES_6);
  setField(&arp_rarp, PROTOCOL_ADDR_SENDER, datagram, position, BYTES_4);
  setField(&arp_rarp, HARDWARE_ADDR_RECEIVER, datagram, position, BYTES_6);
  setField(&arp_rarp, PROTOCOL_ADDR_RECEIVER, datagram, position, BYTES_4);
  setField(&arp_rarp, "relleno", datagram, position, datagram.length() - position);


  arp_rarp.showData();

  cout<<endl;

  return 0;

}

void setField(ARP_RARP *obj,  string field, string block, int &position, int bits){
  obj->initField(field, block.substr(position, bits));
  position += bits;
}
