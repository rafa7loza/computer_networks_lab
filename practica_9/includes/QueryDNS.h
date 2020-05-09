#ifndef QUERYDNS_H
#define QUERYDNS_H

#include "helpers.h"

#define DOMAIN_NAME "domain name"
#define TYPE_QUERY "type query"
#define CLASS_DNS "dns class"

using namespace std;

class QueryDNS{
private:
  int fposition;
  string domainName;
  int type;
  int dnsClass;

  string getDomain(string &binary, int *fpos);
public:
  QueryDNS();
  QueryDNS(string &data);

  void setField(string &data, string field, int *fpos);
  void showData();
};

#endif
