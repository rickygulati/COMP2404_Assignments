#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Agenda.h"

// ctor
Agenda::Agenda(string name){
  agendaName = name;
  numCalendars = 0;
}

// dtor
Agenda::~Agenda(){
  for(int i = 0; i < numCalendars; i++)
    delete calendars[i];
}

// Adds a calendar to the agenda
bool Agenda::add(Calendar* c){
  if(numCalendars == MAX_CALENDARS)
    return false;
  else{
    calendars[numCalendars] = c;
    numCalendars++;
    return true;
  }
}

// Returns true if a calendar name matching the string parameter was found, false otherwise
bool Agenda::find(string n, Calendar** c){
  for(int i = 0; i < numCalendars; i++){
    if(n.compare(calendars[i]->getCalendarName()) == 0){
      *c = calendars[i];
      return true;
    }
  }
  cout<<"ERROR: Calendar "<<n<<" not found"<<endl;
  return false;
}

// Returns true if a date was added to the agenda successfully, false otherwise
bool Agenda::add(Date* d, string n){
  Calendar* temp;
  if(find(n, &temp))
    return temp->addDate(d);
  delete d;
  return false;
}

// Prints the agenda in a nicely formatted way
void Agenda::print(){
  Calendar c("temp");
  for(int i = 0; i < numCalendars; i++)
    c.merge(calendars[i]);
  cout<<"Agenda: "<<agendaName<<endl;
  c.printDates();
}
