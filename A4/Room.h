#ifndef ROOM_H
#define ROOM_H
using namespace std;

#include "defs.h"

class Room {
  private:
    ReqRoomType type; // type of room
    int roomNumber; // room number
    float rate; // rate per night of room

  public:
    Room(ReqRoomType, int = -1, float = -1); // ctor
    int getRoomNum() const; // returns roomNumber
    float getRate() const; // returns rate
    string typeToString() const; // Returns string based on type variable
    void print() const; // prints room info
    ReqRoomType getType() const; // returns type
    void computePoints(int&); // computes points based on type and assigns to passed parameter
};

#endif
