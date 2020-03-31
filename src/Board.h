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
	int debug_counter = 0;


public:
	bool Blue_turn;
	bool Blue_win;
	bool Game_done;
	int score;
	std::vector <piece*> BlueActive;
	std::vector <piece*> RedActive;

	Board();
	~Board();
	Board(const Board& old_board);
	int gameDialog();
	void init_ace(void);
	int** getstate(void);
	int** getLaserTrack(void);
	bool ComputerVsComputer();
	bool PlayerVsComputer();
	bool PlayerVsPlayer();
	void update_board();
	void Delete_active_vector();
	int Do_action(int,int);
	void update_laser();


private:
	void playerChoiceDialog();
	int move( int index_piece, direction move_direc, bool print);
	int turn( int index_piece, direction turn_direc);
	void validMove(int index_piece, int x, int y, bool *ret_safe_move, bool *ret_piece_there, bool print);
	void updateRedAndBlueActive();
	void calculate_score();
	void switch_pieces(int index_piece, int x, int y);
	int search( int PosX, int PosY);

};




#endif

