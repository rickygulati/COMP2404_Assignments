#ifndef MAP_H
#define MAP_H

#include "Record.h"

using namespace std;

template <class T>
class Map {
private:
  vector<T> keys;
  vector<vector<Record*>> values;
public:
  void add(T, Record*);
  void getKeys(vector<T>&);
  void getSize() const;
  vector<Record*>& operator[](T k);
};

#endif
