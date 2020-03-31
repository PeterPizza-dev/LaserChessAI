#ifndef AI_H_
#define AI_H_

#include "Board.h"

struct Move
{
    int pieceX, pieceY, move;
};


class AI {
public:
	AI(bool status);
	bool isActive;
	int utility(Board board);
	int miniMax(Board board, int depth, bool MaxPlayer);
	Move findMove(Board board);
};

#endif /* AI_H_ */
