main: main.cpp shape.so
	g++ main.cpp -Ishape/ -L. shape.so -o main

shape.so : shape.o
	g++ --shared shape.o -o shape.so

shape.o : shape/shape.cpp
	g++ -c -fPIC shape/shape.cpp -o shape.o

clean:
	rm shape.o