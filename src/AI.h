#ifndef AI_H_
#define AI_H_

#include "Board.h"

struct Move
{
    int piece, move;
};


class AI {
public:
	//AI constructor
	AI(bool isBlue);
	//Bool value to toggle colour of the AI
	bool isBlue;
	//Alpha betas for pruning
	int alpha;
	int beta;
	int COUNT;
	//Evaluation function for the Game state
	int utility(Board board);

	//Normal adversial minimax search
	int miniMax(Board board, int depth, bool MaxPlayer);
	//First Max step of the Minimax, returns a type of struct Move
	Move findMove(Board board);

	//Max and min fnctions for the minimax Alpha-Beta pruning
	int Max_Value(Board board, int depth, int a, int b);
	int Min_Value(Board board, int depth, int a, int b);
	//First Max step of the Minimax w. alpha beta pruning, returns a type of struct Move
	Move findMove_AB(Board board);


};

#endif /* AI_H_ */
