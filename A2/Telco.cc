#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Telco.h"

Telco::Telco(string n): name(n), numSubs(0) {}

Telco::~Telco() {
  calls.cleanup();
  for(int i = 0; i < numSubs; i++)
    delete subscribers[i];
}

void Telco::addSub(Subscriber* sub) {
  if(numSubs < MAX_SUBS)
    subscribers[numSubs++] = sub;
}

void Telco::addCall(string srcNum, string destNum, int year, int month, int day, int hour, int minute, int duration) {
  int count = 0;
  Call* temp;
  for(int i = 0; i < numSubs; i++){
    if(subscribers[i]->getPhone().compare(srcNum) == 0){
      if(count == 0) {
        temp = new Call(srcNum, destNum, duration, day, month, year, hour, minute);
        calls.add(temp);
      }
      subscribers[i]->addOutgoing(temp);
      count++;
    }
    else if(subscribers[i]->getPhone().compare(destNum) == 0){
      if(count == 0) {
        temp = new Call(srcNum, destNum, duration, day, month, year, hour, minute);
        calls.add(temp);
      }
      subscribers[i]->addIncoming(temp);
      count++;
    }

    if(count == 2){
      return;
    }

  }
  if(count == 0)
    cout<<"ERROR: Call not added!"<<endl;
}

void Telco::computeFreqCaller(string destNum) {
    int max = 0;
    Array* collection = NULL;
    if(destNum.compare("all") == 0)
      collection = &calls;
    else {
      for(int i = 0; i < numSubs; i++) {
        if(destNum.compare(subscribers[i]->getPhone()) == 0) {
          subscribers[i]->getIncoming(&collection);
          break;
        }
      }
    }
    if(collection == NULL) {
      cout<<"ERROR: Subscriber not found!"<<endl;
      return;
    }

    for(int i = 0; i < collection->getSize(); i++) {
      int count = 0;
      for(int j = i+1; j < collection->getSize(); j++) {
        if(collection->get(i)->getSource().compare(collection->get(j)->getSource()) == 0)
          count += 1;
      }
      if(count > max)
        max = count;
    }

    for(int i = 0; i < collection->getSize(); i++) {
      int count = 0;
      for(int j = i+1; j < collection->getSize(); j++) {
        if(collection->get(i)->getSource().compare(collection->get(j)->getSource()) == 0)
          count += 1;
      }
      if(count == max) {
        cout<<"Most frequent caller phone: "<<collection->get(i)->getSource()<<endl;
        cout<<"Calls placed to "<<destNum<<":"<<endl;
        for(int k = 0; k < collection->getSize(); k++) {
          if(destNum.compare("all") != 0){
            if(collection->get(i)->getSource().compare(collection->get(k)->getSource()) == 0
              && collection->get(i)->getDest().compare(destNum) == 0){
              collection->get(k)->print();
            }
          }
          else {
            if(collection->get(i)->getSource().compare(collection->get(k)->getSource()) == 0){
              collection->get(k)->print();
            }
          }
        }
      }
  }
}

void Telco::computeFreqCalled(string srcNum) {
  int max = 0;
  Array* collection = NULL;
  if(srcNum.compare("all") == 0)
    collection = &calls;
  else {
    for(int i = 0; i < numSubs; i++) {
      if(srcNum.compare(subscribers[i]->getPhone()) == 0) {
        subscribers[i]->getOutgoing(&collection);
        break;
      }
    }
  }
  if(collection == NULL) {
    cout<<"ERROR: Subscriber not found!"<<endl;
    return;
  }

  for(int i = 0; i < collection->getSize(); i++) {
    int count = 0;
    for(int j = i+1; j < collection->getSize(); j++) {
      if(collection->get(i)->getDest().compare(collection->get(j)->getDest()) == 0){
        count += 1;
      }
    }
    if(count > max)
      max = count;
  }

  for(int i = 0; i < collection->getSize(); i++) {
    int count = 0;
    for(int j = i+1; j < collection->getSize(); j++) {
      if(collection->get(i)->getDest().compare(collection->get(j)->getDest()) == 0)
        count += 1;
    }
    if(count == max) {
      cout<<"Most frequent called phone: "<<collection->get(i)->getDest()<<endl;
      cout<<"Calls placed from "<<srcNum<<":"<<endl;
      for(int k = 0; k < collection->getSize(); k++) {
        if(srcNum.compare("all") != 0){
          if(collection->get(i)->getDest().compare(collection->get(k)->getDest()) == 0
            && collection->get(i)->getSource().compare(srcNum) == 0){
            collection->get(k)->print();
          }
        }
        else {
          if(collection->get(i)->getDest().compare(collection->get(k)->getDest()) == 0){
            collection->get(k)->print();
          }
        }
      }
    }
 }
}

void Telco::print() {
  cout<<"TELCO: "<<name<<endl<<endl;
  for(int i = 0; i < numSubs; i++) {
    subscribers[i]->print();
    cout<<endl;
  }
}
