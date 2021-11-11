#include <iostream>
#include <string>
#include <iomanip>

#include "Guest.h"

using namespace std;

Guest::Guest(string n, bool p): name(n), premium(p), points(0) {}

string Guest::getName() const {return name;}

bool Guest::isPremium() const {return premium;}

void Guest::addPts(int p) {points += p;}

void Guest::print() const {
  cout<<"- - "<<setfill(' ')<<setw(15)<<left<<name;
  if(premium)
    cout<<setfill(' ')<<setw(10)<<left<<"Premium";
  else
    cout<<setfill(' ')<<setw(10)<<left<<"Regular";
  cout<<"guest:";
  cout<<setfill(' ')<<setw(7)<<right<<fixed<<points;
  cout<<" pts";
}
