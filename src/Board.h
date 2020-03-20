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
	void display_board();
	int gameDialog();
	void init_ace(void);
	int** getstate(void);
	bool ComputerVsComputer();
	bool PlayerVsComputer();
	bool PlayerVsPlayer();

private:
	void playerChoiceDialog();
	void update_board();
	int move( int index_piece, direction move_direc);
	int turn( int index_piece, direction turn_direc);
	bool validMove(int index_piece, int x, int y);


	int search( int PosX, int PosY);
	void RTurn( int PosX, int PosY, direction move_direc, direction turn_direc);
	void BTurn( int PosX, int PosY, direction move_direc, direction turn_direc);

};


#endif

