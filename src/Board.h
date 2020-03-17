#ifndef Board_H_
#define Board_H_

#include <vector> 
#include "piece.h"

class Board {
protected:
	int field[8][10];

	//std::vector <piece*> Active;

public:
	Board();
	~Board();
	void update_board(Board Playing);
	void display_board(Board Playing);
	void init_ace(void);

	std::vector <piece*> Active;
};


#endif Board_H_

