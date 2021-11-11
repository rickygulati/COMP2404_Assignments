#ifndef CALL_H
#define CALL_H

#include "Date.h"
#include "Time.h"

class Call{
  private:
    string src; // source number
    string dest; // destination number
    int duration; // call duration
    Date* date; // Date pointer to store date of call
    Time* time; // Time pointer to store time of call

  public:
    Call(string source, string destination, int dur, int dd, int mm, int yy, int hour, int minute); // ctor
    ~Call(); // dtor
    bool greaterThan(Call*); // Parameter: Call pointer to be compared; Return: true if this is greater than parameter, false otherwise
    void print(); // Prints all information about the Call object
    string getSource(); // Returns the source number
    string getDest(); // Returns the destination number
};

#endif
