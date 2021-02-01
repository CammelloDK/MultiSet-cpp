CXX=g++
SRC=multiset.h coppia.h main.cpp
OBJ=$(SRC:.cpp=.o)
EXEC=844796

all:$(EXEC)

$(EXEC):$(OBJ)
	$(CXX) -o $@ $^

cleanexe:
	rm -rf $(EXEC) 

cleanjunk:
	rm -rf *.o

clean: cleanjunk cleanexe
