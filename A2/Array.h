#ifndef ARRAY_H
#define ARRAY_H

#define MAX_ARR 300

#include "Call.h"

class Array
{
  public:
    Array(); // ctor
    ~Array(); // dtor
    Array(Array&); // copy ctor
    bool add(Call*); // Parameter: Call pointer; Return:true if added, false otherwise
    bool add(Array&); // Parameter: Array pointer: Return: true if all calls of array added, false otherwise
    void print(); // prints all information of the Array object
    void cleanup(); // deallocates all elements of calls array
    int getSize() const; // returns size of calls array
    Call* get(int) const; // Parameter: call index; Return: Call pointer to element at parameter index

  private:
    Call* calls[MAX_ARR]; // Primitive array of Call* elements
    int size; // number of elements in calls array
};

#endif
