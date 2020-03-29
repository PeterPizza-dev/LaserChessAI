#ifndef AI_H_
#define AI_H_

#include "Board.h"

struct Move
{
    int piece, move;
};


class Ai {
protected:
	bool turn;
	Move;
public:
	Ai();
	int miniMax(Board board, int depth, bool MaxPlayer);
	Move findMove(Board board);
};

#endif /* AI_H_ */
