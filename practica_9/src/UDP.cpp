#include "UDP.h"

UDP::UDP(){}

UDP::UDP(string &data){
  this->fposition = 0;
  setField(data, ORIGIN_PORT_UDP, &this->fposition);
  setField(data, DESTINATION_PORT_UDP, &this->fposition);
  setField(data, TOTAL_LENGHT, &this->fposition);
  setField(data, CHECKSUM_UDP, &this->fposition);
  setField(data, OTHER_DATA, &this->fposition);
}

void UDP::setField(string &data, string field, int *fpos){
  string representation;

  if(field == ORIGIN_PORT_UDP){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->originPort = static_cast<unsigned int>(binToDec(representation));
  } else if(field == DESTINATION_PORT_UDP){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->destinationPort = static_cast<unsigned int>(binToDec(representation));
  } else if(field == CHECKSUM_UDP){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->checksum = binToHex(representation);
  } else if(field == TOTAL_LENGHT){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->length = binToHex(representation);
  } else if(field == OTHER_DATA){
    representation = data.substr(*fpos);
    if(this->originPort == 53 || this->destinationPort == 53)
      this->payload = (void *) new DNS(representation);
    else
      this->otherData = representation;

  }

}

void UDP::showData(){

  cout << "\tSegmento UDP" << endl
  << endl
  << "Puerto de origen: " << this->originPort << endl
  << "Puerto de destino: " << this->destinationPort << endl
  << "Tamaño total: " << this->length << endl
  << "Suma de comprobación: " << this->checksum << endl
  << endl;

  if((this->originPort == 53 || this->destinationPort == 53) && this->payload){
    static_cast<DNS*>(this->payload)->showData();
  }else{
    cout << "Datos: \n [ ";
    for(int i=0; i<this->otherData.length(); i += BYTE){
      if(i%BYTE == 0 && i != 0) cout << "-";
      cout << binToHex(this->otherData.substr(i, BYTE));
    }
    cout << " ]\n\n";
  }
}
