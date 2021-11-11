#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#include "Recorder.h"

Recorder::Recorder(string n): name(n) {}

void Recorder::printRecords() const{
  cout<<endl<<"Records for "<<name<<":";
  for(int i = 0; i < records.size(); i++) {
    cout<<endl<<name<<": "<<records[i];
  }
}
