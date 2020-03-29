
#include <iostream>
#include "Ai.h"
#include "Board.h"

using namespace std;

Ai::Ai() {
	turn = true;
	Move.piece = -1;
	Move.move = -1;
};

int Ai::miniMax(Board board, int depth, bool MaxPlayer){
	//Current value of board

	Temp_board = board.copy();

	int score = board.score;

	if (depth == 3){
		return bestValue;
	}

	//If the node is a leaf node return the vale
	//ALSO include some sort of terminal test
	if(score > 900 || score < -900){
		return score;
	}

	if(MaxPlayer){
		int bestValue = -1000;
		//For every move possible - for each piece
		//Piece
		for(int i=0; i<SIZE.red; i++){
			//For each piece, total number of moves
			for(int j=0; j<10; j++){
				//NODE REPRESENTS THE NODE/NEXT GAME state
				Temp_board.doAction[i, j, 0];
				Temp_board.update_board();

				//UNDO the move - piece back to ORG position.
				bestValue = max(bestValue, miniMax(board, depth+1, false));
			}
		}
		return bestValue;
	}
	else{
		int bestValue = 1000;
		//For every move possible - for each piece
		//Piece
		for(int i=0; i<size.Blue; i++){
			//For each piece, total number of moves
			for(int j=0; j<10; j++){
				Temp_board.doAction[i, j, 0];
				Temp_board.update_board();
				bestValue = min(bestValue, miniMax(board, depth+1, true));
			}
		}
		return bestValue;
	}
}
bool Ai::isTerminalState(int score){
	if(score > 900 || score < -900){
		return true;
	}
	else return false;
}

//Essentially just the first MAX step in miniMax
//Made seperately to extract the move, which max the evaluation function
Move Ai::findMove(Board board){
	int bestValue = -1000;
	Move bestMove;
	bestMove.piece = -1;
	bestMove.move = -1;
	Temp_board = board.copy();

	for(int i=0; i<size.Red; i++){
		//Here the org. position could be saved.
		for(int j=0; j<10; j++){
			// Make the move
			Temp_board.doAction[i, j, 0];
			Temp_board.update_board();
			value = min(bestValue, miniMax(temp_board, depth+1, false));
			//UNDO the move - piece back to ORG position.
			if(value > bestValue){
				bestMove.piece = piece[i];
				bestMove.move = j;
				bestValue = value;
			}
		}
	}
	cout <<"The best move is to move the: "<<bestMove.piece<<" to with the following move "<<bestMove.move<<endl;
	return bestMove;
}

//THIS IS HOW

int utility(Board sate){
	return state.score();
}

int miniMax(Board state){
	v = max_value(state);
	return Move
}

int max_value(Board state){
	if(terminalState) return utility(state);
	v = -1000;
	//Numvbr of pieces in own class
	for(int i=0; i<size.Red; i++){
		//Number of actions possible for given piece
		for(int j=0; j<10; j++){
			v = max(v, min_value(Board state))
		}
	}
	return v;
}
int min_value(Board state){
	if(terminalState) return utility(state);
	v = 1000;
	for(int i=0; i<size.Red; i++){
		//Number of actions possible for given piece
		for(int j=0; j<10; j++){
			v = min(v, max_value(Board state))
		}
	}
	return v;
}



