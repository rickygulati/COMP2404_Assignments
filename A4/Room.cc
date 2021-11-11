#include <iostream>
#include <string>
#include <iomanip>

#include "Room.h"
#include "defs.h"

using namespace std;

Room::Room(ReqRoomType t, int rn, float r)
: type(t), roomNumber(rn), rate(r) {}

int Room::getRoomNum() const {return roomNumber;}

float Room::getRate() const {return rate;}

string Room::typeToString() const {
  switch(type) {
    case C_REG: return "Regular";
    case C_PREM: return "Premium";
    case C_SUITE: return "Suite";
    default: return "";
  }
}

ReqRoomType Room::getType() const {return type;}

void Room::computePoints(int &pts) {
  switch(type) {
    case C_REG: pts = 0.1*rate; break;
    case C_PREM: pts = 0.15*rate; break;
    case C_SUITE: pts = 0.2*rate; break;
  }
}

void Room::print() const {
  cout<<"- - ";
  cout<<setfill(' ')<<setw(5)<<left<<fixed<<roomNumber;
  cout<<setfill(' ')<<setw(12)<<left<<fixed<<typeToString();
  cout<<"room:  $";
  cout<<setfill(' ')<<setw(7)<<right<<fixed<<setprecision(2)<<rate;
  cout<<" per night"<<endl;
}
