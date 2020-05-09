#include "ResponseDNS.h"

ResponseDNS::ResponseDNS(){}

ResponseDNS::ResponseDNS(string &data){
  this->fposition = 0;
  setField(data, DOMAIN_NAME, &this->fposition);
  setField(data, TYPE_RESPONSE, &this->fposition);
  setField(data, CLASS_DNS, &this->fposition);
  setField(data, TTL_DNS_RESPONSE, &this->fposition);
  setField(data, LENGTH_DNS_RESPONSE, &this->fposition);
  setField(data, RDATA, &this->fposition);
}

void ResponseDNS::setField(string &data, string field, int *fpos){
  string representation;
  if(field == DOMAIN_NAME){
    domainName = this->getDomain(data, fpos);
  }else if(field == TYPE_RESPONSE){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->type = binToDec(representation);
  }else if(field == CLASS_DNS){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->dnsClass = binToDec(representation);
  }else if(field == TTL_DNS_RESPONSE){
    representation = data.substr(*fpos, BYTES_4);
    *fpos += BYTES_4;
    this->ttl = binToDec(representation);
  }else if(field == LENGTH_DNS_RESPONSE){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->lengthData = binToDec(representation);
  }else if(field == RDATA){
    this->data = data.substr(*fpos);
  }
}

void ResponseDNS::showData(){
  cout << "\tDNS Query" << endl
    << endl
    << "Domain Name: " << this->domainName << endl
    << "Type: " << this->type << endl
    << "Class: " << this->dnsClass << endl
    << "TTL: " << this->ttl << endl
    << "Length of the data: " << this->lengthData << " bytes" << endl;
    // << endl;
    printHexData(this->data);
}

string ResponseDNS::getDomain(string &binary, int * fpos){
  int size, len, bfrsize;
  unsigned char * bytesbfr;
  string name;

  size = binary.length();
  bfrsize = size / BYTE;
  bytesbfr = new unsigned char[bfrsize];

  for(int k=0, i=0; i<size; i+=BYTE, ++k)
    bytesbfr[k] = binToDec(binary.substr(i, BYTE));


  int bytes = 0;
  while(bytesbfr[bytes] != 0 &&  bytes < bfrsize){

    if(bytes > 0) name += ".";
    len = bytesbfr[bytes++];
    while(len-- && bytes < bfrsize)
      name += bytesbfr[bytes++];
  }
  *fpos += (++bytes*BYTE);

  return name;
}
