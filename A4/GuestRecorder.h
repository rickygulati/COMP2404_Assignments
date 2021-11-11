#ifndef GUESTRECORDER_H
#define GUESTRECORDER_H

#include "Recorder.h"
#include "Guest.h"
#include "Room.h"

class GuestRecorder: public Recorder {
  public:
    GuestRecorder(string=""); // ctor
    virtual void update(Reservation*); // adds info about Reservation* passed as parameter
};

#endif
