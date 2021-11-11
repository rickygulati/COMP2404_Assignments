#ifndef SHELTER_H
#define SHELTER_H

#include "Animal.h"
#include "Client.h"
#include "MatchListByScore.h"
#include "MatchListByClient.h"
#include "Match.h"

#define MAX 64

class Shelter {
  private:
    string name; // Shelter name
    Animal* animals[MAX]; // Array of shelter animals
    Client* clients[MAX]; // Array of shelter clients
    int numAnimals; // Shelter animal count
    int numClients; // Shelter client count

  public:
    Shelter(string = ""); // ctor
    ~Shelter(); // dtor
    bool add(Animal*); // Returns true if Animal pointer added, false otherwise
    bool add(Client*); // Returns true if Client pointer added, false otherwise
    void printAnimals() const; // Prints info of all shelter animals
    void printClients() const; // Prints info of all shelter clients
    void computeMatches(MatchListByScore&, MatchListByClient&); // Computes matches between animals and clients based on client criteria and adds new match pointer to both provided lists
};

#endif
