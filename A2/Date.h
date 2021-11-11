#ifndef DATE_H
#define DATE_H

class Date
{
  public:
    Date(int=0, int=0, int=2000); // ctor
    ~Date(); // dtor
    bool greaterThan(Date* d) const; // Parameter: Date pointer; Return: Returns true if this is greater than Date pointer, false otherwise
    bool equals(Date* d) const; // Parameter: Date pointer; Return: Returns true if this is equal to Date pointer, false otherwise
    void print() const; // Prints information about the date

  private:
    int day; // day
    int month; // month
    int year; // year
    int  lastDayInMonth() const; // Returns integer corresponding to last day in month
    bool leapYear() const; // Returns true if year is leap year, false otherwise
    string getMonthStr() const; // Returns string(name) corresponding to month integer
    void setDate(int, int, int); // Parameter: day(int), month(int), year(int); Sets day, month, year according to parameters
};

#endif
