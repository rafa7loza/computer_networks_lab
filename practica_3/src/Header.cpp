#include <iostream>

#include "Header.h"
#include "helpers.h"

Header::Header(){}

Header::Header(string &data, int * position){

  setField(data, ADDRESS_RECEIVER, position);
  setField(data, ADDRESS_SENDER, position);
  setField(data, HEADER_CODE, position);
  this->payloadSize = data.substr(*position).length();
}

void Header::setField(string &data, string field, int * fposition){
  if(field == ADDRESS_SENDER){
    string block = data.substr(*fposition, BYTES_6);
    *fposition += BYTES_6;
    this->addressSender = getMACAddress(block);
  }else if(field == ADDRESS_RECEIVER){
    string block = data.substr(*fposition, BYTES_6);
    *fposition += BYTES_6;
    this->addressReceiver = getMACAddress(block);
  }else if(field == HEADER_CODE){
    // string code = binToHex(data.substr(*fposition, BYTE))+binToHex(data.substr(*fposition+BYTE, BYTE));
    // if(code == "0800") this->type = "IPv4";
    // else if(code == "0806") this->type = "ARP";
    // else if(code == "8035") this->type = "RARP";
    // else if(code == "86DD") this->type = "IPv6";
    this->type = binToHex(data.substr(*fposition, BYTE))+binToHex(data.substr(*fposition+BYTE, BYTE));
    *fposition += BYTES_2;
  }
}

void Header::showData(){

  cout << "Dirección de destino:\t" << this->addressReceiver << endl
    << "Dirección de origen:\t" << this->addressSender << endl
    << "Código:\t\t\t"<< this->type << endl
    << "Tamaño del datagrama:\t" << this->payloadSize << " bytes" << endl
    << endl;
}

string Header::getType(){
  return this->type;
}
