#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

Date::Date(int d, int m, int y)
{
  setDate(d, m, y);
}

Date::~Date() {}

void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}

int Date::lastDayInMonth() const
{
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear() const
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

bool Date::lessThan(Date& d) const{
  if(year < d.year)
    return true;
  else if(year > d.year)
    return false;
  else
    if(month < d.month)
      return true;
    else if(month > d.month)
      return false;
    else
      if(day >= d.day)
        return false;
      else return true;
}

bool Date::equals(Date& d) const{
  return (day == d.day && month == d.month && year == d.year);
}

void Date::print() const{
  cout<<year<<"-";
  cout<<setfill('0')<<setw(2)<<month<<"-";
  cout<<setfill('0')<<setw(2)<<day;
}

void Date::add(int duration) {
  if(duration >= 31 || duration < 0)
    return;
  if((duration+day) > lastDayInMonth()) {
    day = duration - (lastDayInMonth()-day);

    if(month == 12) {
      month = 1;
      year++;
    }
    else
      month++;
  }
  else
    day += duration;
}
