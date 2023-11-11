fillarrayapp: fillArrayLib.o fillArrayApp.o
	g++ -o fillarrayapp fillArrayLib.o fillArrayApp.o

fillArrayLib.o: fillArrayLib.cpp fillArray.h
	g++ -c fillArrayLib.cpp

fillArrayApp.o: fillArrayApp.cpp fillArray.h
	g++ -c fillArrayApp.cpp

clean:
	rm -f fillarrayapp FillArrayApp.cpp

