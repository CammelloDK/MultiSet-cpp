main.exe: main.o
	g++ main.o -o main.exe -std=c++0x

main.o: main.cpp multiset.h coppia.h
	g++ -c main.cpp -o main.o -std=c++0x

cleanexe:
	rm -rf *.exe 

cleanjunk:
	rm -rf *.o

clean: cleanjunk cleanexe

