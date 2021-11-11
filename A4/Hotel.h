#ifndef HOTEL_H
#define HOTEL_H

#include "ResManager.h"
#include "Guest.h"
#include "RoomArray.h"

#define MAX_GUESTS 256

class Hotel {
  private:
    string name; // hotel name
    Guest* guests[MAX_GUESTS]; // array of Guest pointers
    int numGuests; // number of guests
    RoomArray rooms; // collection of rooms
    ResManager* resManager; // ResManager pointer

  public:
    Hotel(string = "", ResManager* = NULL); // ctor
    ~Hotel(); // dtor
    void getRooms(RoomArray**); // assigns address of RoomArray collection to parameter
    void addGuest(Guest*); // adds guest to guests array
    void addRoom(Room*); // adds room to rooms collection
    void printGuests() const; // prints info about all guests
    void printRooms(); // prints all room info
    bool findGuest(string n, Guest** g); // returns true if found and assigns found guest to passed Guest**, returns false otherwise 
};

#endif
