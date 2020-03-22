#include <GL/freeglut.h>
#include <stdlib.h>
#include <iostream>
#include "game.h"
#include "piece.h"

int gridX,gridY;



// All these classes are meant to draw the pieces to the gameboard
// It is assumed that a 2D array (Matrix) is inputted to the drawPieces
// such that the pieces with correct color, and orientation can be drawn.
// the color is assumed to be -5 (red) 5 (blue).

int play_board[8][10] =
    {{0,1,0,0,0,0,0,0,2,1},
     {2,0,0,0,0,0,0,0,0,1},
     {2,0,0,0,0,0,0,0,0,1},
     {2,0,0,0,0,0,0,0,0,1},
     {2,0,0,0,0,0,0,0,0,1},
     {2,0,0,0,0,0,0,0,0,1},
     {2,0,0,0,0,0,0,0,0,1},
     {2,1,0,0,0,0,0,0,2,0}};


void sq_unit(int,int);
void white_area(int,int);
void red_area(int,int);
void Laser(int,int,int);
void Deflector(int,int,direction,int);
void Defender(int,int,direction,int);
void Switch(int,int,direction,int);
void King(int,int,int);
void draw_laser(int,int,int,int);

void initGrid(int x, int y){
    gridX = x;
    gridY = y;
}

void drawBoard(){
    for (int i=0; i<gridX;i++){
        for (int j=0;j<gridY;j++){
            sq_unit(i,j);
            if (play_board[j][i] == 1){
                white_area(i,(gridY-1)-j);
            }else if (play_board[j][i] == 2){
                red_area(i,(gridY-1)-j);
            }
        }
    }
}

void drawPieces(int** state){ 
    for (int i=0; i<gridX;i++){
        for (int j=0;j<gridY;j++){
            int piece = state[j][i];
            switch((int)(abs(piece) / 10)){
                case 1:
                    Laser(i,(gridY-1)-j,piece);
                    break;

                case 2:
                    Deflector(i,(gridY-1)-j,direction(abs(piece) % 10),piece);
                    break;
                
                case 3:
                    Defender(i,(gridY-1)-j,direction(abs(piece ) % 10),piece);
                    break;
                
                case 4:
                    Switch(i,(gridY-1)-j,direction(abs(piece) % 10),piece);
                    break;
                
                case 5:
                    King(i,(gridY-1)-j,piece);
                    break;
                
                default:
                    break;

            }
        }
    }
}

void drawLaserTrack(int** laser_track, bool Blue_turn){
    int x_prev,y_prev;
    if(Blue_turn){

        for (int i=0; i<gridX;i++){
            for (int j=0;j<gridY;j++){
            if (laser_track[j][i] == 1){
                draw_laser(i,(gridY-1)-j,x_prev,y_prev );
                x_prev = i;
                y_prev = j;
                }
            }
        }
    }

}

void draw_laser(int x, int y, int x_prev, int y_prev){
    glColor3f(0.0,1.0,0.0);
    glLineWidth(5);
    glBegin(GL_LINE);
        glVertex2f(x+0.5,y);
        glVertex2f(x+0.5,y+1);
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
    glColor3f(.8,0.0,0.0);
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

void Laser(int x, int y, int color){
    if (color > 0) {
        glColor3f(1.0,0.0,0.0);
    }else{
        glColor3f(0.0,0.0,1.0);
    }
    glBegin(GL_POLYGON);
        glVertex2f(x+0.3,y+0.2);
        glVertex2f(x+0.7,y+0.2);
        glVertex2f(x+0.8,y+0.3);
        glVertex2f(x+0.8,y+0.7);
        glVertex2f(x+0.7,y+0.8);
        glVertex2f(x+0.3,y+0.8);
        glVertex2f(x+0.2,y+0.7);
        glVertex2f(x+0.2,y+0.3);
    glEnd();
    
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
        if (color > 0){
            glVertex2f(x+0.3,y+0.2);
            glVertex2f(x+0.7,y+0.2);
            glVertex2f(x+0.5,y+0.05);  
        }else{  
            glVertex2f(x+0.3,y+0.8);
            glVertex2f(x+0.7,y+0.8);
            glVertex2f(x+0.5,y+0.95);  
        }
    glEnd();
}

void Deflector(int x, int y, direction orientation, int color){
    if (color > 0) {
        glColor3f(1.0,0.0,0.0);
    }else{
        glColor3f(0.0,0.0,1.0);
    }
    switch (orientation)
    {
    case W:
        glBegin(GL_TRIANGLES);
            glVertex2f(x+0.1,y+0.1);
            glVertex2f(x+0.9,y+0.1);
            glVertex2f(x+0.9,y+0.9);
        glEnd();
        break;
    
    case N:
        glBegin(GL_TRIANGLES);
            glVertex2f(x+0.1,y+0.1);
            glVertex2f(x+0.9,y+0.1);
            glVertex2f(x+0.1,y+0.9);
        glEnd();
        break;
    
    case E:
        glBegin(GL_TRIANGLES);
            glVertex2f(x+0.1,y+0.1);
            glVertex2f(x+0.9,y+0.9);
            glVertex2f(x+0.1,y+0.9);
        glEnd();
        break;

    case S:
        glBegin(GL_TRIANGLES);
            glVertex2f(x+0.9,y+0.1);
            glVertex2f(x+0.9,y+0.9);
            glVertex2f(x+0.1,y+0.9);
        glEnd();
        break;
    
    default:
        break;
    }
    
}    

void Defender(int x, int y, direction orientation, int color){
    if (color > 0) {
        glColor3f(1.0,0.0,0.0);
    }else{
        glColor3f(0.0,0.0,1.0);
    }
    glBegin(GL_QUADS);
            glVertex2f(x+0.1,y+0.1);
            glVertex2f(x+0.9,y+0.1);
            glVertex2f(x+0.9,y+0.9);
            glVertex2f(x+0.1,y+0.9);
    glEnd();
    glColor3f(0.0,1.0,0.0);
    switch (orientation)
    {
    case N:
        glBegin(GL_QUADS);
            glVertex2f(x+0.05,y+0.9);
            glVertex2f(x+0.95,y+0.9);
            glVertex2f(x+0.95,y+0.8);
            glVertex2f(x+0.05,y+0.8);
        glEnd();
        break;
    
    case E:
        glBegin(GL_QUADS);
            glVertex2f(x+0.9,y+0.05);
            glVertex2f(x+0.9,y+0.95);
            glVertex2f(x+0.8,y+0.95);
            glVertex2f(x+0.8,y+0.05);
        glEnd();
        break;
    
    case S:
        glBegin(GL_QUADS);
            glVertex2f(x+0.05,y+0.1);
            glVertex2f(x+0.95,y+0.1);
            glVertex2f(x+0.95,y+0.2);
            glVertex2f(x+0.05,y+0.2);
        glEnd();
        break;
    
    case W:
        glBegin(GL_QUADS);
            glVertex2f(x+0.1,y+0.05);
            glVertex2f(x+0.1,y+0.95);
            glVertex2f(x+0.2,y+0.95);
            glVertex2f(x+0.2,y+0.05);
        glEnd();
        break;
    
    default:
        break;
    }
    
}

void King(int x, int y, int color){
    if (color > 0) {
        glColor3f(1.0,0.0,0.0);
    }else{
        glColor3f(0.0,0.0,1.0);
    }
    glBegin(GL_QUADS);
        glVertex2f(x+0.1,y+0.1);
        glVertex2f(x+0.1,y+0.9);
        glVertex2f(x+0.9,y+0.9);
        glVertex2f(x+0.9,y+0.1);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
        glVertex2f(x+0.3,y+0.3);
        glVertex2f(x+0.3,y+0.7);
        glVertex2f(x+0.7,y+0.7);
        glVertex2f(x+0.7,y+0.3);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
        glVertex2f(x+0.4,y+0.4);
        glVertex2f(x+0.4,y+0.6);
        glVertex2f(x+0.6,y+0.6);
        glVertex2f(x+0.6,y+0.4);
    glEnd();
}

void Switch(int x, int y, direction orientation, int color){
    if (color > 0) {
        glColor3f(1.0,0.0,0.0);
    }else{
        glColor3f(0.0,0.0,1.0);
    }
    switch (orientation)
    {
    case W:
        glBegin(GL_POLYGON);
            glVertex2f(x+0.1,y+0.2);
            glVertex2f(x+0.2,y+0.1);
            glVertex2f(x+0.9,y+0.8);
            glVertex2f(x+0.8,y+0.9);
        glEnd();
        break;
    
    case N:
        glBegin(GL_POLYGON);
            glVertex2f(x+0.9,y+0.2);
            glVertex2f(x+0.8,y+0.1);
            glVertex2f(x+0.1,y+0.8);
            glVertex2f(x+0.2,y+0.9);
        glEnd();
        break;

    case E:
        glBegin(GL_POLYGON);
            glVertex2f(x+0.1,y+0.2);
            glVertex2f(x+0.2,y+0.1);
            glVertex2f(x+0.9,y+0.8);
            glVertex2f(x+0.8,y+0.9);
        glEnd();
        break;
    
    case S:
        glBegin(GL_POLYGON);
            glVertex2f(x+0.9,y+0.2);
            glVertex2f(x+0.8,y+0.1);
            glVertex2f(x+0.1,y+0.8);
            glVertex2f(x+0.2,y+0.9);
        glEnd();
        break;

    default:
        break;
    
    }

    
}