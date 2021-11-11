#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "ResManager.h"
#include "Hotel.h"

using namespace std;

ResManager::ResManager(Hotel* h): hotel(h), numReservations(0) {}

ResManager::~ResManager() {
  delete hotel;
  for(int i = 0; i < numReservations; i++)
    delete reservations[i];

  for(int i = 0; i < recorders.size(); i++)
    delete recorders[i];
}

void ResManager::setHotel(Hotel* h) {hotel = h;}

void ResManager::addReservation(string name, int yr, int mth, int day, int stay, ReqRoomType reqType) {
  if(stay >= 31 || stay < 0 || numReservations >= MAX_RES)
    return;

  Date* newDate = new Date(day, mth, yr);
  RoomArray* rooms;
  hotel->getRooms(&rooms);
  bool added = false;

  for(int i = 0; i < rooms->getSize(); i++) {
    Room* hotRoom = rooms->get(i);

    if(hotRoom->getType() == reqType) {
      bool flag = true;

      for(int i = 0; i < numReservations; i++) {
        Room* resRoom;
        reservations[i]->getRoom(&resRoom);

        if(hotRoom->getRoomNum() == resRoom->getRoomNum()) {
          Date* resDate;
          reservations[i]->getDate(&resDate);

          if(newDate->equals(*resDate)) {
            flag = false;
            break;
          }

          if(newDate->lessThan(*resDate)) {
            Date* tempDate = new Date(day, mth, yr);
            tempDate->add(stay);

            if(!tempDate->lessThan(*resDate)) {
              flag = false;
              delete tempDate;
              break;
            }
            delete tempDate;
          }

          else {
            Date tempDate = *resDate;
            tempDate.add(reservations[i]->getStay());

            if(!tempDate.lessThan(*newDate)) {
              flag = false;
              break;
            }
          }
        }
      }

      if(flag) {
        Guest* newGuest;

        if(hotel->findGuest(name, &newGuest)) {
            Reservation* newRes = new Reservation(newGuest, hotRoom, newDate, stay);

            for(int i = numReservations-1; i >= 0; i--) {

              if(newRes->lessThan(reservations[i])) {
                reservations[i+1] = reservations[i];

                if(i == 0) {
                  reservations[i] = newRes;
                  numReservations++;
                  added = true;
                  break;
                }
              }

              else {
                reservations[i+1] = newRes;
                numReservations++;
                added = true;
                break;
              }
            }

            if(numReservations == 0) {
              reservations[numReservations++] = newRes;
              added = true;
            }

            if(added) {
              int points;
              hotRoom->computePoints(points);
              points *= stay;
              newGuest->addPts(points);
              notify(newRes);
              return;
            }
        }

        else {
          delete newDate;
          cout<<"ERROR: Guest "<<name<<" does not exist"<<endl;
          return;
        }
      }
    }
  }
  cout<<"ERROR: Registration request for "<<name<<", "; newDate->print();
  cout<<": No room of matching type available"<<endl;
  delete newDate;
}

void ResManager::subscribe(Recorder* r) {
  recorders.push_back(r);
}

void ResManager::print() const {
  for(int i = 0; i < numReservations; i++) {
    cout<<endl;
    reservations[i]->print();
  }
}

void ResManager::printRecords() const {
  for(int i = 0; i < recorders.size(); i++) {
    recorders[i]->printRecords();
    cout<<endl;
  }
}

void ResManager::notify(Reservation* r) {
  for(int i = 0; i < recorders.size(); i++) {
    recorders[i]->update(r);
  }
}
