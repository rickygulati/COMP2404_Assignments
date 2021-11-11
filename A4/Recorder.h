#ifndef RECORDER_H
#define RECORDER_H
#include <vector>

#include "Reservation.h"

class Recorder {
  protected:
    string name; // Recorder name
    vector<string> records; // stl vector collection of records

  public:
    Recorder(string=""); // ctor
    virtual void printRecords() const; // prints all records
    virtual void update(Reservation*) = 0; // this is overloaded in derived classes
};

#endif
