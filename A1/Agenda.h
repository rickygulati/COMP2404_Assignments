#ifndef AGENDA_H
#define AGENDA_H

#include "Calendar.h"

#define MAX_CALENDARS 10

class Agenda{
  private:
    string agendaName;
    Calendar* calendars[MAX_CALENDARS];
    int numCalendars;
    bool find(string n, Calendar** c);

  public:
    Agenda(string name);
    ~Agenda();
    bool add(Calendar* c);
    bool add(Date* d, string n);
    void print();
};

#endif
