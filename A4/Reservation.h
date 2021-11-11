#ifndef RESERVATION_H
#define RESERVATION_H

#include "Guest.h"
#include "Room.h"
#include "Date.h"

using namespace std;

class Reservation {
  private:
    Guest* guest; // Guest pointer
    int stay; // number of days of stay
    Room* room; // Room pointer
    float price; // Total stay cost
    Date* date; // Start date of stay

  public:
    Reservation(Guest*, Room*, Date*, int); // ctor
    ~Reservation(); // dtor
    void getGuest(Guest**); // assigns guest pointer to passed parameter by reference
    int getStay() const; // returns stay variable
    void getRoom(Room**); // assigns room pointer to passed parameter by reference
    float getPrice() const; // returns price variable
    void getDate(Date**); // assigns date pointer to passed parameter by reference
    bool lessThan(Reservation*); // returns true if this date is less than date of passed parameter, false otherwise
    void print() const; // prints reservation info
};

#endif
