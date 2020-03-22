#ifndef Board_H_
#define Board_H_

#include <vector> 
#include "piece.h"


class Board {
protected:
	int** field = 0;
	int** laser_track = 0;
	int ROWS = 8;
	int COLUMNS = 10;
	std::vector <piece*> Active;


public:
	bool Blue_turn;
	bool Blue_win;
	bool Game_done;
	Board();
	int gameDialog();
	void init_ace(void);
	int** getstate(void);
	int** getLaserTrack(void);
	bool ComputerVsComputer();
	bool PlayerVsComputer();
	bool PlayerVsPlayer();
	void update_board();
	void Delete_active_vector();


private:
	void playerChoiceDialog();
	void update_laser();
	int move( int index_piece, direction move_direc);
	int turn( int index_piece, direction turn_direc);
	void validMove(int index_piece, int x, int y, bool *ret_safe_move, bool *ret_piece_there);

	void switch_pieces(int index_piece, int x, int y);
	int search( int PosX, int PosY);
	void RTurn( int PosX, int PosY, direction move_direc, direction turn_direc);
	void BTurn( int PosX, int PosY, direction move_direc, direction turn_direc);

};




#endif

