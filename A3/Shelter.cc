#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

#include "Shelter.h"

using namespace std;

Shelter::Shelter(string s): name(s), numAnimals(0), numClients(0) {}

Shelter::~Shelter() {
  for(int i = 0; i < numAnimals; i++)
    delete animals[i];
  for(int i = 0; i < numClients; i++)
    delete clients[i];
}

bool Shelter::add(Client* c) {
  if(numClients < MAX) {
    clients[numClients++] = c;
    return true;
  }
  cout<<"ERROR: Max client limit reached!"<<endl;
  return false;
}

bool Shelter::add(Animal* a) {
  if(numAnimals < MAX) {
    animals[numAnimals++] = a;
    return true;
  }
  cout<<"ERROR: Max animal limit reached!"<<endl;
  return false;
}

void Shelter::printAnimals() const {
  cout<<"Shelter animals: ";
  for(int i = 0; i < numAnimals; i++) {
    cout<<endl;
    animals[i]->print();
  }
}

void Shelter::printClients() const {
  cout<<"Shelter clients: ";
  for(int i = 0; i < numClients; i++) {
    cout<<endl;
    clients[i]->print();
  }
}

void Shelter::computeMatches(MatchListByScore& ms, MatchListByClient& mc) {
  for(int i = 0; i < numClients; i++) {
    CriteriaArray* criteriaList;
    clients[i]->getClientCriteria(&criteriaList);
    for(int j = 0; j < numAnimals; j++) {
      float score = 0;
      for(int k = 0; k < criteriaList->getSize(); k++) {
        Criteria* current = criteriaList->get(k);
        if(current->getName() == "Species") {
          if(current->getValue() == animals[j]->speciesToString())
            score += 10;
        }
        else if(current->getName() == "Breed") {
          if(current->getValue() == animals[j]->getBreed())
            score += current->getWeight();
        }
        else if(current->getName() == "Gender") {
          if(current->getValue() == animals[j]->getGender())
            score += current->getWeight();
        }
        else if(current->getName() == "Age") {
          stringstream ss(current->getValue());
          int cValue;
          ss>>cValue;
          int age = animals[j]->getAge() / 12;
          float diff;
          (cValue > age)? diff = cValue - age: diff = age - cValue;
          diff /= 10.0;
          if(diff > 1.0)
            diff = 1;
          score += (current->getWeight()*(1-diff));
        }
      }
      if(score > 0.0) {
        Match* match = new Match(animals[j], clients[i], score);
        ms.add(match);
        mc.add(match);
      }
    }
  }
}
