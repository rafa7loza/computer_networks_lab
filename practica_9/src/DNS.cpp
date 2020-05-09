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
  }else if(field == FLAGS_DNS){
    representation = data.substr(*fpos, BYTES_2);
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
  }else if(field == OTHER_DATA_DNS){
    representation = data.substr(*fpos);
    if(this->flags.qr){
      debug("Response");
    }else{
      debug("Query");
      this->payload = (void *) new QueryDNS(representation);
    }
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

    if(this->flags.qr){
      debug("Response");
    }else{
      static_cast<QueryDNS*>(this->payload)->showData();
    }

    // printHexData(this->otherData);

}
