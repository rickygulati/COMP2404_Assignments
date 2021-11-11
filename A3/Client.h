#ifndef CLIENT_H
#define CLIENT_H

#include "Identifiable.h"
#include "CriteriaArray.h"

class Client: public Identifiable {
  private:
    static int nextId; // Integer part of client id
    string name; // Client name
    CriteriaArray clientCriteria; // Collection to store client criteria

  public:
    Client(string); // ctor
    string getName() const; // Returns client name
    void getClientCriteria(CriteriaArray**); // Returns the criteria collection by reference
    void print(); // Prints client info
    void addCriteria(Criteria*); // Adds a criteria to the criteria collection
};

#endif
