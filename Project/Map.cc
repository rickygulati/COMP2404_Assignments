#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Map.h"

using namespace std;

template <class T>
void Map<T>::add(T key, Record* rec) {
  for(int i = 0; i < keys.size(); i++) {
    if(key == keys.at(i)) {
      values.at(i).push_back(rec);
      return;
    }
  }
  keys.push_back(key);
  vector<Record*> temp;
  values.push_back(temp);
  values.at(values.size()-1).push_back(rec);
}

template <class T>
void Map<T>::getKeys(vector<T>& temp) {temp = keys;}

template <class T>
void Map<T>::getSize() const {return keys.size();}

template <class T>
vector<Record*>& Map<T>::operator[](T key) {
   for(int i = 0; i < keys.size(); i++) {
     if(key == keys.at(i)) {
       return values.at(i);
     }
   }

   throw "Key not found in map";
}
