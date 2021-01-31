main.exe: main.o
	g++ main.o -o main.exe

main.o: main.cpp multiset.h coppia.h
	g++ -c main.cpp -o main.o

clean:
	rm *.o *.exe
