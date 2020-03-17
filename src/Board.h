#ifndef Board_H_
#define Board_H_

#include <vector> 
#include "piece.h"

class Board {
protected:
	int field[8][10];
	std::vector <piece*> Active;

public:
	bool Blue_turn;
	Board();
	void update_board(Board Playing);
	void display_board(Board Playing);
	void init_ace(void);
	void RTurn(Board Playing, int PosX, int PosY, direction move, direction turn);
	void BTurn(Board Playing, int PosX, int PosY, direction move, direction turn);
	int search(Board Playing, int PosX, int PosY);
	int move(Board Playing, int index, direction move);
	int turn(Board Playing, int index, direction turn);
	int* getstate(void);
};


#endif Board_H_

