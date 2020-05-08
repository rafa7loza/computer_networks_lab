#include "QueryDNS.h"

QueryDNS::QueryDNS(){}

QueryDNS::QueryDNS(string &data){
  this->fposition = 0;
  setField(data, DOMAIN_NAME, &this->fposition);
  setField(data, TYPE_QUERY, &this->fposition);
  setField(data, CLASS_DNS, &this->fposition);
}

void QueryDNS::setField(string &data, string field, int *fpos){
  if(field == DOMAIN_NAME){
    this->getDomain(data, fpos);
  }else if(field == TYPE_QUERY){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->type = binToDec(representation);
  }else if(field == CLASS_DNS){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->dnsClass = binToDec(representation);
  }
}

void QueryDNS::showData(){
  cout << "\tDNS Query" << endl
    << endl
    << "Domain Name: " << this->domainName << endl
    << "Type: " << this->type << endl
    << "Class: " << this->dnsClass << endl
    << endl;
}

string QueryDNS::getDomain(string &binary, int * fpos){
  int size, len, bfrsize;
  unsigned char * bytesbfr;
  string name;

  size = binary.length();
  bfrsize = size / BYTE;
  bytesbfr = new unsigned char[bfrsize];

  for(int k = i = 0; i<size; i+=BYTE, ++k)
    bytesbfr[k] = binToDec(data.substr(i, BYTE));

  int bytes = 0;
  while(bytesbfr[bytes] != 0 &&  bytes < bfrsize){
    if(bytes > 0) name += ".";
    len = bytesbfr[bytes++];
    while(len-- && bytes < bfrsize)
      name += bytesbfr[bytes++];
  }

  *fpos += (bytes*BYTE);
  // debug(name);
  return name;
}
