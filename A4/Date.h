#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;

class Date
{
  public:
    Date(int=0, int=0, int=2000); // ctor
    ~Date(); // dtor
    bool lessThan(Date&) const; // Parameter: Date reference; Return: Returns true if this is less than Date reference, false otherwise
    bool equals(Date&) const; // Parameter: Date reference; Return: Returns true if this is equal to Date reference, false otherwise
    void print() const; // Prints information about the date
    void add(int); // Adds the value of the parameter to the current date

  private:
    int day; // day
    int month; // month
    int year; // year
    int  lastDayInMonth() const; // Returns integer corresponding to last day in month
    bool leapYear() const; // Returns true if year is leap year, false otherwise
    void setDate(int, int, int); // Parameter: day(int), month(int), year(int); Sets day, month, year according to parameters
};

#endif
