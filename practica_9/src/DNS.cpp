#include "DNS.h"

DNS::DNS(){}

DNS::DNS(string &data){

}

void DNS::setField(string &data, string field, int * fpos){
  string representation:
  if(field == ID_DNS){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->id = static_cast<int>(binToDec(representation));
  }else if(FLAGS_DNS){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->flags.qr = representation[0] - ONE;
    this->flags.opCode = binToDec(representation.substr(1, BITS_4));
    this->flags.authAns = representation[5] - ONE;
    this->flags.tc = representation[6] - ONE;
    this->flags.rd = representation[7] - ONE;
    this->flags.ra = representation[8] - ONE;
    this->flags.z = representation(9, BITS_3);
    this->flags.rCode = binToDec(representation(12, BITS_4));

  }
}

void DNS::showData(){

}
