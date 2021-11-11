#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Call.h"

Call::Call(string source, string destination, int dur, int dd, int mm, int yy, int hour, int minute)
: src(source), dest(destination), duration(dur)
{
  date = new Date(dd, mm, yy);
  time = new Time(hour, minute);
}

Call::~Call(){
  delete date;
  delete time;
}

bool Call::greaterThan(Call* call) {
  if(date->equals(call->date))
    return time->greaterThan(call->time);

  return date->greaterThan(call->date);
}

void Call::print() {
  date->print();
  cout<<" ";
  time->print(); cout<<", ";
  cout<<setfill(' ')<<setw(2)<<duration;
  cout<<" mins: From: ";
  cout<<src<<" To: ";
  cout<<dest<<endl;

}

string Call::getSource() {return src;}
string Call::getDest() {return dest;}
