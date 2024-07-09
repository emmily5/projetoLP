Astronauta.o: Astronauta.cpp Astronauta.hpp
	g++ -c Astronauta.cpp -o Astronauta.o

Voo.o: Voo.cpp Voo.hpp
	g++ -c Voo.cpp -o Voo.o

Sistema.o: Sistema.cpp Sistema.hpp
	g++ -c Sistema.cpp -o Sistema.o

final: main.cpp Astronauta.o Voo.o Sistema.o
	g++ main.cpp Astronauta.o Voo.o Sistema.o -o final.exe

limpar:
	del *.o final.exe