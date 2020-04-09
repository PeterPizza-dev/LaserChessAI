
#include <iostream>
#include <string.h>
#include <vector>


#include "AI.h"
#include "Board.h"

using namespace std;

//AI constructor - Sets the colour of the computer player
AI::AI(bool isBlue) {
	this->isBlue = isBlue;
};

//AI utility - Evaluation function of the state of the game Board.
int AI::utility(Board state){
	int score;
	isBlue ?  score = (-1)*state.score : score =  (state.score);
	return score;
}

//Minimax algorithm function
int AI::miniMax(Board board, int depth, bool MaxPlayer){
	//Current value of board
	int score = utility(board);
	//Temporary vectors to keep track of which turn it is
	std::vector <piece*> turn;
	std::vector <piece*> notTurn;
	isBlue ? turn=board.BlueActive: turn=board.RedActive;
	isBlue ? notTurn=board.RedActive : notTurn=board.BlueActive;

	//Terminal test
	if(score > 900 || score < -900){
		return score;
	}
	//This is the cut-off depth to the search, the depth is +1
	//Because the first Max step is done in the find move function
	if (depth == 2){
		return score;
	}

	if(MaxPlayer){
		int bestValue = -1000;
		//For every move possible and for each piece
		//Piece
		for(int i=0; i<turn.size(); i++){
			//For each piece, total number of moves
			for(int j=0; j<10; j++){
				//don't try and turn the king(redundant move)
				if (!strcmp(typeid(turn[i][0]).name(),"4King") && j == 8){
					break;
				}
				//Copy of the current game state
				Board Temp_board = board;
				//Keeps track of current turn in the game, to search for new move
				isBlue ? Temp_board.Blue_turn=true : Temp_board.Blue_turn=false ;
				//Do the action
				Temp_board.Do_action(i, j);
				int res = Temp_board.Do_action(i, j);
				//If result is -1, continue to next move
				if (res != 0){
					continue;
				}
				//Else we update and evaluate board state
				else{
					Temp_board.update_laser(false);
					//Recursive call to miniMax
					bestValue = max(bestValue, miniMax(Temp_board, depth+1, false));
					Temp_board.~Board();
				}
			}
		}
		return bestValue;
	}
	//If minimizing player
	else{
		int bestValue = 1000;
		//For every move possible - for each piece
		//Piece
		for(int i=0; i<board.BlueActive.size(); i++){
			//For each piece, total number of moves
			for(int j=0; j<10; j++){
				//Don't try and turn the king
				if (!strcmp(typeid(notTurn[i][0]).name(),"4King") && j == 8){
					break;
				}
				Board Temp_board = board;
				isBlue ? Temp_board.Blue_turn=false : Temp_board.Blue_turn=true;

				int res = Temp_board.Do_action(i, j);
				if (res != 0){
					continue;
				}else{
					Temp_board.update_laser(false);
					bestValue = min(bestValue, miniMax(Temp_board, depth+1, true));
					Temp_board.~Board();
				}
			}
		}
		return bestValue;
	}
}

//Essentially just the first MAX step in miniMax
//Made seperately to extract the move, which max the evaluation function
Move AI::findMove(Board board){
	int bestValue = -1000;
	Move bestMove;
	bestMove.piece = -1;
	bestMove.move = -1;
	std::vector <piece*> turn;
	isBlue ? turn=board.BlueActive : turn=board.RedActive;
	//Piece
	for(int i=0; i<turn.size(); i++){
		//Move
		for(int j=0; j<10; j++){
			//don't try and turn the king
			if (!strcmp(typeid(turn[i][0]).name(),"4King") && j == 8){
				break;
			}
			Board Temp_board = board;
			isBlue ? Temp_board.Blue_turn=true : Temp_board.Blue_turn=false;

			// Make the move
			int res = Temp_board.Do_action(i, j);
			if (res != 0){
				//Don't check for invalid moves
				continue;
			}
			else{
				Temp_board.update_laser(false);
				int minvalue = miniMax(Temp_board, 0, false);
				int value = max(bestValue, minvalue);
				Temp_board.~Board();

				//If the value is higher than the curren bestValue is is stored
				//And the current move that max the bestValue is stored in the Move struct
				if(value > bestValue){
					bestMove.piece = i;
					bestMove.move = j;
					bestValue = value;
				}
			}
		}
		cout << "PiecesChecked: " << i << "/" << turn.size() << endl;
	}
	//Best move is returned
	return bestMove;
}

//Implementation of the Alpha Beta pruning
//FindMove function - first Max step of the minimax, using pruning
Move AI::findMove_AB(Board board){
	int bestValue = -1000;
	Move bestMove;
	bestMove.piece = -1;
	bestMove.move = -1;
	std::vector <piece*> turn;
	isBlue ? turn=board.BlueActive : turn=board.RedActive;
	//Initial alpha and beta's
	int alpha = -1000;
	int beta = 1000;
	//Piece
	for(int i=0; i<turn.size(); i++){
		//Move
		for(int j=0; j<10; j++){
			//dont try and turn the king
			if (!strcmp(typeid(turn[i][0]).name(),"4King") && j == 8){
				break;
			}
			Board Temp_board = board;
			// Make the move
			int res = Temp_board.Do_action(i, j);
			if (res != 0){
				//Don't check for invalid moves
				continue;
			}else{
				//UNDO the move - piece back to ORG position.
				Temp_board.update_laser(false);
				int minvalue = Min_Value(Temp_board, 0, alpha, beta);
				int value = max(bestValue,minvalue);
				Temp_board.~Board();

				//ALPHA BETA COMMENTS HER
				cout<<"Beta er :"<<beta<<endl;
				if(value >= beta){
					return bestMove;
				}
				alpha = max(alpha, value);
				cout<<"Alpha er :"<<alpha<<endl;
				Temp_board.~Board();
	            if (beta <= alpha)
	                break;
				if(value > bestValue){
					bestMove.piece = i;
					bestMove.move = j;
					bestValue = value;
				}

			}
		}
		cout << "PiecesChecked: " << i << "/" << turn.size() << endl;
	}
	//board.Blue_turn=true;
	//~Temp_board();
	cout<<"SIZE is blue"<<board.BlueActive.size()<<endl;
	cout<<"SIZE is red"<<board.RedActive.size()<<endl;

	//UNDO the move - piece back to ORG position.
	cout<<"Return best val"<<bestValue<<endl;
	cout <<"Move piece "<<bestMove.piece<<" Ypos: "<<" with move "<<bestMove.
	move<< "\n\n\n"<< endl;
	return bestMove;
}

int AI::Max_Value(Board board, int depth, int alpha, int beta){
	int score = utility(board);
	std::vector <piece*> turn;
	std::vector <piece*> notTurn;
	isBlue ? turn=board.BlueActive: turn=board.RedActive;
	isBlue ? notTurn=board.RedActive : notTurn=board.BlueActive;
	if (depth == 2){
		return score;
	}
	//If the node is a leaf node return the vale
	//ALSO include some sort of terminal test
	if(score > 900 || score < -900){
		return score;
	}
	int bestValue = -1000;
	//For every move possible - for each piece
	//Piece
	for(int i=0; i<turn.size(); i++){
		//For each piece, total number of moves
		for(int j=0; j<10; j++){
		//dont try and turn the king
			if (!strcmp(typeid(turn[i][0]).name(),"4King") && j == 8){
				break;
			}
			Board Temp_board = board;
			isBlue ? Temp_board.Blue_turn=true : Temp_board.Blue_turn=false ;
			//NODE REPRESENTS THE NODE/NEXT GAME state
			Temp_board.Do_action(i, j);
			int res = Temp_board.Do_action(i, j);
			if (res != 0){
				continue;
			}else{
				Temp_board.update_laser(false);
				//UNDO the move - piece back to ORG position.
				bestValue = max(bestValue, Min_Value(Temp_board, depth+1, alpha, beta));
				if(bestValue >= beta){
					return bestValue;
				}
				alpha = max(alpha, bestValue);
				Temp_board.~Board();
	            if (beta <= alpha)
	                break;
			}
            // Alpha Beta Pruning
		}
	}
	return bestValue;
}
int AI::Min_Value(Board board, int depth, int alpha, int beta){
	int score = utility(board);
	std::vector <piece*> turn;
	std::vector <piece*> notTurn;
	isBlue ? turn=board.BlueActive: turn=board.RedActive;
	isBlue ? notTurn=board.RedActive : notTurn=board.BlueActive;
	if (depth == 2){
		return score;
	}
	//If the node is a leaf node return the vale
	//ALSO include some sort of terminal test
	if(score > 900 || score < -900){
		return score;
	}
	int bestValue = 1000;
	//For every move possible - for each piece
	//Piece
	for(int i=0; i<notTurn.size(); i++){
		//For each piece, total number of moves
		for(int j=0; j<10; j++){
			//Dont try and turn the king
			if (!strcmp(typeid(notTurn[i][0]).name(),"4King") && j == 8){
				break;
			}
			Board Temp_board = board;
			isBlue ? Temp_board.Blue_turn=false : Temp_board.Blue_turn=true;

			int res = Temp_board.Do_action(i, j);
			if (res != 0){
				continue;
			}else{
				Temp_board.update_laser(false);
				bestValue = min(bestValue, Max_Value(Temp_board, depth+1, alpha, beta));
				Temp_board.~Board();
				if(bestValue <= alpha){
					return bestValue;
				}
				beta = min(beta, bestValue);
				Temp_board.~Board();
	            if (beta <= alpha)
	                break;
			}
		}
	}
	return bestValue;
}
