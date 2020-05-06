#include <iostream>
#include <string>
#include <math.h>

#include "helpers.h"

using namespace std;

string decToHex(int num){

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

string decToBin(int num){
  string result = "";
  while(num > 0){
    result += (num % 2) + '0';
    num /= 2;
  }

  while(result.length() <= 7) result += '0';

  reverse(result.begin(), result.end());

  return result;

}

int binToDec(string binary){
  int result = 0, p = 0;

  for(int i=binary.length()-1; i>=0; --i, ++p){
    if(binary[i] == '1')
      result += pow(2, p);
  }
  return result;
}

string binToHex(string binary){
  return decToHex(binToDec(binary));
}

string getIpAddress(string binary){

  string result = "";
  int sz = binary.length();

  for(int k=0; k<sz; k+=BYTE){
    string aux = binary.substr(k, BYTE);
    result += to_string(binToDec(aux)) + '.';

  }
  return result.substr(0, result.length()-1);
}

string getMACAddress(string binary){
  string result = "";
  int sz = binary.length();

  for(int k=0; k<sz; k+=BYTE){
    string aux = binary.substr(k, BYTE);
    result += decToHex(binToDec(aux)) + "-";
  }

  return result.substr(0, result.length()-1);
}

string getIPv6Address(string binary){
  string result = "";
  int sz = binary.length();

  for(int k=0; k<sz; k+=BITS_4){
    string block = binary.substr(k, BITS_4);
    result += tolower(decToHex(binToDec(block))[1]);
    if((k+BITS_4)%16 == 0 && k+BITS_4<sz) result += ':';

  }
  return result;
}

int open_file(char * str){
  // Opening the file
  return open(str,
    // Flags
    O_RDWR | O_CREAT,
    // Permisions
    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
}

int getFileSize(int fd){
  int currentPosition = lseek(fd, 0, SEEK_CUR);
  int size = lseek(fd, 0, SEEK_END) - lseek(fd, 0, SEEK_SET);
  lseek(fd, currentPosition, SEEK_SET);
  return size;
}
