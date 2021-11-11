#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "Match.h"

Match::Match(Animal* a, Client* c, float s): animal(a), client(c), score(s) {}

Match::~Match() {}

float Match::getScore() {return score;}

string Match::getClientId() {return client->getId();}

void Match::print() {
  cout<<setw(10)<<left<<client->getId();
  cout<<setw(10)<<left<<client->getName();
  cout<<":";
  cout<<setw(8)<<right<<animal->getId();
  cout<<setw(5)<<" ";
  cout<<setfill(' ')<<setw(15)<<left<<animal->getName();
  cout<<setw(5)<<":";
  cout<<setw(4)<<right<<fixed<<setprecision(1)<<score;
  cout<<setw(4)<<setprecision(0)<<" ("<<score*5<<"%"<<")";
}
