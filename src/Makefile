CXX = g++
CXXFLAGS = -g -std=c++11

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

all: main

OBJECTS = main.o menu.o player.o
main: $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS)


clean: 
	$(RM) *.o main