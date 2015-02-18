BIN = pawng
CC = g++
OBJS = main.cpp Game.hpp Game.cpp GameObject.hpp GameObject.cpp GameObjectManager.hpp GameObjectManager.cpp Player.hpp Player.cpp Ball.hpp Ball.cpp
CFLAGS = -w
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all : $(OBJS)
	$(CC) -fdiagnostics-color $(OBJS) $(CFLAGS) $(LFLAGS) -o $(BIN)
