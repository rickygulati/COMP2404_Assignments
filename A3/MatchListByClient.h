#ifndef MATCHLISTBYCLIENT_H
#define MATCHLISTBYCLIENT_H

#include "MatchList.h"

class MatchListByClient: public MatchList {
  public:
    void add(Match*); // Adds node with data as the provided parameter to linked list
};

#endif
