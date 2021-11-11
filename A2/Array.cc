#include <iostream>
using namespace std;

#include "Array.h"

Array::Array(): size(0) {}

Array::~Array() {}

Array::Array(Array &arr){
  size = 0;
  add(arr);
}

void Array::cleanup() {
  for(int i = 0; i < size; i++)
    delete calls[i];
}

bool Array::add(Call* c)
{
  if (size >= MAX_ARR)
    return false;

  if(size == 0) {
    calls[size++] = c;
    return true;
  }

  for(int i = size - 1; i >= 0; --i){
    if(c->greaterThan(calls[i])){
      calls[i+1] = calls[i];
      if(i == 0) {
        calls[i] = c;
        size++;
        return true;
      }
    }
    else{
      calls[i+1] = c;
      ++size;
      return true;
    }
  }
  return false;
}

bool Array::add(Array& arr){
  for(int i = 0; i < arr.size; ++i){
    if(!add(arr.calls[i])){
      return false;
    }
  }
  return true;
}

int Array::getSize() const{
  return size;
}

Call* Array::get(int index) const{
  return calls[index];
}

void Array::print()
{
  for (int i=0; i<size; i++){
    calls[i]->print();
  }

  cout << endl;
}
