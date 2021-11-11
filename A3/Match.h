#ifndef MATCH_H
#define MATCH_H

#include "Animal.h"
#include "Client.h"

class Match {
  private:
    Animal* animal; // Pointer to an Animal object
    Client* client; // Pointer to a Client object
    float score; // match score

  public:
    Match(Animal* = NULL, Client* = NULL, float = -1.0); // ctor
    ~Match(); // dtor
    float getScore(); // Returns the score
    string getClientId(); // Returns the client id
    void print(); // Prints info about the match
};

#endif
