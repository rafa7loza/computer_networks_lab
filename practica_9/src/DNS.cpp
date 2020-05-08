#include "DNS.h"

DNS::DNS(){}

DNS::DNS(string &data){
  this->fposition = 0;
  cout
    << endl
    << "************************************" << endl
    << data
    << endl << "************************************" << endl
    << endl;
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
    debug(field);
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->id = static_cast<int>(binToDec(representation));
  }else if(field == FLAGS_DNS){
    representation = data.substr(*fpos, BYTES_2);
    debug(representation);
    *fpos += BYTES_2;
    this->flags.qr = representation[0] - ZERO;
    this->flags.opCode = binToDec(representation.substr(1, BITS_4));
    this->flags.authAns = representation[5] - ZERO;
    this->flags.tc = representation[6] - ZERO;
    this->flags.rd = representation[7] - ZERO;
    this->flags.ra = representation[8] - ZERO;
    this->flags.z = representation[9] - ZERO;
    this->flags.ad = representation[10] - ZERO;
    this->flags.cd = representation[11] - ZERO;
    this->flags.rCode = binToDec(representation.substr(12, BITS_4));
  }else if(field == QD_COUNT){
    debug(field);
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->qdCount = binToDec(representation);
  }else if(field == AN_COUNT){
    debug(field);
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->anCount = binToDec(representation);
  }else if(field == NS_COUNT){
    debug(field);
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->nsCount = binToDec(representation);
  }else if(field == AR_COUNT){
    debug(field);
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->arCount = binToDec(representation);
  }

  else if(field == OTHER_DATA_DNS){
    debug(field);
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
    << "QR [" << this->flags.qr << "]" << endl
    << "AA [" << this->flags.authAns << "]" << endl
    << "TC [" << this->flags.tc << "]" << endl
    << "RD [" << this->flags.rd << "]" << endl
    << "RA [" << this->flags.ra << "]" << endl
    << "Z [" << this->flags.z << "]" << endl
    << "AD [" << this->flags.ad << "]" << endl
    << "CD [" << this->flags.cd << "]" << endl
    << "RCode: " << this->flags.rCode << endl
    << endl
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
