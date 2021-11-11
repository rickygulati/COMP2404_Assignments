#ifndef MATCHLISTBYSCORE_H
#define MATCHLISTBYSCORE_H

#include "MatchList.h"

class MatchListByScore: public MatchList {
  public:
    void add(Match*); // Adds node with data as the provided parameter to linked list
};

#endif
