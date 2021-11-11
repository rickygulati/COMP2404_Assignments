A2:	main.o Date.o Time.o Call.o Control.o Array.o Subscriber.o Telco.o View.o
	g++ -o A2 main.o Date.o Time.o Call.o Control.o Array.o Subscriber.o Telco.o View.o

main.o:	main.cc Control.h
	g++ -c main.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc

Array.o: Array.cc Array.h
	g++ -c Array.cc

Time.o: Time.cc Time.h
	g++ -c Time.cc

Call.o: Call.cc Call.h
	g++ -c Call.cc

Subscriber.o: Subscriber.cc Subscriber.h
	g++ -c Subscriber.cc

Control.o: Control.cc Control.h
	g++ -c Control.cc

Telco.o: Telco.cc Telco.h
	g++ -c Telco.cc

View.o: View.cc View.h
	g++ -c View.cc

clean:
	rm -f *.o A2
