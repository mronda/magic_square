CC = g++ -O2 -Wno-deprecated -std=c++11

all: Matrix

Matrix: pa1.o 
	g++ pa1.o -o Matrix

pa1.o: pa1.cpp
	g++ -c pa1.cpp

clean:
	rm pa1.o Matrix