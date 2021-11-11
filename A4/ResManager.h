#ifndef RESMANAGER_H
#define RESMANAGER_H

#define MAX_RES 64

#include "Reservation.h"
#include "Recorder.h"

class Hotel;

class ResManager {
    private:
      Hotel* hotel; // Hotel pointer
      Reservation* reservations[MAX_RES]; // array of Reservation pointers
      int numReservations; // reservation count
      vector<Recorder*> recorders; // stl vector collection of Recorder pointers
      void notify(Reservation*); // Updates all recorders in recorders collection when reservation is added

    public:
      ResManager(Hotel* = NULL); // ctor
      ~ResManager(); // dtor
      void setHotel(Hotel*); // assigns parameter to hotel variable
      void addReservation(string, int, int, int, int, ReqRoomType); // takes parameters to create Date and Reservation objects and attempts to add to reservations array
      void print() const; // prints all reservations
      void printRecords() const; // prints all recorder info in recorders collection
      void subscribe(Recorder*); // Adds parameter Recorder pointer to recorders collection
};

#endif
