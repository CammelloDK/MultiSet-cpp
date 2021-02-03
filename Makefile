CXX=g++
SRC=multiset.h coppia.h main.cpp
OBJ=$(SRC:.cpp=.o)
EXEC=844796

all:$(EXEC)

$(EXEC):$(OBJ)
	$(CXX) -o $@ $^ -std=c++0x

cleanexe:
	rm -rf $(EXEC) 

cleanjunk:
	rm -rf *.o

clean: cleanjunk cleanexe
