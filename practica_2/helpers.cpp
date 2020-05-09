#include <iostream>
#include <string>
#include "helpers.h"

using namespace std;

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

string binToString(int num){
  string result = "";
  while(num > 0){
    result += (num % 2) + '0';
    num /= 2;
  }

  while(result.length() <= 7) result += '0';

  reverse(result.begin(), result.end());

  return result;

}

unsigned int binToDec(string binary){
  int result = 0, p = 0;

  for(int i=binary.length()-1; i>=0; --i, ++p){
    if(binary[i] == '1')
      result += pow(2, p);
  }
  return result;
}

string getAddress(string binary){

  string result = "";
  int sz = binary.length();
  // cout << binary.size() << endl;

  for(int k=0; k<sz; k+=BYTE){
    string aux = binary.substr(k, BYTE);
    // cout << aux << ", " << binToDec(aux) << endl;
    result += to_string(binToDec(aux)) + '.';

  }
  return result.substr(0, result.length()-1);
}
