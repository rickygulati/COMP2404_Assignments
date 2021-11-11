#ifndef MATCHLIST_H
#define MATCHLIST_H

#include "Match.h"

class MatchList
{
   protected: class Node
  {
    public:
      Match* data; // Pointer to Match object as data
      Node*    next; // Pointer to next node in linked list
  };

  public:
    MatchList(); // ctor
    ~MatchList(); // dtor
    void print() const; // Prints entire MatchList info
    void cleanup(); // deallocates linkedList nodes

  protected:
    Node* head; // Pointer to first node in linked list

};

#endif
