#include "ICMPv4.h"
#include "helpers.h"

ICMPv4::ICMPv4(){}

ICMPv4::ICMPv4(string data){
  int aux = 0;
  initField(ICMPV4_TYPE, data.substr(aux, BYTE));
  aux += BYTE;
  initField(ICMPV4_CODE, data.substr(aux, BYTE));
  aux += BYTE;
  initField(ICMPV4_CHECKSUM, data.substr(aux, BYTES_2));
  aux += BYTES_2;
  initField(ICMPV4_OTHER, data.substr(aux));
}

void ICMPv4::initField(string field, string representation){
  if(field == ICMPV4_TYPE){
    int aux = binToDec(representation);
    switch(aux){
        case 0: { this->type = "Echo Reply";   break;}
        case 3: { this->type = "Unreacheable Destination";   break;}
        case 4: { this->type = "Source Quench";  break;}
        case 5: { this->type = "Redirect";   break;}
        case 8: { this->type = "Echo";   break;}
        case 11: { this->type = "Time Exceeded";   break;}
        case 12: { this->type = "Parameter Problem";   break;}
        case 13: { this->type = "Timestamp";   break;}
        case 14: { this->type = "Timestamp Reply";   break;}
        case 15: { this->type = "Information Request";   break;}
        case 16: { this->type = "Information Reply";   break;}
        case 17: { this->type = "Addressmask";   break;}
        case 18: { this->type = "Addressmask Reply";   break;}
      }
  }else if(field == ICMPV4_CODE){
    this->errorCode = binToDec(representation);
  }else if(field == ICMPV4_CHECKSUM){
    for(int i=0; i<BYTES_2; i+=BYTE){
      this->checksum += binToHex(representation.substr(i, BYTE));
    }
  }else if(field == ICMPV4_OTHER){
    for(int i=0; i<representation.length(); i+=BYTE){
      this->otherFields += binToHex(representation.substr(i, BYTE)) + '-';
    }
    this->otherFields[this->otherFields.length()-1] = '\0';
  }
}

void ICMPv4::showData(){
  cout << "Mensaje informativo: " << this->type << endl
    << "Código de error: " << this->errorCode << endl
    << "Checksum: " << this->checksum << endl;
    printHexData(this->otherFields);

}
