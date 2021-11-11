#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "Identifiable.h"

Identifiable::Identifiable(string s, int &n) {
  stringstream ss;
  ss<<s<<"-"<<n;
  id = ss.str();
  n++;
}

string Identifiable::getId() const {
  return id;
}
