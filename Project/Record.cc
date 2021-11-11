#include <iostream>
#include <string>
#include <iomanip>

#include "Record.h"

using namespace std;

Record::Record(int y, string r, string sr, string at, int nf, int num)
: year(y), region(r), subRegion(sr), animalType(at), numFarms(nf), numAnimals(num) {}

int Record::getYear() const {return year;}

string Record::getRegion() const {return region;}

string Record::getSubRegion() const {return subRegion;}

string Record::getAnimalType() const {return animalType;}

int Record::getNumFarms() const {return numFarms;}

int Record::getNumAnimals() const {return numAnimals;}

ostream& operator<<(ostream& output, Record& r) {
  output<<setfill(' ')<<setw(7)<<left<<r.year;
  output<<setfill(' ')<<setw(4)<<left<<r.region;
  output<<setfill(' ')<<setw(25)<<right<<r.subRegion;
  output<<setfill(' ')<<setw(15)<<right<<r.animalType;
  output<<setfill(' ')<<setw(8)<<right<<r.numFarms<<":";
  output<<setfill(' ')<<setw(10)<<right<<r.numAnimals;

  return output;
}
