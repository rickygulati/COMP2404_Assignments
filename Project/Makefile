fp: main.o Record.o CompareBehaviour.o Map.o ReportData.o ReportGenerator.o Control.o View.o
	g++ -o fp main.o Record.o CompareBehaviour.o Map.o ReportData.o ReportGenerator.o Control.o View.o

main.o: main.cc
	g++ -c main.cc

CompareBehaviour.o: CompareBehaviour.cc CompareBehaviour.h
	g++ -c CompareBehaviour.cc

Control.o: Control.cc Control.h
	g++ -c Control.cc

Map.o: Map.cc Map.h
	g++ -c Map.cc

Record.o: Record.cc Record.h
	g++ -c Record.cc

ReportData.o: ReportData.cc ReportData.h
	g++ -c ReportData.cc

ReportGenerator.o: ReportGenerator.cc ReportGenerator.h
	g++ -c ReportGenerator.cc

View.o: View.cc View.h
	g++ -c View.cc

clean:
	rm -f *.o fp
