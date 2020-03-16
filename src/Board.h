#ifndef Board_H_
#define Board_H_

#include <iostream> 
#include <vector> 
#include <string>
#include "piece.h"

class Board {
protected:
	int field[8][10];
	vector<piece*> Active;

public:
	Board();
	~Board();
	int* update_board(Board Playing);
	void display_board(Board Playing);
	void init_ace(void);
};


#endif Board_H_
