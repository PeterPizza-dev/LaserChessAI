#include "Board.h"
#include "piece.h"
#include <iostream>
#include <string.h>
#include <regex>

using namespace std;

void clear();
int charToInt(char c);


Board::Board() {
	Blue_turn = true;
};

//all pieces blue are negative. red pieces are positive

void Board::update_board(){
	//Reset board for updating
	field = new int*[ROWS];
	for (int i = 0; i < ROWS; i++) {
		field[i] = new int[COLUMNS];
		for (int j = 0; j < COLUMNS; j++) {
			field[i][j] = 0;
		}
	}

	for (unsigned int i = 0; i < Active.size(); i++) {
		const char* pieceName =  typeid(Active[i][0]).name();
		if (!strcmp(pieceName,"4King")){
			field[Active[i]->getX()][Active[i]->getY()] = Active[i]->getColour()
				* (Active[i]->getOrientation()+50);//Insert king expression;
		}

		else if (!strcmp(pieceName,"5Laser") ){
			if (Active[i]->getColour() < 0) {
				field[0][0] = 10;
			}else {
				field[7][9] = -10;

			}
		}

		else if (!strcmp(pieceName,"9Deflector")){
		field[Active[i]->getX()][Active[i]->getY()] = Active[i]->getColour() * (Active[i]->getOrientation()+20);//Insert Deflector expression;
		}
		else if (!strcmp(pieceName,"8Defender")) {
			field[Active[i]->getX()][Active[i]->getY()] = Active[i]->getColour() * (Active[i]->getOrientation()+30);//Insert Defender expression;
		}

		else if (!strcmp(pieceName,"6Switch")) {
			field[Active[i]->getX()][Active[i]->getY()] = Active[i]->getColour() * (Active[i]->getOrientation()+40);//Insert Switch expression;
		}

		else { cout << "Unknown piece" << endl; }
	}
	return;
};


void Board::display_board(){

};

void Board::init_ace(void) {
	//Red pieces

	Active.push_back(new King(0,5,S,1));
	Active.push_back(new Laser(S, 1));
	Active.push_back(new Defender(0, 4, S, 1));
	Active.push_back(new Defender(0, 6, S, 1));

	Active.push_back(new Deflector(0, 7, E, 1));
	Active.push_back(new Deflector(1, 2, S, 1));
	Active.push_back(new Deflector(3, 0, N, 1));
	Active.push_back(new Deflector(3, 7, E, 1));
	Active.push_back(new Deflector(4, 0, E, 1));
	Active.push_back(new Deflector(4, 7, N, 1));
	Active.push_back(new Deflector(5, 6, E, 1));

	Active.push_back(new Switch(3, 4, N, 1));
	Active.push_back(new Switch(3, 5, E, 1));

	//Blue pieces
	Active.push_back(new King(7, 4, S, -1));
	Active.push_back(new Laser(S, -1));
	Active.push_back(new Defender(7, 3, N, -1));
	Active.push_back(new Defender(7, 5, N, -1));

	Active.push_back(new Deflector(7, 2, W, -1));
	Active.push_back(new Deflector(6, 7, N, -1));
	Active.push_back(new Deflector(4, 2, W, -1));
	Active.push_back(new Deflector(4, 9, S, -1));
	Active.push_back(new Deflector(3, 2, S, -1));
	Active.push_back(new Deflector(3, 9, W, -1));
	Active.push_back(new Deflector(2, 3, W, -1));

	Active.push_back(new Switch(4, 4, E, -1));
	Active.push_back(new Switch(4, 5, N, -1));

	update_board();
	return;
}

void Board::RTurn( int PosX, int PosY, direction move_direc, direction turn_dire) {
	if (Blue_turn) { cout << "Blue turn to play";}
	else if (move_direc != None && turn_dire != None) { cout << "Only one move_direc is allowed per turn"; }
	else{
		int index = search( PosX, PosY);
			if (move_direc != None){
				int res = move( index, move_direc);
			}
			else {
				int res = turn( index, turn_dire);
			}
	}
};



void Board::BTurn( int PosX, int PosY, direction move_direc, direction turn_dire) {
	if (!Blue_turn) { cout << "Red turn to play"<<endl; }
	else if (move_direc != None && turn_dire != None) { cout << "Only one move is allowed per turn"<<endl; }
	else {
		int index = search( PosX, PosY);
		if (Active[index]->getColour() > 0){
			 cout << "This is a red piece, you can't move that" << endl;
		}
		else if (move_direc != None) {
			int res = move( index, move_direc);
		}
		else {
			int res = turn( index, turn_dire);
		}
	}
};

int Board::search( int PosX, int PosY) {
	int index = 0;
	for (int i=0; i < Active.size(); i++) {
		if (Active[i]->getX() == PosX && Active[i]->getY() == PosY) { 
			return i; 
		}
	};
	return -1;
};

int Board::move( int index, direction move_dire) {
	switch (move_dire)
	{
	case NE:
		Active[index]->setX(Active[index]->getX() - 1);
		Active[index]->setY(Active[index]->getY() + 1);
		break;
	case E:
		Active[index]->setY(Active[index]->getY() + 1);
		break;
	case N:
		Active[index]->setX(Active[index]->getX() - 1);
		break;
	case W:
		Active[index]->setY(Active[index]->getY() - 1);
		break;
	case S:
		Active[index]->setX(Active[index]->getX() + 1);
		break;
	case SE:
		Active[index]->setX(Active[index]->getX() + 1);
		Active[index]->setY(Active[index]->getY() + 1);
		break;
	case SW:
		Active[index]->setX(Active[index]->getX() + 1);
		Active[index]->setY(Active[index]->getY() - 1);
		break;
	case NW:
		Active[index]->setX(Active[index]->getX() - 1);
		Active[index]->setY(Active[index]->getY() - 1);
		break;
	default: 
		cout << "Not an eligible move";
		return -1;
	}
	return 0;
};

int Board::turn( int index, direction turn_dire) {
	switch (turn_dire)
	{
	case NE:
		cout << "Not an eligible turn";
		break;
	case NW:
		cout << "Not an eligible turn";
		break;
	case SW:
		cout << "Not an eligible turn";
		break;
	case SE:
		cout << "Not an eligible turn";
		break;
	default:
		Active[index]->setOrientation(turn_dire);
		return 0;
	}
	return -1;
};

int** Board::getstate(void) {
	return field;
};


void Board::playerChoiceDialog(){		
	if(Blue_turn){cout << "Player Ones go (Blue turn)" <<endl;}
	else{cout<< "Player Tows go (Red turn)" << endl;}
	cout << "First choose what piece to move:" << endl;
	bool col_choice,row_choice,chosing_piece,chose_the_move = true;
	int x,y,piece_index;
	char col,row;
	regex regex_pattern_col("[a-j]");
	regex regex_pattern_row("[1-8]");

	while (chosing_piece){
		while (col_choice){

			cout << "Choose in what coloumn [a-j] (reading left to right) the piece is placed" <<endl;
			string input;
			getline(cin, input);
			input = tolower(input[0]);
		
			if(!regex_match(input,regex_pattern_col)){
				clear();
				cout << "That is not a legal choice, please try again:" << endl;
			}else{ col=input[0]; y = charToInt(input[0]); col_choice=false; }

		}

		while (row_choice){
			row_choice = false;
			cout << "Choose in what row [1-8] (reading bottom to top) the piece is placed" <<endl;
			string input;
			getline(cin, input);
			if(!regex_match(input,regex_pattern_row)){
				clear();
				cout << "That is not a legal choice, please try again:" << endl;
			}else{ row=input[0];x = 8-(input[0] - '0'); row_choice = false;	}
			
		}
		piece_index = search(x, y);
		if(piece_index < 0) {
			clear();
			cout << "There is no piece in this position, please try again" << endl;
			col_choice = row_choice = true;
		}else{
			if ( (Active[piece_index] -> getColour() < 0 && Blue_turn) || (Active[piece_index] -> getColour() > 0 && !Blue_turn) ){ chosing_piece = false;}
			else{
				col_choice = row_choice = true;
				if(Blue_turn){
					clear(); 
					cout << "You can't choose the piece on " << col << row << " Since this is a red piece, and it is blues turn."<< endl;}
				else{
					clear(); 
					cout << "You can't choose the piece on " << col << row << " Since this is a blue piece, and it is reds turn."<< endl;}
				}
			}	
		}
	cout << "Second choice what you would like to do" << endl;
	while(chose_the_move){
		cout << "[0] Move piece: UP" << endl;
		cout << "[1] Move piece: UPPER RIGHT CORNOR" << endl;
		cout << "[2] Move piece: RIGHT" << endl;
		cout << "[3] Move piece: LOWER RIGHT CORNOR" << endl;
		cout << "[4] Move piece: DOWN" << endl;
		cout << "[5] Move piece: LOWER LEFT CORNOR" << endl;
		cout << "[6] Move piece: LEFT" << endl;
		cout << "[7] Move piece: UPPER LEFT CORNOR" << endl;
		cout << "[8] Turn piece: CLOCKWISE" << endl;
		cout << "[9] Turn piece: COUNTER CLOCKWISE" << endl;

		string input;
		getline(cin, input);
		regex regex_pattern("[0-9]");
		int choice;
		if(!regex_match(input,regex_pattern)){
			choice = -1;
		}else{
			choice = input[0] - '0';
		}
		switch(choice){
			case 0:
				move(piece_index,N);
				chose_the_move = false;
				break;
			
			case 1:
				move(piece_index,NE);
				chose_the_move = false;
				break;
			
			case 2:
				move(piece_index,E);
				chose_the_move = false;
				break;
			
			case 3:
				move(piece_index,SE);
				chose_the_move = false;
				break;
			
			case 4:
				move(piece_index,S);
				chose_the_move = false;
				break;
			
			case 5:
				move(piece_index,SW);
				chose_the_move = false;
				break;
			
			case 6:
				move(piece_index,W);
				chose_the_move = false;
				break;
			
			case 7:
				move(piece_index,NW);
				chose_the_move = false;
				break;
			
			case 8:
				cout << "We got into case 8" << endl;
				chose_the_move = false;
				switch(Active[piece_index]->getOrientation()){
					case N:
						turn(piece_index,E);
						break;
					case E:
						turn(piece_index,S);
						break;
					case S:
						turn(piece_index,W);
						break;
					case W:
						turn(piece_index,N);
						break;
					default:
						cout << "Sorry can't turn to that" << endl;
						break;
				}
				break;
			
			case 9:
				chose_the_move = false;
				switch(Active[piece_index]->getOrientation()){
					case N:
						turn(piece_index,W);
						break;
					case W:
						turn(piece_index,S);
						break;
					case S:
						turn(piece_index,E);
						break;
					case E:
						turn(piece_index,N);
						break;
					
					default:
						break;
				}
				break;

			default:
				cout << "No case match, continue." << endl;
				break;
		}

	}
	
}



int Board::gameDialog(){
	cout << "Welcome to Laser chess, choose what gamemode you will like:" << endl;
	cout << "[1] Player vs. Player" << endl;
	cout << "[2] Player vs. Computer" << endl;
	cout << "[3] Computer vs. Computer" << endl;
	int choice;
	bool choosing = true;
	while(choosing){
		string input;
		getline(cin, input);
		regex regex_pattern("[0-9]");
		if(!regex_match(input,regex_pattern)){
			choice = -1;
		}else{
			choice = input[0] - '0';
		}
		switch(choice){
			case 1:
				//start player vs player 
				clear();
				return 1;
				choosing = false;
				break;

			case 2:
				//start player vs Computer
				clear();
				return 2;
				choosing = false;
				break;

			case 3:
				//start player vs Computer
				clear();
				return 3;
				choosing = false;
				break;

			default:
				clear();
				cout << "Not a possible option, please choose one of the following." << endl;
				cout << "Player vs. Player [1]" << endl;
				cout << "Player vs. Computer [2]" << endl;
				cout << "Computer vs. Computer [3]" << endl;
				break;
		}
	}
};

bool Board::ComputerVsComputer(){
	cout << "Lean back, and watch the computer win against itself" << endl;
	return false;

}

bool Board::PlayerVsPlayer(){
	playerChoiceDialog();
	if(Blue_turn){Blue_turn=false;}
	else{Blue_turn=true;}
	update_board();
	clear();
	return false;

	
}

bool Board::PlayerVsComputer(){
	return false;

}


void clear(){
	cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n" << endl;
}


int charToInt(char c){
	array<char,10> chars= {'a','b','c','d','e','f','g','h','i','j'};
	for (int i=0; i<chars.size(); i++){
		if(c == chars[i]){ return i;}
	}
}

