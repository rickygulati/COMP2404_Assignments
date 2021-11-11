#include <iostream>
#include <string>
using namespace std;

#include "MatchList.h"

MatchList::MatchList() : head(NULL) { }

MatchList::~MatchList()
{
  Node* currNode = head;

  while(currNode != NULL) {
    Node* temp = currNode;
    currNode = currNode->next;
    delete temp;
  }
}

void MatchList::cleanup() {
  Node* currNode = head;

  while(currNode != NULL) {
    Node* temp = currNode;
    currNode = currNode->next;
    if(temp->data != NULL){
      Match* m = temp->data;
      delete m;
    }
    
  }
}

void MatchList::print() const
{
  Node* currNode = head;

  while (currNode != NULL) {
    currNode->data->print();
    cout<<endl;
    currNode = currNode->next;
  }
}
