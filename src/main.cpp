//#include <GL/freeglut.h>
#include <stdlib.h>
//#include "game.h"
#include "Board.h"
#include "piece.h"
#include <iostream>
using namespace std;
//Run it with: gcc main.cpp game.cpp -o laserChess -lGL -lGLU -lglut

/*
#define COLUMNS 10
#define ROWS 10

GLint Width = 650, Height = 650;

const int CubeSize = 200;

GLuint texture;

void Display_callback();
void reshape_callback(int,int);

void Keyboard_event(unsigned char key, int x, int y);
void Mouse_event(int button, int state, int x, int y);
void init();

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
*/
int main() {
	Board Playing;
	Playing.init_ace();
	std::cout << typeid(Playing.Active[1]).name();
	return 0;
}

/*
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
    drawPieces();
    glutSwapBuffers();
}

void Keyboard_event(unsigned char key, int x, int y){
    if(key==27){
        exit(0);
    }
}

void Mouse_event(int button, int state, int x, int y){
    
}
*/
