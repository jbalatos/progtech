CC=g++

CFLAGS=-g -Wall -O2 -std=c++11

TARGET=index

clean:
	rm *.o $(TARGET)

all: $(TARGET).o move.o  state.o player.o greedy.o righteous.o sneaky.o spartan.o game.o
	$(CC) -o $(TARGET) $(TARGET).o move.o state.o player.o greedy.o righteous.o sneaky.o spartan.o game.o

$(TARGET): $(TARGET).cpp greedy.cpp righteous.cpp sneaky.cpp spartan.cpp game.hpp
	$(CC) $(CFLAGS) -c $(TARGET).cpp

move: move.cpp move.hpp
	$(CC) $(CFLAGS) -c move.cpp

state: state.cpp state.hpp move.hpp
	$(CC) $(CFLAGS) -c state.cpp

player: player.cpp player.hpp state.hpp
	$(CC) $(CFLAGS) -c player.cpp

greedy: greedy.cpp player.hpp
	$(CC) $(CFLAGS) -c greedy.cpp

righteous: righteous.cpp player.hpp
	$(CC) $(CFLAGS) -c righteous.cpp

sneaky: sneaky.cpp player.hpp
	$(CC) $(CFLAGS) -c spartan.cpp

game: game.cpp game.hpp move.hpp state.hpp player.hpp
	$(CC) $(CFLAGS) -c game.cpp
