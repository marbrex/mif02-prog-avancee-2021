all: executable.out

executable.out: main.o Generator.o
	g++ -g main.o Generator.o -o executable.out

main.o: main.cpp Generator.hpp
	g++ -g -c main.cpp

Generator.o: Generator.hpp Generator.cpp
	g++ -g -c Generator.cpp

clean:
	rm *.o

veryclean: clean
	rm *.out