#include <GL/freeglut.h>
#include <stdlib.h>
#include <iostream>
#include "game.h"
#include "piece.h"

//Run it with: gcc main.cpp game.cpp piece.cpp -o laserChess -lGL -lGLU -lglut -lstdc++
//Simplification (Laser only shoot along north (for blue) and south (for red)
//Simplification (You can only move the pieces, you can change their orientation)


#define COLUMNS 10
#define ROWS 8

GLint Width = 800, Height = 650;

const int CubeSize = 200;

GLuint texture;

void Display_callback();
void reshape_callback(int,int);

void Keyboard_event(unsigned char key, int x, int y);
void Mouse_event(int button, int state, int x, int y);
void init();


//Template state

int state[COLUMNS][ROWS] = 
    {{0,0,0,-(20+E),-(20+N),0,0,-10},
     {0,0,0,0,0,0,0,0},
     {(20+W),0,0,(20+W),(20+S),0,-(20+S),0},
     {(30+N),0,0,0,0,(20+W),0,0},
     {50,0,0,(40+W),-(40+N),0,0,-(30+S)},
     {(30+N),0,0,(40+S),-(40+E),0,0,-50},
     {0,0,-(20+E),0,0,0,0,-(30+S)},
     {0,(20+N),0,-(20+N),-(20+E),0,0,-(20+E)},
     {0,0,0,0,0,0,0,0},
     {10,0,0,(20+S),(20+W),0,0,0}};


main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(Width, Height);
    glutCreateWindow("Laser Chess");
    glutReshapeFunc(reshape_callback);
    glutDisplayFunc(Display_callback);
    glutKeyboardFunc(Keyboard_event);
    glutMouseFunc(Mouse_event);
    init();
    glutMainLoop();
}


void init(){
    glClearColor(0.6f,0.6f,0.6f,1.0);
    initGrid(COLUMNS,ROWS);
    
}


void reshape_callback(int w, int h){
    glViewport(0,0,(GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);

}

void Display_callback(){
    glClear(GL_COLOR_BUFFER_BIT);
    drawBoard();
    drawPieces(state);
    glutSwapBuffers();
}

void Keyboard_event(unsigned char key, int x, int y){
    if(key==27){
        exit(0);
    }
}

void Mouse_event(int button, int state, int x, int y){
    
}