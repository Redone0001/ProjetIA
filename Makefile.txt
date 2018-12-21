TARGET  = $(wildcard *.cpp)
PROG    = $(TARGET:.cpp=.out)
INCLUDE = $(wildcard src/*.cpp)
OBJ     = $(INCLUDE:.cpp=.o)


CC  = g++
CFL = -Wall -O3 -std=c++11

all: $(OBJ) $(PROG)
	@echo "All done!"

%.out:%.cpp $(OBJ) 
	@echo "Compiling $@ from $^"
	$(CC) $(CFL)  $^ -o $@


%.o:%.cpp
	@echo "Compiling dependency $@ from $^"
	$(CC) $(CFL) $^ -c -o $@


.PHONY: clean

clean:
	@rm $(PROG)
	@rm $(OBJ)
