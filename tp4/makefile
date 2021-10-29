all: executable.out

executable.out: main.o Expression.o Constante.o Plus.o Moins.o Mult.o
	g++ -g main.o Expression.o Constante.o Plus.o Moins.o Mult.o -o executable.out

main.o: main.cpp Expression.hpp Constante.hpp Plus.hpp Moins.hpp Mult.hpp
	g++ -g -c main.cpp

Expression.o: Expression.hpp Expression.cpp
	g++ -g -c Expression.cpp

Constante.o: Constante.hpp Constante.cpp Expression.hpp
	g++ -g -c Constante.cpp

Plus.o: Plus.hpp Plus.cpp Expression.hpp
	g++ -g -c Plus.cpp

Moins.o: Moins.hpp Moins.cpp Expression.hpp
	g++ -g -c Moins.cpp

Mult.o: Mult.hpp Mult.cpp Expression.hpp
	g++ -g -c Mult.cpp

clean:
	rm *.o

veryclean: clean
	rm *.out