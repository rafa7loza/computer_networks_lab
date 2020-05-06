#ifndef HEADER_H
#define HEADER_H

using namespace std;

class Header{
public:
  Header();
  Header(string &data, int * position);
  void showData();
  string getType();

private:
  string addressSender;
  string addressReceiver;
  string type;
  int payloadSize;
  void setField(string &data, string field, int * fpos);
};

#endif
