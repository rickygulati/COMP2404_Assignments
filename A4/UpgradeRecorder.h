#ifndef UPGRADERECORDER_H
#define UPGRADERECORDER_H

#include "Recorder.h"
#include "Guest.h"
#include "Room.h"

class UpgradeRecorder: public Recorder {
  public:
    UpgradeRecorder(string=""); // ctor
    virtual void update(Reservation*); // adds info about Reservation* passed as parameter
};

#endif
