CXX = gcc
CFLAGS = -g -Wall 
OBJ = main_program.o followed by header_program.o
EXE = name_yo_file

all: $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(EXE)

.cpp.o:
	$(CXX)	$(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(EXE)
