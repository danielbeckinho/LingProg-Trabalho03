CXX = g++
CXXFLAGS = -Wall -g

mainProgram: mainProgram.o structFilme.o catalogo.o persistenciaCatalogo.o
	$(CXX) $(CXXFLAGS) -o mainProgram mainProgram.o structFilme.o catalogo.o persistenciaCatalogo.o

mainProgram.o: mainProgram.cpp structFilme.o catalogo.o persistenciaCatalogo.o
	$(CXX) $(CXXFLAGS) -c mainProgram.cpp

structFilme.o: structFilme.h 

catalogo.o: catalogo.h structFilme.h 

persistenciaCatalogo.o: persistenciaCatalogo.h catalogo.h
