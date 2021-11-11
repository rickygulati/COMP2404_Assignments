Author: Ricky Gulati (101146071)
Purpose: This program is designed for assignment 4 of COMP2404A for Winter 2021 term.
         The program implements a program to manage a hotel. The hotel will have multiple rooms of different types, including a suite, some
         premium rooms, and regular rooms. The hotel will also keep track of the multiple guests that stay at the hotel.
         The reservations will be managed by a separate control-like object, that serves as the reservation manager.
         When a new reservation is requested, the reservation manager will be responsible for determining which room
         of the requested type is available for the duration of the guest’s stay.

List of source and header files:
  1. Control.cc
  2. Control.h
  3. Date.cc
  4. Date.h
  5. defs.h
  6. Guest.cc
  7. Guest.h
  8. GuestRecorder.cc
  9. GuestRecorder.h
  10. Hotel.cc
  11. Hotel.h
  12. main.cc
  13. Recorder.cc
  14. Recorder.h
  15. Reservation.cc
  16. Reservation.h
  17. ResManager.cc
  18. ResManager.h
  19. Room.cc
  20. Room.h
  21. RoomArray.cc
  22. RoomArray.h
  23. StayRecorder.cc
  24. StayRecorder.h
  25. UpgradeRecorder.cc
  26. UpgradeRecorder.h
  27. View.cc
  28. View.h

Other files:
  Makefile
  README.TXT
  UMLDiagram.pdf

Compiling and launching instructions:
To compile and create the executable, use either of the following commands: make A4
                                                                            make

To delete all object files and the executable, use the following command: make clean
