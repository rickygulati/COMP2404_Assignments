#ifndef CONTROL_H
#define CONTROL_H

using namespace std;

#include "ReportGenerator.h"
#include "View.h"

class Control {
private:
  vector<ReportGenerator*> reports;
  View view;
public:
  Control();
  ~Control();
  void launch();
  void init();
};

#endif
