#ifndef CONTROL_H
#define CONTROL_H

#include "ResManager.h"
#include "Hotel.h"
#include "StayRecorder.h"
#include "GuestRecorder.h"
#include "UpgradeRecorder.h"
#include "View.h"

class Control
{
  public:
    Control(); // ctor
    ~Control(); // dtor
    void launch(); // populates with data and interacts with user

  private:
    void initHotel(); // initializes data for hotel object
    ResManager* resMgr; // pointer to ResManager object
    Hotel* hotel; // pointer to Hotel object
    View view; // View object
};

#endif
