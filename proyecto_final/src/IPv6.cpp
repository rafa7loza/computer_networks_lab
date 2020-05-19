#include <iostream>

#include "IPv6.h"

IPv6::IPv6(){}

IPv6::IPv6(string &data, int * position){
  setField(data, IPV6_VERSION, position);
  setField(data, IPV6_CLASS, position);
  setField(data, IPV6_FLOW_LABEL, position);
  setField(data, IPV6_PAYLOAD_LEN, position);
  setField(data, IPV6_NEXT_HEADER, position);
  setField(data, IPV6_HOP_LIMIT, position);
  setField(data, IPV6_SOURCE_ADDRESS, position);
  setField(data, IPV6_DESTINATION_ADDRESS, position);
}

void IPv6::setField(string &data, string field, int * fpos){
  string representation;
  if(field == IPV6_VERSION){
    representation = data.substr(*fpos, BITS_4);
    *fpos += BITS_4;
    this->version = binToDec(representation);
  }else if(field == IPV6_CLASS){
    representation = data.substr(*fpos, BYTE);
    *fpos += BYTE;
    string priority = representation.substr(5);
    if(priority == "000") this->traffic.priority = "De rutina";
    else if(priority == "001") this->traffic.priority = "Prioritario";
    else if(priority == "010") this->traffic.priority = "Inmediato";
    else if(priority == "011") this->traffic.priority = "Relampago";
    else if(priority == "100") this->traffic.priority = "Invalidacion Relampago";
    else if(priority == "101") this->traffic.priority = "Procesando llamada critica y de emergencia";
    else if(priority == "110") this->traffic.priority = "Control de trabajo de Internet";
    else if(priority == "111") this->traffic.priority = "Control de red";

    if(representation[4] == '1') this->traffic.retard = "bajo";
    else this->traffic.retard = "normal";

    if(representation[3] == '1') this->traffic.performance = "alto";
    else this->traffic.performance = "normal";

    if(representation[2] == '1') this->traffic.reliavility = "alto";
    else this->traffic.reliavility = "normal";
  }else if(field == IPV6_FLOW_LABEL){
    representation = data.substr(*fpos, BITS_20);
    *fpos += BITS_20;
    this->flowLabel = binToDec(representation);
  }else if(field == IPV6_PAYLOAD_LEN){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->payloadLength = binToDec(representation);
  }else if(field == IPV6_NEXT_HEADER){
    representation = data.substr(*fpos, BYTE);
    *fpos += BYTE;
    int aux = binToDec(representation);

    switch (aux) {
      case 1: { this->nextHeader = "ICMPv4"; break;}
      case 2: { this->nextHeader = "IGMP"; break;}
      case 3: { this->nextHeader = "GGP"; break;}
      case 4: { this->nextHeader = "IP"; break;}
      case 5: { this->nextHeader = "ST"; break;}
      case 6: { this->nextHeader = "TCP"; break;}
      case 7: { this->nextHeader = "CBT"; break;}
      case 8: { this->nextHeader = "EGP"; break;}
      case 9: { this->nextHeader = "IGP"; break;}
      case 10: { this->nextHeader = "BBN-RCC-MON"; break;}
      case 17: { this->nextHeader = "UDP"; break;}
      case 18: { this->nextHeader = "MUX"; break;}
      case 27: { this->nextHeader = "RDP"; break;}
      case 28: { this->nextHeader = "IRTP"; break;}
      case 45: { this->nextHeader = "IDRP"; break;}
      case 46: { this->nextHeader = "RSVP"; break;}
      case 47: { this->nextHeader = "GRE"; break;}
      case 48: { this->nextHeader = "MHRP"; break;}
      case 50: { this->nextHeader = "ESP"; break;}
      case 51: { this->nextHeader = "AH"; break;}
      case 54: { this->nextHeader = "NARP"; break;}
      case 55: { this->nextHeader = "MOBILE"; break;}
      case 58: { this->nextHeader = "ICMPv6"; break;}
      case 88: { this->nextHeader = "EIGRP"; break;}
      case 89: { this->nextHeader = "OSPF"; break;}
      case 94: { this->nextHeader = "IPIP"; break;}
      case 95: { this->nextHeader = "MICP"; break;}
      case 97: { this->nextHeader = "ETHERIP"; break;}
      case 98: { this->nextHeader = "ENCAP"; break;}
      case 103: { this->nextHeader = "PIM"; break;}
      case 112: { this->nextHeader = "VRRP"; break;}
      case 113: { this->nextHeader = "PGM"; break;}
      case 116: { this->nextHeader = "L2TP"; break;}
      case 118: { this->nextHeader = "STP"; break;}
      case 121: { this->nextHeader = "SMP"; break;}
      case 131: { this->nextHeader = "PIPE"; break;}
      case 132: { this->nextHeader = "SCTP"; break;}
      case 133: { this->nextHeader = "FC"; break;}
      case 137: { this->nextHeader = "MPLS-in-IP"; break;}
      case 139: { this->nextHeader = "HIP"; break;}
    }
  }else if(field == IPV6_HOP_LIMIT){
    representation = data.substr(*fpos, BYTE);
    *fpos += BYTE;
    this->hopLimit = binToDec(representation);
  }else if(field == IPV6_SOURCE_ADDRESS){
    representation = data.substr(*fpos, BYTES_16);
    *fpos += BYTES_16;
    this->originAddress = getIPv6Address(representation);
  }else if(field == IPV6_DESTINATION_ADDRESS){
    representation = data.substr(*fpos, BYTES_16);
    *fpos += BYTES_16;
    this->destinationAddress = getIPv6Address(representation);
  }else if(field == IPV6_OTHER_DATA){
    this->otherData = data.substr(*fpos);
  }
}

void IPv6::showData(){
  cout << "Version: " << this->version << endl
    << "Traffic Class: { Prioridad: " << this->traffic.priority
    << ", Retardo: " << this->traffic.retard
    << ", Performance: " << this->traffic.performance
    << ", Fiabilidad: " << this->traffic.reliavility << " }" << endl
    << "Tipo de flujo: " << this->flowLabel << endl
    << "Tamaño de datos: " << this->payloadLength << endl
    << "Encabezado siguiente: " << this->nextHeader << endl
    << "Límite de salto: " << this->hopLimit << endl
    << "Dirección IP de origen: " << this->originAddress << endl
    << "Dirección IP de destino: " << this->destinationAddress << endl
    printHexData(this->otherData);
    cout << endl;
}
