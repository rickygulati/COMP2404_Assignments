#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

// Default ctor
Date::Date(string name, int d, int m, int y, int h, int min, int duration, bool rec, int weeks)
{
  eventName = name;
  recurring = rec;
  setDate(d, m, y);
  valid = validate(d, m, y, h, min, duration);
  if(valid){
    startTime = (h*60) + min;
    eventDuration = duration;
  }
  else{
    startTime = 0;
    eventDuration = 0;
  }
  if(recurring)
    weekCount = weeks;
  else
    weekCount = 0;
}

// Copy ctor
Date::Date(Date& date){
  eventName = date.eventName;
  startTime = date.startTime;
  eventDuration = date.eventDuration;
  recurring = date.recurring;
  weekCount = date.weekCount;
  valid = date.valid;
  day = date.day;
  month = date.month;
  year = date.year;
}

// Sets date
void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12 ) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}

// Returns true if this date is earlier than the date of parameter d
bool Date::lessThan(Date* d){
  if(year > d->year)
    return false;
  else if(year < d->year)
    return true;
  else
    if(month > d->month)
      return false;
    else if(month < d->month)
      return true;
    else
      if(day < d->day)
        return true;
      else if(day > d->day)
        return false;
      else
        if(startTime < d->startTime)
          return true;
        else return false;
}

// Returns the recurring flag
bool Date::isRecurring(){
  return recurring;
}

// Returns the valid flag
bool Date::isValid(){
  return valid;
}

// validates the date, start time and duration
bool Date::validate(int d, int m, int y, int hour, int minute, int dur){
  if(day == 0 || month == 0 || year == 0)
    return false;
  else if(hour < 0 || hour > 23 || minute < 0 || minute > 59 || dur < 0)
    return false;
  else if(dur <= 0 || dur > 1440)
    return false;
  else if(((hour*60) + minute + dur) > 1440)
    return false;
  else return true;
}

// Prints the data members in a nice format
void Date::print(){
  cout<<setfill(' ')<<setw(40)<<eventName<<":";
  cout<<setfill(' ')<<setw(10)<<getMonthStr()<<" "<<setw(2)<<day<<", "<<year<<" @ ";
  cout<<setfill('0')<<setw(2)<<(startTime/60)<<":";
  cout<<setfill('0')<<setw(2)<<(startTime%60)<<" - ";
  cout<<setfill('0')<<setw(2)<<((startTime+eventDuration)/60)<<":";
  cout<<setfill('0')<<setw(2)<<((startTime+eventDuration)%60);
  if(recurring)
    cout<<", recurs for "<<weekCount<<" weeks";
  cout<<endl;
}

// Returns the last date according to the value of the month
int Date::lastDayInMonth()
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

// Returns true if year is a leap year, false otherwise
bool Date::leapYear()
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

// Returns the name of the month
string Date::getMonthStr()
{
  string monthStrings[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}
