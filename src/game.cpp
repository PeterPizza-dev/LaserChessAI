#include <GL/freeglut.h>
#include <stdlib.h>
#include "game.h"


int gridX,gridY;

int play_board[10][8] = 
    {{2,2,2,2,2,2,2,0},
     {1,0,0,0,0,0,0,1},
     {0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0},
     {2,0,0,0,0,0,0,2},
     {0,1,1,1,1,1,1,1}};




void sq_unit(int,int);
void white_area(int,int);
void red_area(int,int);
void laser();
void Deflector(int,int,int);
void Defender(int,int,int);
void Switch(int,int,int);
void King(int,int,int);

void initGrid(int x, int y){
    gridX = x;
    gridY = y;
}

void drawBoard(){
    for (int i=0; i<gridX;i++){
        for (int j=0;j<gridY;j++){
            sq_unit(i,j);
            if (play_board[i][j] == 1){
                white_area(i,j);
            }else if (play_board[i][j] == 2){
                red_area(i,j);
            }
        }
    }
}

void drawPieces(){
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_QUADS);
        glVertex2f(4,4);
        glVertex2f(5,4);
        glVertex2f(5,5);
        glVertex2f(4,5);
    glEnd();
}

void white_area(int x, int y){
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
        glVertex2f(x+0.3,y+0.3);
        glVertex2f(x+0.7,y+0.3);
        glVertex2f(x+0.7,y+0.7);
        glVertex2f(x+0.3,y+0.7);
    glEnd();
}

void red_area(int x, int y){
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex2f(x+0.3,y+0.3);
        glVertex2f(x+0.7,y+0.3);
        glVertex2f(x+0.7,y+0.7);
        glVertex2f(x+0.3,y+0.7);
    glEnd();
}

void sq_unit(int x, int y){
   //int gridWidth = glutGet(GLUT_WINDOW_WIDTH)/gridX;
   //int gridHeight = glutGet(GLUT_WINDOW_HEIGHT)/gridY;
    glLineWidth(1.5);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x,y);
        glVertex2f(x+1,y);
        glVertex2f(x+1,y+1);
        glVertex2f(x,y+1);
    glEnd();
    if (x == gridX-1 && y == gridY-1){
        glLineWidth(1.5);
        glColor3f(0.0,1.0,0.0);
        glBegin(GL_LINE_LOOP);
            glVertex2f(0,0);
            glVertex2f(gridX,0);
            glVertex2f(gridX,gridY);
            glVertex2f(0,gridY);
        glEnd();
    }
     
}