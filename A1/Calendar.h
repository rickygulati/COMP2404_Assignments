#ifndef CALENDAR_H

#include "Date.h"

#define CALENDAR_H

#define MAX_DATES 64

class Calendar{
  public:
    Calendar(string name);
    ~Calendar();
    string getCalendarName();
    bool addDate(Date* d);
    void merge(Calendar* c);
    void printDates();
    void print();

  private:
    string calendarName;
    Date** dates;
    int numDates;


};

#endif
