#ifndef DATE_H
#define DATE_H

class Date
{
  public:
    Date(string name, int d, int m, int y, int h, int min, int duration, bool rec = false, int weeks = 10);
    Date(Date&);
    bool isRecurring();
    bool isValid();
    void print();
    bool lessThan(Date* d);

  private:
    string eventName;
    int startTime;
    int eventDuration;
    bool recurring;
    int weekCount;
    bool valid;
    int day;
    int month;
    int year;
    int  lastDayInMonth();
    bool leapYear();
    string getMonthStr();
    bool validate(int d, int m, int y, int hour, int minute, int dur);
    void setDate(int,int,int);
};

#endif
