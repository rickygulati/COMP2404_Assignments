A3: main.o Identifiable.o Animal.o Criteria.o CriteriaArray.o Client.o Match.o MatchList.o MatchListByScore.o MatchListByClient.o Shelter.o Control.o View.o
	g++ -o A3 main.o Identifiable.o Animal.o Criteria.o CriteriaArray.o Client.o Match.o MatchList.o MatchListByScore.o MatchListByClient.o Shelter.o Control.o View.o

main.o: main.cc Control.h
	g++ -c main.cc

Control.o: Control.cc Control.h
	g++ -c Control.cc

Criteria.o: Criteria.cc Criteria.h
	g++ -c Criteria.cc

CriteriaArray.o: CriteriaArray.cc CriteriaArray.h
	g++ -c CriteriaArray.cc

Identifiable.o: Identifiable.cc Identifiable.h
	g++ -c Identifiable.cc

Animal.o: Animal.cc Animal.h defs.h
	g++ -c Animal.cc

Client.o: Client.cc Client.h
	g++ -c Client.cc

Match.o: Match.cc Match.h
	g++ -c Match.cc

MatchList.o: MatchList.cc MatchList.h
	g++ -c MatchList.cc

MatchListByScore.o: MatchListByScore.cc MatchListByScore.h
	g++ -c MatchListByScore.cc

MatchListByClient.o: MatchListByClient.cc MatchListByClient.h
	g++ -c MatchListByClient.cc

Shelter.o: Shelter.cc Shelter.h
	g++ -c Shelter.cc

View.o: View.cc View.h
	g++ -c View.cc

clean:
	rm -f *.o A3
