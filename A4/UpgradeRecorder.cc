#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

#include "UpgradeRecorder.h"

UpgradeRecorder::UpgradeRecorder(string n)
: Recorder(n) {}

void UpgradeRecorder::update(Reservation* r) {
  Guest* g;
  r->getGuest(&g);
  Room* rm;
  r->getRoom(&rm);
  if(!g->isPremium() && (r->getStay()*(rm->getRate())) > 1500) {
    stringstream k;
    k<<"Guest"<<setw(15)<<right<<g->getName()<<", $"<<setw(6)<<right<<fixed<<setprecision(2)<<(r->getStay()*(rm->getRate()));
    records.push_back(k.str());
  }
}
