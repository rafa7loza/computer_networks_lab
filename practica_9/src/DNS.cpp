#include "DNS.h"

DNS::DNS(){}

DNS::DNS(string &data){
  this->fposition = 0;
  setField(data, ID_DNS, &this->fposition);
  setField(data, FLAGS_DNS, &this->fposition);
  setField(data, QD_COUNT, &this->fposition);
  setField(data, AN_COUNT, &this->fposition);
  setField(data, NS_COUNT, &this->fposition);
  setField(data, AR_COUNT, &this->fposition);
  setField(data, OTHER_DATA_DNS, &this->fposition);
}

void DNS::setField(string &data, string field, int * fpos){
  string representation;
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
    this->flags.z = representation.substr(9, BITS_3);
    this->flags.rCode = binToDec(representation.substr(12, BITS_4));
  }else if(field == QD_COUNT){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->qdCount = binToDec(representation);
  }else if(field == AN_COUNT){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->anCount = binToDec(representation);
  }else if(field == NS_COUNT){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->nsCount = binToDec(representation);
  }else if(field == AR_COUNT){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->arCount = binToDec(representation);
  }

  else if(field == OTHER_DATA_DNS){
    representation = data.substr(*fpos);
    this->otherData = representation;
  }
}

void DNS::showData(){
  cout << "\tSegmento DNS" << endl
    << endl
    << "ID: " << this->id << endl
    << "\n\tFlags" << endl
    << "Op Code: " << this->flags.opCode << endl
    << "RCode: " << this->flags.rCode << endl
    << "QR [" << this->flags.qr << "]" << endl
    << "AA [" << this->flags.authAns << "]" << endl
    << "TC [" << this->flags.tc << "]" << endl
    << "RD [" << this->flags.rd << "]" << endl
    << "RA [" << this->flags.ra << "]" << endl
    << "Reserved: " << this->flags.z << endl << endl
    << "QD Count: " << this->qdCount << endl
    << "AN Count: " << this->anCount << endl
    << "NS Count: " << this->nsCount << endl
    << "AR Count: " << this->arCount << endl
    << endl;

    cout << "Data: \n[ ";
    for(int i=0; i<this->otherData.length(); i+=BYTES_2){
      if(i%BYTES_2 == 0 && i != 0) cout << "-";
      cout << binToHex(this->otherData.substr(i, BYTES_2));
    }
    cout << " ]" << endl;
}
