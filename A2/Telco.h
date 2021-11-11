#ifndef TELCO_H
#define TELCO_H

#define MAX_SUBS 64

#include "Subscriber.h"

class Telco{
  private:
    string name; // Name of Telco
    int numSubs; // Number of subscribers in Telco
    Array calls; // Array object of all calls in Telco
    Subscriber* subscribers[MAX_SUBS]; // Primitive array of Subscriber* objects

  public:
    Telco(string=""); // ctor
    ~Telco(); // dtor
    void addSub(Subscriber*); // Takes a Subscriber pointer and adds it to subscribers array
    void addCall(string, string, int, int, int, int, int, int); // Parameter: source number (string), destination number (string), year (int), month (int), day (int), hour (int), minute (int), duration (int); Adds Call to calls array and corresponding subscriber's calls
    void computeFreqCaller(string = "all"); // Parameter: if "all", prints all calls of most frequent caller; if a subscriber number, prints all calls between that number and the most frequent caller to that number
    void computeFreqCalled(string = "all"); // Parameter: if "all", prints all calls of most frequent called number; if a subscriber number, prints all calls between that number and the most frequent called number
    void print(); // Prints all information about the Telco object
};

#endif
