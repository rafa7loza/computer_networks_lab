#ifndef RESPONSEDNS_H
#define RESPONSEDNS_H

#include "helpers.h"

#define DOMAIN_NAME "domain name"
#define TYPE_RESPONSE "type response"
#define CLASS_DNS "dns class"
#define TTL_DNS_RESPONSE "dns ttl response"
#define LENGTH_DNS_RESPONSE "dns length resposne"
#define RDATA "dns rdata"

using namespace std;

class ResponseDNS{
private:
  int fposition;
  string domainName;
  int type;
  int dnsClass;
  unsigned int ttl;
  int lengthData;
  string data;

  string getDomain(string &binary, int *fpos);
public:
  ResponseDNS();
  ResponseDNS(string &data);

  void setField(string &data, string field, int *fpos);
  void showData();
};

#endif
