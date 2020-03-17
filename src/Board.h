#ifndef Board_H_
#define Board_H_

#include <vector> 
#include "piece.h"

class Board {
protected:
	int** field = 0;
	int ROWS = 8;
	int COLUMNS = 10;
	std::vector <piece*> Active;


public:
	bool Blue_turn;
	Board();
	void update_board();
	void display_board();
	void init_ace(void);
	void RTurn( int PosX, int PosY, direction move_direc, direction turn_direc);
	void BTurn( int PosX, int PosY, direction move_direc, direction turn_direc);
	int search( int PosX, int PosY);
	int move( int index_direc, direction move_direc);
	int turn( int index_direc, direction turn_direc);
	int** getstate(void);


};


#endif Board_H_

