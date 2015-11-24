

Homework3:		calculator.o  main.o reader.o writer.o
			g++ -std=c++11 -pthread -Wall *.o -o Homework3


main.o:			main.cpp homework3.h
			g++ -std=c++11 -pthread -Wall -c main.cpp


calculator.o:		calculator.cpp homework3.h
			g++ -std=c++11 -pthread -c calculator.cpp

reader.o:		reader.cpp homework3.h
			g++ -std=c++11 -pthread -c reader.cpp

writer.o:		writer.cpp homework3.h
			g++ -std=c++11 -pthread -Wall -c writer.cpp
