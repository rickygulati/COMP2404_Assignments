#ifndef RECORD_H
#define RECORD_H

using namespace std;

class Record {
  friend ostream& operator<<(ostream& output, Record& r);
private:
  int year;
  string region;
  string subRegion;
  string animalType;
  int numFarms;
  int numAnimals;

public:
  Record(int=0, string="", string="", string="", int=0, int=0);
  int getYear() const;
  string getRegion() const;
  string getSubRegion() const;
  string getAnimalType() const;
  int getNumFarms() const;
  int getNumAnimals() const;
};

#endif
