Lab7: main.o SortDriver.o NumberFileDriver.o NumberFileGenerator.o
	g++ -g -std=c++11 -Wall -o Lab7 main.o SortDriver.o NumberFileDriver.o NumberFileGenerator.o

main.o: main.cpp Sorts.h Sorts.hpp
	g++ -g -std=c++11 -Wall -c main.cpp

SortDriver.o: SortDriver.h SortDriver.cpp
	g++ -g -std=c++11 -Wall -c SortDriver.h SortDriver.cpp

NumberFileDriver.o: NumberFileDriver.h NumberFileDriver.cpp
	g++ -g -std=c++11 -Wall -c NumberFileDriver.h NumberFileDriver.cpp

NumberFileGenerator.o: NumberFileGenerator.h NumberFileGenerator.cpp
	g++ -g -std=c++11 -Wall -c NumberFileGenerator.h NumberFileGenerator.cpp

clean:
	rm *.o Lab7
	echo clean done
