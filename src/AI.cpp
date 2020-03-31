
#include <iostream>
#include "AI.h"
#include "Board.h"

using namespace std;

AI::AI(bool status) {
	isActive = status;
};

int AI::utility(Board state){
	return state.score;
}

int AI::miniMax(Board board, int depth, bool MaxPlayer){
	//Current value of board
	int score = board.score;

	if (depth == 1){
		return score;
	}

	//If the node is a leaf node return the vale
	//ALSO include some sort of terminal test
	if(score > 900 || score < -900){
		return score;
	}
	cout<<MaxPlayer<<endl;
	if(MaxPlayer){
		int bestValue = -1000;
		//For every move possible - for each piece
		//Piece
		for(int i=0; i<10; i++){
			//For each piece, total number of moves
			for(int j=0; j<10; j++){
				Board Temp_board = board;
				//NODE REPRESENTS THE NODE/NEXT GAME state
				Temp_board.Do_action(i, j);
				Temp_board.update_board();
				Temp_board.update_laser();
				Temp_board.update_board();
				//UNDO the move - piece back to ORG position.
				bestValue = max(bestValue, miniMax(Temp_board, depth+1, false));
			}
		}
		return bestValue;
	}
	else{
		int bestValue = 1000;
		//For every move possible - for each piece
		//Piece
		for(int i=0; i<10; i++){
			//For each piece, total number of moves
			for(int j=0; j<10; j++){
				Board Temp_board = board;
				Temp_board.Do_action(i, j);
				Temp_board.update_board();
				Temp_board.update_laser();
				Temp_board.update_board();
				bestValue = min(bestValue, miniMax(Temp_board, depth+1, true));
			}
		}
		return bestValue;
	}
	//~Temp_board();
}

//Essentially just the first MAX step in miniMax
//Made seperately to extract the move, which max the evaluation function
Move AI::findMove(Board board){
	int bestValue = -1000;
	Move bestMove;
	bestMove.pieceX = -1;
	bestMove.pieceY = -1;
	bestMove.move = -1;
	for(int i=0; i<board.BlueActive.size(); i++){
		//Here the org. position could be saved.
		for(int j=0; j<10; j++){
			Board Temp_board = board;
			// Make the move
			Temp_board.Do_action(i, j);
			//UNDO the move - piece back to ORG position.
			Temp_board.update_board();
			Temp_board.update_laser();
			Temp_board.update_board();


			int value = max(bestValue, miniMax(Temp_board, 0, false));
			cout<<"Best val:"<<value<<endl;
			//UNDO the move - piece back to ORG position.
			//Evt. en destructor her på tidligere board
			cout<<"Main"<<endl;

			if(value > bestValue){
//				bestMove.pieceX = board.BlueActive[i]->getX();
//				bestMove.pieceY = board.BlueActive[i]->getY();
				bestMove.pieceX = i;

				bestMove.move = j;
				bestValue = value;
			}
			cout<<"Return best val"<<bestValue<<endl;

		}
	}
	//~Temp_board();
	board.Do_action(bestMove.pieceX, bestMove.move);
	cout<<"SIZE is blue"<<board.BlueActive.size()<<endl;
	cout<<"SIZE is red"<<board.RedActive.size()<<endl;

	//UNDO the move - piece back to ORG position.
	board.update_board();
	board.update_laser();
	board.update_board();
	cout<<"Return best val"<<bestValue<<endl;
	cout <<"Move piece "<<bestMove.pieceX<<" Ypos: "<<" with move "<<bestMove.move<<endl;
	return bestMove;
}

//THIS IS HOW


//
//int miniMax(Board state, int depth, int aplha, int beta){
//	v = max_value(state);
//	return Move
//}
//
//int max_value(Board state){
//	if(terminalState) return utility(state);
//	v = -1000;
//	//Numvbr of pieces in own class
//	for(int i=0; i<size.Red; i++){
//		//Number of actions possible for given piece
//		for(int j=0; j<10; j++){
//			v = max(v, min_value(Board state))
//		}
//	}
//	return v;
//}
//int min_value(Board state){
//	if(terminalState) return utility(state);
//	v = 1000;
//	for(int i=0; i<size.Red; i++){
//		//Number of actions possible for given piece
//		for(int j=0; j<10; j++){
//			//do move input move in min
//			v = min(v, max_value(Board state))
//		}
//	}
//	return v;
//}



