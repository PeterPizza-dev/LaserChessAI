#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

void initGrid(int,int);
//This is used to sepcifiy the number of grids (Here it is 10, which is static, but could be changed from main.cpp)

void drawBoard();
//this is used to draw the static board

void drawPieces();
//TODO:
//This will be used draw all the live pieces in the game
//Here we would need to pair the geometric figure with the class
//And the player that this piece belongs to.


#endif // GAME_H_INCLUDED