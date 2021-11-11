#ifndef GUEST_H
#define GUEST_H

using namespace std;

class Guest {
  private:
    string name; // Guest name
    bool premium; // true if premium guest, false otherwise
    int points; // points accumulated by guest

  public:
    Guest(string = "", bool = false); // ctor
    void addPts(int); // adds the parameter number of days to the current date
    string getName() const; // returns guest name
    bool isPremium() const; // returns premium variable
    void print() const; // prints guest info
};

#endif
