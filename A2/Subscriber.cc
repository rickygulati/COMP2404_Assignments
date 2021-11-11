#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Subscriber.h"

Subscriber::Subscriber(string phone):phoneNum(phone) {}

Subscriber::~Subscriber(){}

void Subscriber::getIncoming(Array** arr){
  *arr = &incomingCalls;
}

void Subscriber::getOutgoing(Array** arr){
  *arr = &outgoingCalls;
}

void Subscriber::addIncoming(Call* c){
  incomingCalls.add(c);
}

void Subscriber::addOutgoing(Call* c){
  outgoingCalls.add(c);
}

void Subscriber::print() {
  cout<<"Subscriber "<<phoneNum<<":"<<endl;
  Array temp(incomingCalls);
  temp.add(outgoingCalls);
  temp.print();
}

string Subscriber::getPhone() {return phoneNum;}
