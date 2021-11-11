a1:	main.o Date.o Calendar.o Agenda.o
	g++ -o a1 main.o Date.o Calendar.o Agenda.o

main.o:	main.cc
	g++ -c main.cc

Calendar.o: Calendar.cc
	g++ -c Calendar.cc

Agenda.o: Agenda.cc Agenda.h
	g++ -c Agenda.cc

Date.o:	Date.cc
	g++ -c Date.cc

clean:
	rm -f *.o a1
