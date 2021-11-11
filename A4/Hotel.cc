#include <iostream>
#include <string>
#include <iomanip>

#include "Hotel.h"

using namespace std;

Hotel::Hotel(string n, ResManager* r): name(n), resManager(r), numGuests(0) {}

Hotel::~Hotel() {
  for(int i = 0; i < numGuests; i++)
    delete guests[i];
}

void Hotel::getRooms(RoomArray** r) {
  *r = &rooms;
}

void Hotel::addGuest(Guest* g) {
  if(numGuests < MAX_GUESTS)
    guests[numGuests++] = g;
}

void Hotel::addRoom(Room* r) {
  rooms.add(r);
}

void Hotel::printGuests() const {
  for(int i = 0; i < numGuests; i++) {
    cout<<endl;
    guests[i]->print();
  }
}

void Hotel::printRooms() {
  rooms.print();
}

bool Hotel::findGuest(string n, Guest** g) {
  for(int i = 0; i < numGuests; i++) {
    if(n == guests[i]->getName()) {
      *g = guests[i];
      return true;
    }
  }
  return false;
}
