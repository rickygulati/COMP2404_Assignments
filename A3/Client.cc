#include <iostream>
#include <string>

using namespace std;

#include "Client.h"

int Client::nextId = 7001;

Client::Client(string n)
:name(n), Identifiable("C", nextId) {}

string Client::getName() const {return name;}

void Client::getClientCriteria(CriteriaArray** arr) {
  *arr = &clientCriteria;
}

void Client::addCriteria(Criteria* c) {
  clientCriteria.add(c);
}

void Client::print() {
  cout<<id<<": "<<name<<endl;
  cout<<"Client criteria info:"<<endl;
  clientCriteria.print();
}
