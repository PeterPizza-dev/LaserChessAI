CC = g++

# compiler flags for the various OS
ifeq ($(OS),Windows_NT)
    CFLAGS += -D WIN32
    ifeq ($(PROCESSOR_ARCHITEW6432),AMD64)
        CFLAGS += -D AMD64
    else
        ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
            CFLAGS += -D AMD64
        endif
        ifeq ($(PROCESSOR_ARCHITECTURE),x86)
            CFLAGS += -D IA32
        endif
    endif
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CFLAGS += -lGL -lGLU -lglut -lstdc++ 
        outputname = laserChess_Linux
    endif
    ifeq ($(UNAME_S),Darwin)
        CFLAGS += -framework OpenGL -framework GLUT
        outputname = laserChess_MAC
	endif
endif

COMPILE_SOURCES = game.cpp piece.cpp Board.cpp AI.cpp

TARGET = main.cpp

all: $(TARGET)
	$(CC) $(TARGET) $(COMPILE_SOURCES) -o $(outputname) $(CFLAGS)

clean:
	$(RM) $(outputname)
