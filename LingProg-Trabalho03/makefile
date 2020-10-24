CC = g++
CPPFLAGS = -Wall 

OBJECTS = mainProgram.o structFilme.o catalogo.o persistenciaCatalogo.o 

PROGRAM = mainProgram

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o: 
	$(CC) $(CPPFLAGS) -c $<

clean: 
	rm -vf mainProgram *.o
