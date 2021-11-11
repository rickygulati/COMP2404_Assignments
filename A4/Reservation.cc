#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Reservation.h"

Reservation::Reservation(Guest* g, Room* r, Date* d, int n)
: guest(g), room(r), date(d), stay(n), price(n*(r->getRate())) {}

Reservation::~Reservation() {delete date;}

void Reservation::getGuest(Guest** g) {*g = guest;}

void Reservation::getRoom(Room** r) {*r = room;}

int Reservation::getStay() const {return stay;}

float Reservation::getPrice() const {return price;}

void Reservation::getDate(Date** d) {*d = date;}

bool Reservation::lessThan(Reservation* r) {return date->lessThan(*(r->date));}

void Reservation::print() const {
  cout<<"- - Guest:";
  cout<<setfill(' ')<<setw(15)<<right<<guest->getName();
  cout<<"; Room:";
  cout<<setfill(' ')<<setw(5)<<right<<fixed<<room->getRoomNum();
  cout<<"; arrival: "; date->print();
  cout<<"; stay:"<<setfill(' ')<<setw(3)<<right<<fixed<<stay;
  cout<<"; total: $"<<setfill(' ')<<setw(7)<<right<<fixed<<setprecision(2)<<price;
}
