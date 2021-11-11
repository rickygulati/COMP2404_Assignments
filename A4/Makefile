OBJ = main.o Control.o Date.o Guest.o GuestRecorder.o Hotel.o Recorder.o Reservation.o ResManager.o Room.o RoomArray.o StayRecorder.o UpgradeRecorder.o View.o

A4: $(OBJ)
	g++ -o A4 $(OBJ)

main.o: main.cc Control.h
	g++ -c main.cc

Control.o: Control.cc Control.h
	g++ -c Control.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

Guest.o: Guest.cc Guest.h
	g++ -c Guest.cc

GuestRecorder.o: GuestRecorder.cc GuestRecorder.h
	g++ -c GuestRecorder.cc

Hotel.o: Hotel.cc Hotel.h
	g++ -c Hotel.cc

Recorder.o: Recorder.cc Recorder.h
	g++ -c Recorder.cc

Reservation.o: Reservation.cc Reservation.h
	g++ -c Reservation.cc

ResManager.o: ResManager.cc ResManager.h
	g++ -c ResManager.cc

Room.o: Room.cc Room.h
	g++ -c Room.cc

RoomArray.o: RoomArray.cc RoomArray.h
	g++ -c RoomArray.cc

StayRecorder.o: StayRecorder.cc StayRecorder.h
	g++ -c StayRecorder.cc

UpgradeRecorder.o: UpgradeRecorder.cc UpgradeRecorder.h
	g++ -c UpgradeRecorder.cc

View.o: View.cc View.h
	g++ -c View.cc

clean:
	rm -f *.o A4
