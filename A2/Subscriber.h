#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Array.h"

class Subscriber{
  private:
    string phoneNum; // phone number of subscriber
    Array incomingCalls; // Array object of incoming calls
    Array outgoingCalls; // Array object of outgoing calls

  public:
    Subscriber(string = ""); // ctor
    ~Subscriber(); // dtor
    void addIncoming(Call*); // Takes a Call pointer and adds it to incomingCalls
    void addOutgoing(Call*); // Takes a Call pointer and adds it to outgoingCalls
    void print(); // Prints all info about subscriber
    void getIncoming(Array**); // Takes double pointer to Array and assigns it address of incomingCalls
    void getOutgoing(Array**); // Takes double pointer to Array and assigns it address of outgoingCalls
    string getPhone(); // Returns phone number of subscriber


};

#endif
