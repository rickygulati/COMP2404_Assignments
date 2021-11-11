#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Time.h"

Time::Time(int h, int m)
{
  setTime(h, m);
}

void Time::setTime(int h,int m)
{
  hours   = ( h >= 0 && h < 24) ? h : 0;
  minutes = ( m >= 0 && m < 60) ? m : 0;
}

bool Time::greaterThan(Time* t) const
{
  return convertToMins() > t->convertToMins();
}

int Time::convertToMins() const
{
  return (hours*60 + minutes);

}

void Time::print() const
{
  cout<<setfill('0')<<setw(2)<<hours<<":"
      <<setfill('0')<<setw(2)<<minutes;
}
