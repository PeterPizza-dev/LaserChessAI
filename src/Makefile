CC = g++

# compiler flags
CFLAGS = -lGL -lGLU -lglut -lstdc++ 

COMPILE_SOURCES = game.cpp piece.cpp

TARGET = main.cpp

all: $(TARGET)
	$(CC) $(TARGET) $(COMPILE_SOURCES) -o laserChess $(CFLAGS)

clean:
	$(RM) laserChess
