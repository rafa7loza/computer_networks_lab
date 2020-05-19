#include <iostream>
#include <string>

#include "ICMPv6.h"
#include "helpers.h"

string getHexadecimal(string binary);

ICMPv6::ICMPv6(){
  this->type = "Null";
  this->error = "Null";
  this->checkSum = "Null";
  this->otherData = "Null";
  this->typeCode = -1;
  this->typeError = -1;
}

ICMPv6::ICMPv6(string data){
  int aux = 0;
  initField(ICMPV6_TYPE, data.substr(aux, BYTE));
  aux += BYTE;
  initField(ICMPV6_CODE, data.substr(aux, BYTE));
  aux += BYTE;
  initField(ICMPV6_CHECKSUM, data.substr(aux, BYTES_2));
  aux += BYTES_2;
  initField(ICMPV6_OTHER, data.substr(aux));

}

void ICMPv6::initField(string field, string representation){
  if(field == ICMPV6_TYPE){
    this->typeCode = binToDec(representation);
    switch (this->typeCode){
      case 1:   {this->type = "ERROR: Destino Inalcanzable";  break;}
      case 2:   {this->type = "ERROR:  Paquete Demasiado Grande";   break;}
      case 3:   {this->type = "ERROR: Time Exceeded"; break;}
      case 4:   {this->type = "ERROR: Problema De Parametro";   break;}
      case 128: {this->type = "INFORMACION: Pedido De Eco";   break;}
      case 129: {this->type = "INFORMACION: Respuesta De Eco";  break;}
      case 133: {this->type = "DETECCION DE VECINO: Solicitud Del Router";  break;}
      case 134: {this->type = "DETECCION DE VECINO: Anuncio Del Router";  break;}
      case 135: {this->type = "DETECCION DE VECINO: Solicitud Vecino";  break;}
      case 136: {this->type = "DETECCION DE VECINO: Anuncio DE Vecino";   break;}
      case 137: {this->type = "DETECCION DE VECINO: Reoriente El Mensaje";  break;}
      default:  {this->type = "¿?: No Especificado";  break;}
    }
  }else if(field == ICMPV6_CODE){
    this->typeError = binToDec(representation);
    switch (this->typeCode){
      case 1:{
          if(this->typeError == 0) this->error = "Sin Ruta Hacia El Destino";
          else if (this->typeError == 1) this->error = "Comunicacion Prohibida Con El Destino Administrativamente";
          else if (this->typeError == 2) this->error = "Sin Asignacion";
          else if (this->typeError == 3) this->error = "Direccion Inalcanzable";
          else this->error = "Puerto Inalcanzable";
          break;
      }
      case 3:
          if(this->typeError == 0) this->error = "Limite De Salto Excedido";
          else if (this->typeError == 1) this->error = "Tiempo De Reensamble De Fragmento Excedid";
          break;

      case 4:
          if(this->typeError == 0) this->error = "Campo De Encabezado Erroneo";
          else if (this->typeError == 1) this->error = "Tipo Del Siguiente Protocolo Erroneo";
          else if (this->typeError == 2) this->error = "Opcion De IPv6 Desconocida";
          break;

      case 128:
          if(this->typeError == 0) this->error = "Solicitud De Eco";
          else this->error = " ";
          break;

      case 129:
          if(this->typeError == 0)  this->error = "Respuesta De Eco";
          else this->error = " ";
          break;

      default: {this->error = "No Especificado"; break;}
    }
  }else if(field == ICMPV6_CHECKSUM){
    this->checkSum = getHexadecimal(representation);
  }else if(field == ICMPV6_OTHER){
    this->otherData = getHexadecimal(representation);
  }
}

void ICMPv6::showData(){
  cout << "Mensaje informativo: " << this->type << endl
    << "Código de error: {" << this->typeError << "} " << this->error << endl
    << "Checksum: " << this->checkSum << endl
    << "Resto de la información: " << this->otherData << endl;
}

string getHexadecimal(string binary){
  string result = "";
  int sz = binary.length();

  for(int k=0; k<sz; k += BITS_4){
    string block = binary.substr(k, BITS_4);
    result += decToHex(binToDec(block))[1];
    if((k+BITS_4)%16 == 0 && k+BITS_4<sz) result += '-';
  }

  return result;
}
