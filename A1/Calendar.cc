#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Calendar.h"
#include "Date.h"

// default ctor
Calendar::Calendar(string name){
  calendarName = name;
  dates = new Date*[MAX_DATES];
  numDates = 0;
}

// dtor
Calendar::~Calendar(){
  for(int i = 0; i < numDates; i++)
    delete dates[i];
  delete [] dates;
}

// Returns the calendar name
string Calendar::getCalendarName(){
  return calendarName;
}

// Adds a date to the calendar
bool Calendar::addDate(Date* d){
  if(numDates == MAX_DATES){
    cout<<"ERROR: Number of dates full"<<endl;
    delete d;
    return false;
  }
  if(!(d->isValid())){
    cout<<"ERROR: Date is INVALID"<<endl;
    delete d;
    return false;
  }
  int pos = -1;
  for(int i = 0; i < numDates; i++){
    if(d->lessThan(dates[i])){
      pos = i;
      break;
    }
  }
  if(pos == -1)
    pos = numDates;
  for(int i = numDates-1; i >= pos; --i)
    dates[i+1] = dates[i];
  dates[pos] = d;
  numDates++;
  return true;
}

// Adds all dates from the calendar parameter to this calendar
void Calendar::merge(Calendar* c){
  for(int i = 0; i < c->numDates; i++){
    if(numDates == MAX_DATES)
      return;
    Date* d = new Date(*(c->dates[i]));
    addDate(d);
  }
}

// Prints all dates in the calendar
void Calendar::printDates(){
  cout<<"Following are the dates in the calendar: "<<endl;
  for(int i = 0; i < numDates; i++){
    dates[i]->print();
  }
}

// Prints calendar name, number of dates and all dates in the calendar
void Calendar::print(){
  cout<<"Calendar name: "<<calendarName<<endl;
  cout<<"Number of dates in calendar: "<<numDates<<endl;
  printDates();
}
