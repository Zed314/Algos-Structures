OBJ=main.o TasBinaire.o
COMPFLAGS=-std=c++11
programme : $(OBJ)
	g++ $(COMPFLAGS) -o programme $(OBJ)

main.o : main.cpp TasBinaire.h
	g++ $(COMPFLAGS) -c main.cpp

TasBinaire.o: TasBinaire.cpp TasBinaire.h
	g++ $(COMPFLAGS) -c TasBinaire.cpp
clean:
	rm $(OBJ)

