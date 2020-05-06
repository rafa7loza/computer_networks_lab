#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <fstream>
#include <string.h>
#include <string>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

string hexToString(int num);

int main(){

  char ch;
  string type="";
  int number, byte;
  int fileSize;
  string fileName = "ethernet_1.bin";

  // cout<<"\t\t\tS N I F F E R"<<endl<<endl<<endl;
  // cin.get();

  ifstream file(fileName,ios::binary | ios::in);

  file.seekg(0, ios::end);
  fileSize = int(file.tellg());
  file.seekg(0, ios::beg);

  if(file.is_open()){

    cout << "\t\tAnálisis de un paquete Ethernet" << endl;
    cout<<"{Nombre Archivo Abierto}: "<<fileName<<endl<<endl;

    cout<<"Campos Del Protocolo [Ethernet]:"<<endl;

    byte = 0;
    while(file.get(ch)){
      number = ch;

      if(number < 0) number += 256;

      if(byte == 0)
      cout << "\nDireccion de destino: ";
      else if(byte == 6)
      cout << "\nDireccion de origen: ";
      else if(byte == 12){
        cout << "\nTipo: ";
        type += hexToString(number);
      }else if(byte == 14){
        cout << "\nDatos: ";
      }


      cout << hex << setfill('0') << setw(2) << number;

      if(byte != 5 && byte != 11 && byte != 13 && byte != fileSize-1) cout << "-";

      if(byte == 13){
        type += hexToString(number);

        if(type == "0800") cout << ": IPv4";
        else if(type == "0806") cout << ": ARP";
        else if(type == "8035") cout << ": RARP";
        else if(type == "86DD") cout << ": IPv6";
      }
      ++byte;
    }

    file.close();

  }

  cout<<endl<<endl;

  return 0;

}


string hexToString(int num){

  if(num == 0) return "00";

  int res;
  string result = "";

  while(num > 0){
    res = num%16;
    if(res <= 9){
      result += char(res+'0');
    }else{
      switch(res){
      case 10: result += "A"; break;
      case 11: result += "B"; break;
      case 12: result += "C"; break;
      case 13: result += "D"; break;
      case 14: result += "E"; break;
      case 15: result += "F"; break;
      }
    }
    num /= 16;
  }

  if(result.size() == 1){
    result += '0';
  }
  reverse(result.begin(), result.end());

  return result;
}
