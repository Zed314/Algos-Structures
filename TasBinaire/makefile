OBJ=main.o TasBinaire.o
COMPFLAGS=-std=c++11 -Wall
programme : $(OBJ)
	g++ $(COMPFLAGS) -o programme $(OBJ)

main.o : main.cpp TasBinaire.h
	g++ $(COMPFLAGS) -c main.cpp

TasBinaire.o: TasBinaire.tpp TasBinaire.h
	g++ $(COMPFLAGS) -c TasBinaire.h
clean:
	rm $(OBJ)

