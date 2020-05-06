#include <iostream>
#include <string>

#include "IPv4_datagram.h"
#include "helpers.h"

using namespace std;

IPv4_datagram::IPv4_datagram(){}

void IPv4_datagram::initField(string field, string representation){
  if(field == HEADER_LENGTH){
    this->headerLength = (binToDec(representation) * 32) / 8;
  }else if(field == VERSION){
    if(representation == "0100") this->version = "IPv4";
    else this->version = "IPv6";
  }else if(field == SERVICE_TYPE){
    string priority = representation.substr(5);

    if(priority == "000") this->serviceType.priority = "De rutina";
    else if(priority == "001") this->serviceType.priority = "Prioritario";
    else if(priority == "010") this->serviceType.priority = "Inmediato";
    else if(priority == "011") this->serviceType.priority = "Relampago";
    else if(priority == "100") this->serviceType.priority = "Invalidacion Relampago";
    else if(priority == "101") this->serviceType.priority = "Procesando llamada critica y de emergencia";
    else if(priority == "110") this->serviceType.priority = "Control de trabajo de Internet";
    else if(priority == "111") this->serviceType.priority = "Control de red";

    if(representation[4] == '1') this->serviceType.retard = "bajo";
    else this->serviceType.retard = "normal";

    if(representation[3] == '1') this->serviceType.performance = "alto";
    else this->serviceType.performance = "normal";

    if(representation[2] == '1') this->serviceType.reliavility = "alto";
    else this->serviceType.reliavility = "normal";
  }else if(field == TOTAL_LENGTH){
    this->totalLength = binToDec(representation);
  }else if(field == IDENTIFIER){
    this->id = binToDec(representation);
  }else if(field == FLAGS){
    if(representation[1] == '1') this->flags = "No divisible, ";
    else this->flags = "Divisible, ";

    if(representation[0] == '1') this->flags += "Fragmento intermedio";
    else this->flags += "Ultimo fragmento";
  }else if(field == FRAGMENT_POSITION){
    this->position = binToDec(representation);
  }else if(field == TTL){
    this->ttl = binToDec(representation);
  }else if(field == PROTOCOL){
    int aux = binToDec(representation);
    switch (aux) {
      case 1: { this->protocol = "ICMPv4"; break;}
      case 2: { this->protocol = "IGMP"; break;}
      case 3: { this->protocol = "GGP"; break;}
      case 4: { this->protocol = "IP"; break;}
      case 5: { this->protocol = "ST"; break;}
      case 6: { this->protocol = "TCP"; break;}
      case 7: { this->protocol = "CBT"; break;}
      case 8: { this->protocol = "EGP"; break;}
      case 9: { this->protocol = "IGP"; break;}
      case 10: { this->protocol = "BBN-RCC-MON"; break;}
      case 17: { this->protocol = "UDP"; break;}
      case 18: { this->protocol = "MUX"; break;}
      case 27: { this->protocol = "RDP"; break;}
      case 28: { this->protocol = "IRTP"; break;}
      case 45: { this->protocol = "IDRP"; break;}
      case 46: { this->protocol = "RSVP"; break;}
      case 47: { this->protocol = "GRE"; break;}
      case 48: { this->protocol = "MHRP"; break;}
      case 50: { this->protocol = "ESP"; break;}
      case 51: { this->protocol = "AH"; break;}
      case 54: { this->protocol = "NARP"; break;}
      case 55: { this->protocol = "MOBILE"; break;}
      case 88: { this->protocol = "EIGRP"; break;}
      case 89: { this->protocol = "OSPF"; break;}
      case 94: { this->protocol = "IPIP"; break;}
      case 95: { this->protocol = "MICP"; break;}
      case 97: { this->protocol = "ETHERIP"; break;}
      case 98: { this->protocol = "ENCAP"; break;}
      case 103: { this->protocol = "PIM"; break;}
      case 112: { this->protocol = "VRRP"; break;}
      case 113: { this->protocol = "PGM"; break;}
      case 116: { this->protocol = "L2TP"; break;}
      case 118: { this->protocol = "STP"; break;}
      case 121: { this->protocol = "SMP"; break;}
      case 131: { this->protocol = "PIPE"; break;}
      case 132: { this->protocol = "SCTP"; break;}
      case 133: { this->protocol = "FC"; break;}
      case 137: { this->protocol = "MPLS-in-IP"; break;}
      case 139: { this->protocol = "HIP"; break;}
    }
  }else if(field == CHECKSUM_HEADER){
    this->checksumHeader = hexToString(binToDec(representation));
  }else if(field == ADDRESS_ORIGIN){
    this->originAddress = getAddress(representation);
  }else if(field == ADDRESS_DEST){
    this->objectiveAddress = getAddress(representation);
  }

}

void IPv4_datagram::showData(){
  cout << "\tInformación del datagrama " << this->version <<": " << endl << endl;
  cout << "Tamanio de la cabecera: " << this->headerLength << " bytes" << endl
    << "Tipo de servicio: { Prioridad: " << this->serviceType.priority
    << ", Retardo: " << this->serviceType.retard
    << ", Performance: " << this->serviceType.performance
    << ", Fiabilidad: " << this->serviceType.reliavility << " }" << endl
    << "Tamanio total: " << this->totalLength << endl
    << "Identificador: " << this->id << endl
    << "Banderas: " << this->flags << endl
    << "Posicion de fragmento: " << this->position << endl
    << "TTL: " << this->ttl << endl
    << "Protocol: " << this->protocol << endl
    << "Header Checksum: " << this->checksumHeader << endl
    << "Direccion IP de origen: " << this->originAddress << endl
    << "Direccion IP de destino: " << this->objectiveAddress << endl
    << endl;
}
