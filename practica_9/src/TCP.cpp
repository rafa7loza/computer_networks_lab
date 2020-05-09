#include "TCP.h"

TCP::TCP(){}

TCP::TCP(string &data){
  this->fposition = 0;
  setField(data, ORIGIN_PORT_TCP, &fposition);
  setField(data, DESTINATION_PORT_TCP, &fposition);
  setField(data, SEQ_NUM, &fposition);
  setField(data, ACK, &fposition);
  setField(data, HEADER_LENGTH_TCP, &fposition);
  setField(data, RESERVED, &fposition);
  setField(data, FLAGS_TCP, &fposition);
  setField(data, WINDOW_LENGTH, &fposition);
  setField(data, CHECKSUM_TCP, &fposition);
  setField(data, URGENT_POINTER, &fposition);
  setField(data, OTHER_CONTENT, &fposition);
}

void TCP::setField(string &data, string field, int *fpos){
  string representation;
  if(field == ORIGIN_PORT_TCP){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->originPort = binToDec(representation);
  }else if(field == DESTINATION_PORT_TCP){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->destinationPort = binToDec(representation);
  }else if(field == SEQ_NUM){
    representation = data.substr(*fpos, BYTES_4);
    *fpos += BYTES_4;
    this->sequenceNum = static_cast<unsigned int>(binToDec(representation));
  }else if(field == ACK){
    representation = data.substr(*fpos, BYTES_4);
    *fpos += BYTES_4;
    this->ack = static_cast<unsigned int>(binToDec(representation));
  }else if(field == HEADER_LENGTH_TCP){
    representation = data.substr(*fpos, BITS_4);
    *fpos += BITS_4;
    this->headerLength = binToDec(representation);
  }else if(field == RESERVED){
    representation = data.substr(*fpos, BITS_3);
    *fpos += BITS_3;
    this->reserved = representation;
  }else if(field == FLAGS_TCP){
    representation = data.substr(*fpos, BYTE);
    *fpos += BITS_9;
    for(int i=0; i<BITS_9; ++i)
      if(representation[i] == '1') this->flags[i] = true;
      else this->flags[i] = false;
  }else if(field == WINDOW_LENGTH){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->wlength = static_cast<unsigned int>(binToDec(representation));
  }else if(field == CHECKSUM_TCP){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->checksum = binToHex(representation);
  }else if(field == URGENT_POINTER){
    representation = data.substr(*fpos, BYTES_2);
    *fpos += BYTES_2;
    this->urgentPointer = binToDec(representation);
  }else if(field == OTHER_CONTENT){
    representation = data.substr(*fpos);
    this->otherContent = representation;
  }
}

void TCP::showData(){
  cout << "\tSegmento TCP" << endl << endl
    << "Puerto de origen: " << this->originPort << endl
    << "Puerto de destino: " << this->destinationPort << endl
    << "Número de secuencia: " << this->sequenceNum << endl
    << "Número de acuse de recibo: " << this->ack << endl
    << "Longitude de cabecera: " << this->headerLength << endl
    << "** Reservado: " << this->reserved << endl << endl
    << "\tBanderas" << endl;

    cout << "[" << this->flags[0] << "] "<< "NS ECN-nonce concealment protection" << endl
      << "[" << this->flags[1] << "] " << "CWR Congestion Window Reduced" << endl
      << "[" << this->flags[2] << "] " << "ECE" << endl
      << "[" << this->flags[3] << "] " << "URG" << endl
      << "[" << this->flags[4] << "] " << "ACK" << endl
      << "[" << this->flags[5] << "] " << "PSH" << endl
      << "[" << this->flags[6] << "] " << "RST Reset" << endl
      << "[" << this->flags[7] << "] " << "SYN Synchronice" << endl
      << "[" << this->flags[8] << "] " << "FIN" << endl;

    cout << endl
      << "Tamaño de la ventana: " << this->wlength << endl
      << "Suma de verificicación: " << this->checksum << endl
      << "Puntero urgente: " << this->urgentPointer << endl;

    printHexData(this->otherContent);
}
