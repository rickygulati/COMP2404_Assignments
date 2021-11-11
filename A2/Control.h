#ifndef CONTROL_H
#define CONTROL_H

#include "Telco.h"
#include "View.h"

class Control
{
  public:
    Control(); // ctor
    ~Control(); // dtor
    void launch(); // populates telco pointer with data and uses view object

  private:
    Telco* telco; // pointer to Telco object
    View view; // View object
    void initData(Telco*); // initializes subscribers and calls
    void initSubscribers(Telco*); // initializes subscribers
    void initCalls(Telco*); // initializes calls

};

#endif
