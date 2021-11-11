#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

#include "GuestRecorder.h"

GuestRecorder::GuestRecorder(string n)
: Recorder(n) {}

void GuestRecorder::update(Reservation* r) {
  Guest* g;
  r->getGuest(&g);
  Room* rm;
  r->getRoom(&rm);
  if(!g->isPremium() && (rm->getType() != C_REG)) {
    stringstream k;
    k<<"premium guest offer for "<<g->getName();
    records.push_back(k.str());
  }
}
