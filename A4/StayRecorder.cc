#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

#include "StayRecorder.h"

StayRecorder::StayRecorder(string n)
: Recorder(n) {}

void StayRecorder::update(Reservation* r) {
  if(r->getStay() > 3) {
    Guest* g;
    r->getGuest(&g);
    stringstream k;
    k<<"Guest"<<setw(15)<<right<<g->getName()<<","<<setw(5)<<right<<r->getStay()<<" nights";
    records.push_back(k.str());
  }
}
