#ifndef TIME_H
#define TIME_H

class Time
{
  public:
    Time(int=0, int=0);
    bool greaterThan(Time*) const;
    void print() const;

  private:
    int hours;
    int minutes;
    int convertToMins() const;
    void setTime(int, int);
};

#endif
