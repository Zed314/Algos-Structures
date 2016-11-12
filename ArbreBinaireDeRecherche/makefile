OBJ= main.o Abr.o File.o	
COMPFLAGS=-std=c++11 -Wall
programme : $(OBJ)
	g++ $(COMPFLAGS) -o programme $(OBJ)

main.o : main.cpp Abr.h File.h
	g++ $(COMPFLAGS) -c main.cpp

Abr.o : Abr.h Abr.cpp File.h
	g++ $(COMPFLAGS) -c Abr.cpp

File.o : File.h File.cpp
	g++ $(COMPFLAGS) -c File.cpp
clean : 
	rm $(OBJ)
