#ifndef STAYRECORDER_H
#define STAYRECORDER_H

#include "Recorder.h"
#include "Guest.h"

class StayRecorder: public Recorder {
  public:
    StayRecorder(string=""); //ctor
    virtual void update(Reservation*); // adds info about Reservation* passed as parameter
};

#endif
