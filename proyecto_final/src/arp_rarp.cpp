#include <iostream>

#include "arp_rarp.h"

using namespace std;

ARP_RARP::ARP_RARP(){}

ARP_RARP::ARP_RARP(string &data, int *fposition){
  setField(data, HARDWARE, fposition);
  setField(data, PROTOCOL_ARP, fposition);
  setField(data, HARDWARE_SIZE, fposition);
  setField(data, PROTOCOL_SIZE, fposition);
  setField(data, OPERATION_CODE, fposition);
  setField(data, HARDWARE_ADDR_SENDER, fposition);
  setField(data, PROTOCOL_ADDR_SENDER, fposition);
  setField(data, HARDWARE_ADDR_RECEIVER, fposition);
  setField(data, PROTOCOL_ADDR_RECEIVER, fposition);
  setField(data, OTHER_DATA_ARP, fposition);
}

void ARP_RARP::setField(string &data, string field, int * fpos){
  string representation;
  if(field == HARDWARE){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    int aux = binToDec(representation);
    switch (aux) {
      case 0:   { this->hardware = "Reserved"; break; }
      case 1:   { this->hardware = "Ethernet (10Mb)"; break; }
      case 2:   { this->hardware = "Experimental Ethernet"; break; }
      case 3:   { this->hardware = "Amateur Radio AX.25"; break; }
      case 4:   { this->hardware = "Proteon ProNET Token Ring"; break; }
      case 5:   { this->hardware = "Chaos"; break; }
      case 6:   { this->hardware = "IEEE 802 Networks"; break; }
      case 7:   { this->hardware = "ARCNET"; break; }
      case 8:   { this->hardware = "Hyperchannel"; break; }
      case 9:   { this->hardware = "Lanstar"; break; }
      case 10:   { this->hardware = "Autonet Short Address"; break; }
      case 11:   { this->hardware = "LocalTalk"; break; }
      case 12:   { this->hardware = "LocalNet (IBM PCNet or SYTEK LocalNET)"; break; }
      case 13:   { this->hardware = "Ultra Link"; break; }
      case 14:   { this->hardware = "SMDS"; break; }
      case 15:   { this->hardware = "Frame Relay"; break; }
      case 16:   { this->hardware = "Asynchronous Transmission Mode (ATM)"; break; }
      case 17:   { this->hardware = "HDLC"; break; }
      case 18:   { this->hardware = "Fibre Channel"; break; }
      case 19:   { this->hardware = "Asynchronous Transmission Mode (ATM)"; break; }
      case 21:   { this->hardware = "Serial Line"; break; }
      case 22:   { this->hardware = "MIL-STD-188-220"; break; }
      case 23:   { this->hardware = "Metricom"; break; }
      case 24:   { this->hardware = "IEEE 1394.1995"; break; }
      case 25:   { this->hardware = "MAPOS"; break; }
      case 26:   { this->hardware = "Twinaxial"; break; }
      case 27:   { this->hardware = "EUI-64"; break; }
      case 28:   { this->hardware = "HIPARP"; break; }
      case 29:   { this->hardware = "IP and ARP over ISO 7816-3"; break; }
      case 30:   { this->hardware = "ARPSec"; break; }
      case 31:   { this->hardware = "IPsec Tunnel"; break; }
      case 32:   { this->hardware = "InfiniBand (TM)"; break; }
      case 33:   { this->hardware = "TIA-102 Project 25 Common Air Interface (CAI)"; break; }
      case 34:   { this->hardware = "Wiegand Interface"; break; }
      case 35:   { this->hardware = "Pure IP"; break; }
      case 36:   { this->hardware = "HW_EXP1"; break; }
      case 37:   { this->hardware = "HFI"; break; }
      case 256:   { this->hardware = "HW_EXP2"; break; }
      case 257:   { this->hardware = "AEthernet"; break; }
      case 65535:   { this->hardware = "Reserved"; break; }
      default:{
        if((aux >= 38 && aux <= 255) || (aux >= 258 && aux <= 65534))
          this->hardware = "Reserved";
      }
    }
  }else if(field == PROTOCOL_ARP){
    representation = data.substr(*fpos, BYTE);
    *fpos += BYTE;
    int a = binToDec(representation);
    representation = data.substr(*fpos, BYTE);
    *fpos += BYTE;
    int b = binToDec(representation);

    string aux = decToHex(a) + decToHex(b);
    if(aux == "0800") this->protocol = "para IPv4";
    else if(aux == "0806") this->protocol = "para ARP";
    else if(aux == "8035") this->protocol = "para RARP";
    else if(aux == "86DD") this->protocol = "para IPv6";
  }else if(field == HARDWARE_SIZE){
    representation = data.substr(*fpos, BYTE);
    *fpos += BYTE;
    this->hardwareAddressSize = binToDec(representation);
  }else if(field == PROTOCOL_SIZE){
    representation = data.substr(*fpos, BYTE);
    *fpos += BYTE;
    this->protocolAddrssSize = binToDec(representation);
  }else if(field == OPERATION_CODE){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    int aux = binToDec(representation);
    switch (aux){
      case 1:   {this->operationCode = "REQUEST";   break;}
      case 2:   {this->operationCode = "REPLY";   break;}
      case 3:   {this->operationCode = "Request Reverse";   break;}
      case 4:   {this->operationCode = "reply Reverse";   break;}
      case 5:   {this->operationCode = "DRARP-Request";   break;}
      case 6:   {this->operationCode = "DRARP-Reply";   break;}
      case 7:   {this->operationCode = "DRARP-Error";   break;}
      case 8:   {this->operationCode = "InARP-Request";   break;}
      case 9:   {this->operationCode = "InARP-Reply";   break;}
      case 10:   {this->operationCode = "ARP-NAK";   break;}
      case 11:   {this->operationCode = "MARS-Request";   break;}
      case 12:   {this->operationCode = "MARS-Multi";   break;}
      case 13:   {this->operationCode = "MARS-MServ";   break;}
      case 14:   {this->operationCode = "MARS-Join";   break;}
      case 15:   {this->operationCode = "MARS-Leave";   break;}
      case 16:   {this->operationCode = "MARS-NAK";   break;}
      case 17:   {this->operationCode = "MARS-Unserv";   break;}
      case 18:   {this->operationCode = "MARS-SJoin";   break;}
      case 19:   {this->operationCode = "MARS-SLeave";   break;}
      case 20:   {this->operationCode = "MARS-GroupList-Request";   break;}
      case 21:   {this->operationCode = "MARS-GroupList-Reply";   break;}
      case 22:   {this->operationCode = "MARS-Redirect-Map";   break;}
      case 23:   {this->operationCode = "MAPOS-UNARP";   break;}
      case 24:   {this->operationCode = "OP-EXP1";   break;}
      case 25:   {this->operationCode = "OP-EXP2";   break;}
      default: {
        if(aux >= 26 && aux <= 65535) this->operationCode = "Unassigned";
        else this->operationCode = "Rerserved";
      }

    }

  }else if(field == HARDWARE_ADDR_RECEIVER){
    representation = data.substr(*fpos, BYTES_6);
    *fpos += BYTES_6;
    this->hardwareAddressReceiver = getMACAddress(representation);
  }else if(field == HARDWARE_ADDR_SENDER){
    representation = data.substr(*fpos, BYTES_6);
    *fpos += BYTES_6;
    this->hardwareAddressSender = getMACAddress(representation);
  }else if(field == PROTOCOL_ADDR_RECEIVER){
    representation = data.substr(*fpos, BYTES_4);
    *fpos += BYTES_4;
    this->protocolAddressReceiver = getIpAddress(representation);
  }else if(field == PROTOCOL_ADDR_SENDER){
    representation = data.substr(*fpos, BYTES_4);
    *fpos += BYTES_4;
    this->protocolAddressSender = getIpAddress(representation);
  }else if(field == OTHER_DATA_ARP){
    this->otherData = data.substr(*fpos);
  }
}

void ARP_RARP::showData(){
  cout << "Hardware: " << this->hardware << endl
    << "Protocol: " << this->protocol << endl
    << "Hardware address size: " << this->hardwareAddressSize << endl
    << "Protocol address size: " << this->protocolAddrssSize << endl
    << "Codigo de operación: " << this->operationCode << endl
    << "Direccion hardware del Emisor: " << this->hardwareAddressSender << endl
    << "Direccion IP del Emisor: " << this->protocolAddressSender << endl
    << "Direccion hardware del Receptor: " << this->hardwareAddressReceiver << endl
    << "Direccion IP del Receptor: " << this->protocolAddressReceiver << endl;
    // << "Datos: " << this->data << endl
    printHexData(this->otherData);
    cout << endl;
}
