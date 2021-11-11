#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

#include "Control.h"

using namespace std;

Control::Control() {
  AnimalReport* ar = new AnimalReport(new DescBehaviour<int>());
  reports.push_back(ar);
}

Control::~Control() {
  for(int i = 0; i < reports.size(); i++)
    delete reports[i];
  ReportGenerator::cleanup();
}

void Control::init() {
  ReportGenerator::populate();
}

void Control::launch() {
  init();

  while(true) {
    int choice;
    string input;
    view.showMenu(choice);

    switch(choice) {
      case 1: { cout<<endl<<"REGION: "<<endl;
                 break; }
      case 2: { cout<<endl<<"Year: "<<endl<<endl;
                 break; }
      case 3: { cout<<endl<<"Animal: "<<endl;
                reports[0]->compute();
                reports[0]->printReport(); break; }
      default: return;
    }
  }
}
