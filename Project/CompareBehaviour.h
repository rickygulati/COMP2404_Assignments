#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H

#include <iostream>

using namespace std;

template <class T>
class CompareBehaviour {
public:
  virtual bool compare(T, T) = 0;
};

template <class T>
class AscBehaviour:public CompareBehaviour<T> {
public:
  virtual bool compare(T, T);
};

template <class T>
class DescBehaviour:public CompareBehaviour<T> {
public:
  virtual bool compare(T, T);
};

template <class T>
bool AscBehaviour<T>::compare(T t1, T t2) {
  return t1 < t2;
}

template <class T>
bool DescBehaviour<T>::compare(T t1, T t2) {
  return t1 > t2;
}


#endif
