#include <GL/freeglut.h>
#include <stdlib.h>
#include "game.h"
#include "Board.h"
#include "piece.h"
#include <iostream>
#include <unistd.h>
#include <regex>
#include "AI.h"


using namespace std;
//Run it with: gcc main.cpp game.cpp -o laserChess -lGL -lGLU -lglut


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
void call_draw_functions();

bool gameDone = false;
int gameMode;
Board Game;
AI computer(true);
//Template state

int state[ROWS][COLUMNS] = 
    {{-10,0,0,0,-(30+S),-50,-(30+S),-(20+E),0,0},
     {0,0,-(20+S),0,0,0,0,0,0,0},
     {0,0,0,(20+W),0,0,0,0,0,0},
     {-(20+N),0,(20+S),0,-(40+N),-(40+E),0,-(20+E),0,(20+W)},
     {-(20+E),0,(20+W),0,(40+W),(40+S),0,-(20+N),0,(20+S)},
     {0,0,0,0,0,0,-(20+E),0,0,0},
     {0,0,0,0,0,0,0,(20+N),0},
     {0,0,(20+W),(30+N),50,(30+N),0,0,0,10}};


int main(int argc, char* argv[])
{
	cout<<"LETS GO"<<endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(Width, Height);
    glutCreateWindow("Laser Chess");
    glutReshapeFunc(reshape_callback);
    glutDisplayFunc(Display_callback);
    glutKeyboardFunc(Keyboard_event);
    init();


    glutMainLoop();
    return 0;
}


void init(){
    gameMode = Game.gameDialog();
    //From the seeting what init do we need
    Game.init_ace();
    Game.update_board();
    gameDone = false;

    glutIdleFunc(Display_callback);
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
void call_draw_functions(){
    glClear(GL_COLOR_BUFFER_BIT);
    drawBoard();
    drawPieces(Game.getstate());
    //drawLaserTrack(Game.getLaserTrack(),Game.Blue_turn);
    glutSwapBuffers();
}

void AI_move(){
        Move AI = computer.findMove(Game);
        Game.Do_action(AI.piece, AI.move);
        Game.update_board();
        Game.update_laser(true);
        Game.update_board();
        if(Game.Blue_turn){Game.Blue_turn=false;}
	    else{Game.Blue_turn=true;}
}

void Display_callback(){
    if(!gameDone){
        call_draw_functions();
        switch(gameMode){
            case 1:
                gameDone = Game.PlayerVsPlayer();
                if(gameDone){
                    call_draw_functions();
                }
                break;
            case 2:
                if (Game.Blue_turn){
                    AI_move();
                    gameDone = Game.Game_done;
                }else{
                    gameDone = Game.PlayerVsComputer();
                }
                if(gameDone){
                    call_draw_functions();
                }
                break;
            case 3:
                Game.ComputerVsComputer();
                break;
            default:
                break;
        }
    }else{
        glutIdleFunc(NULL);
        Game.Delete_active_vector();
        Game.Blue_turn = true;
        if(Game.Blue_win){cout << "Blue wins the game, congratz, wanna try again? [y/n]" << endl;}
        else{cout << "Red wins the game, congratz, wanna try again? [y/n]" << endl;}
        string input;
        getline(cin, input);
        input = tolower(input[0]);
        regex regex_pattern("[y,n]");
        if(!regex_match(input,regex_pattern)){
            Display_callback();
        }else{
            char in = input[0];
            if(in == 'n'){
                exit(0);
            }else{init();}
            
        }
    }
}

void Keyboard_event(unsigned char key, int x, int y){
    if(key==27){
        exit(0);
    }
}


