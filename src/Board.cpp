#include "Board.h"
#include "piece.h"
#include <iostream>
#include <string.h>
#include <regex>
#include <array>
#include "AI.h"


using namespace std;

void clear();
int charToInt(char c);

//If altered, it should be changed in game.cpp as well
int play_board_check[8][10] =
    {{0,1,0,0,0,0,0,0,2,1},
     {2,0,0,0,0,0,0,0,0,1},
     {2,0,0,0,0,0,0,0,0,1},
     {2,0,0,0,0,0,0,0,0,1},
     {2,0,0,0,0,0,0,0,0,1},
     {2,0,0,0,0,0,0,0,0,1},
     {2,0,0,0,0,0,0,0,0,1},
     {2,1,0,0,0,0,0,0,2,0}};



Board::Board() {
	Blue_turn = true;
};
Board::~Board() {
	//Remove all the entries in the vectors
	Active.clear();
	BlueActive.clear();
	RedActive.clear();
	//Free up the allocated memory, by swaping them with empty nonallocated vectors
	vector<piece*>().swap(Active);
	vector<piece*>().swap(BlueActive);
	vector<piece*>().swap(RedActive);

	//delete the element in feild, and free memory
	field = NULL;

	//delete the element in feild, and free memory
    laser_track = NULL;

	
};

Board::Board(const Board &old_board) {
	score = old_board.score;
	Blue_turn = old_board.Blue_turn;
	for (int i = 0; i < old_board.Active.size(); i++)
		{
			const char* pieceName =  typeid(old_board.Active[i][0]).name();
			int x = old_board.Active[i] -> getX();
			int y  = old_board.Active[i] -> getY();
			direction ori = old_board.Active[i] -> getOrientation();
			int colour =  old_board.Active[i] -> getColour();

			if (!strcmp(pieceName, "4King")){
				Active.push_back(new King(x,y,ori,colour));
			}

			else if (!strcmp(pieceName, "8Defender")){
				Active.push_back(new Defender(x,y,ori,colour));
			}

			else if (!strcmp(pieceName, "9Deflector")){
				Active.push_back(new Deflector(x,y,ori,colour));
			}

			else if (!strcmp(pieceName, "5Laser")){
				Active.push_back(new Laser(ori,colour));
			}
			else if (!strcmp(pieceName, "6Switch")){
				Active.push_back(new Switch(x,y,ori,colour));
			}

		}
		updateRedAndBlueActive();

}



void Board::update_laser(bool player){
	if(player){
	//Reset board for updating
	laser_track = new int*[ROWS];
	for (int i = 0; i < ROWS; i++) {
		laser_track[i] = new int[COLUMNS];
		for (int j = 0; j < COLUMNS; j++) {
			laser_track[i][j] = 0;
		}
	}
	}
	Laser_Track Laser;
	if(Blue_turn){
		Laser.setX(7);
		Laser.setY(9);
		Laser.setOrientation(N);
	}else{
		Laser.setX(0);
		Laser.setY(0);
		Laser.setOrientation(S);
	}
	
	int x,y;
	int hit;
	direction new_ori;
	for (int i = 0; i < (ROWS*COLUMNS); i++ ){

		Laser.update_pos();
		x = Laser.getX();
		y = Laser.getY();
		if (x < 0 || x == ROWS || y < 0 || y == COLUMNS){
			break;
		}
		if(player){
			laser_track[x][y] = 1;
		}
		hit = search(x,y);
		if (hit != -1){
			new_ori = Active[hit] -> laser_in(Laser.getOrientation());		
			if(new_ori == None){
				break;
			}
			else if (new_ori == Dead){

				if (!strcmp(typeid(Active[hit][0]).name(),"4King")){
					if(Active[hit] -> getColour() < 0){Blue_win = false;}
					else {Blue_win = true;}
					Game_done = true;
				}
				Active.erase(Active.begin()+hit);
				
				break;
			}else{
				Laser.setOrientation(new_ori);
			}
		}
	}
	updateRedAndBlueActive();
	calculate_score();
	if (player){
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLUMNS; j++) {
				cout << laser_track[i][j] << " ";
			}
			cout << "\n" << endl;
		}
	}
}

void Board:: calculate_score(){
	//Blue vs Red (Blue is max Red is min)
	int BlueSum = 0;
	int RedSum = 0;
	//The scores are as follows:
	// 2 point - Defender
	// 4 point - Deflector
	// 0 point - Switch (0 because it can not be killed, so it doesn't effect the zero sum game)
	// 1000 point - King (Don't lose this)


	for (unsigned int i = 0; i < BlueActive.size(); i++) {
		const char* pieceName =  typeid(BlueActive[i][0]).name();
		if(!strcmp(pieceName,"4King")){
			BlueSum += 1000;
		}else if(!strcmp(pieceName,"8Defender")){
			BlueSum += 2;
		}else if(!strcmp(pieceName,"9Deflector")){
			BlueSum += 4;
		}
	}
	for (unsigned int i = 0; i < RedActive.size(); i++) {
		const char* pieceName =  typeid(RedActive[i][0]).name();
		if(!strcmp(pieceName,"4King")){
			RedSum += 1000;
		}else if(!strcmp(pieceName,"8Defender")){
			RedSum += 2;
		}else if(!strcmp(pieceName,"9Deflector")){
			RedSum += 4;
		}
	}
	score = (BlueSum-RedSum);
}
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


void Board::test_minmax(void) {
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

	Active.push_back(new Switch(3, 4, N, 1));

	//Blue pieces
	Active.push_back(new King(7, 4, S, -1));
	Active.push_back(new Laser(S, -1));
	Active.push_back(new Defender(7, 3, N, -1));
	Active.push_back(new Defender(7, 5, N, -1));

	Active.push_back(new Deflector(5, 9, S, -1));

	Active.push_back(new Switch(4, 5, N, -1));

	updateRedAndBlueActive();
}


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

	updateRedAndBlueActive();
}

void Board::updateRedAndBlueActive(){
	RedActive.erase(RedActive.begin(),RedActive.end());
	BlueActive.erase(BlueActive.begin(),BlueActive.end());

	for (unsigned int i = 0; i < Active.size(); i++) {
		const char* pieceName = typeid(Active[i][0]).name();
		int pieceColour = Active[i] -> getColour();
		if (!strcmp(pieceName,"5Laser")){
			continue;
		}
		else if(pieceColour < 0){
			BlueActive.push_back(Active[i]);
		} else {
			RedActive.push_back(Active[i]);
		}
	}
}

int Board::search( int PosX, int PosY) {
	int index = 0;
	for (int i=0; i < Active.size(); i++) {
		if (Active[i]->getX() == PosX && Active[i]->getY() == PosY) { 
			return i; 
		}
	};
	return -1;
};

void Board::validMove(int index_piece, int x, int y, bool *ret_safe_move, bool *ret_piece_there, bool print){
	int res = search(x,y);
	int colour = Active[index_piece] -> getColour();	
	//Check out of bounds
	if (x == ROWS || y == COLUMNS || x < 0 || y < 0){
		if (print){
			cout << "You are moving a piece out of the board. This is not legal" << endl;
		}
		*ret_safe_move = false;
		*ret_piece_there = false;
	}
	
	else if (res < 0){
		if ( (colour > 0 && play_board_check[x][y] == 0) || 
			 (colour < 0 && play_board_check[x][y] == 0) ){
			*ret_safe_move = true;
			*ret_piece_there = false;
		}else if (colour < 0 && play_board_check[x][y] == 1){
			*ret_safe_move = true;
			*ret_piece_there = false;
		}else if (colour > 0 && play_board_check[x][y] == 2){
			*ret_safe_move = true;
			*ret_piece_there = false;
		}
		else{
			*ret_safe_move = false;
			*ret_piece_there = false;
		}

	}else{
		if(print){
			cout << "A piece is already on this location" << endl;
		}
		if (colour < 0 && play_board_check[x][y] == 1){
			*ret_safe_move = false;
			*ret_piece_there = true;
		}else if (colour > 0 && play_board_check[x][y] == 2){
			*ret_safe_move = false;
			*ret_piece_there = true;
		}else if ( (colour > 0 && play_board_check[x][y] == 0) || 
			 	(colour < 0 && play_board_check[x][y] == 0) ){
			*ret_safe_move = false;
			*ret_piece_there = true;
		}else{
			if(print){
			cout << "Even if you move a switch, you can't move into a coloured space, which isn't yours." << endl;
			*ret_safe_move = false;
			*ret_piece_there = false;
			}
		}
		
	}

}


void Board::switch_pieces(int index, int x, int y){
	int switch_index = search(x,y);

	Active[switch_index] -> setX(Active[index]->getX());
	Active[switch_index] -> setY(Active[index]->getY());
	Active[index]        -> setX(x);
	Active[index]        -> setY(y);
}

int Board::move( int index, direction move_dire, bool print) {
	int x,y;
	bool res_safe,res_taken;
	std::vector <piece*> player_vec;
	if(Blue_turn){player_vec = BlueActive;}
	else {player_vec=RedActive;}
	const char* pieceName =  typeid(Active[index][0]).name();
	switch (move_dire)
	{
		case NE:
			x = Active[index]->getX() - 1;
			y = Active[index]->getY() + 1;
			validMove(index,x,y,&res_safe,&res_taken,print);
			if(res_safe){
				Active[index]->setX(x);
				Active[index]->setY(y);
				return 0;
			}else{
				if (res_taken){
					if (!strcmp(pieceName,"6Switch")){
						switch_pieces(index,x,y);
						return 0;
					}else{ return -1;}
				}
				else{
					return -1;
				}
			}
		
		case E:
			x = Active[index]->getX();
			y = Active[index]->getY() + 1;
			validMove(index,x,y,&res_safe,&res_taken,print);
			if(res_safe){
				Active[index]->setY(y);
				return 0;
			}else{
				if (res_taken){
					if (!strcmp(pieceName,"6Switch")){
						switch_pieces(index,x,y);
						return 0;
					}else{ return -1;}
				}else{
					return -1;
				}
			}			
		
		
		case N:
			x = Active[index]->getX() - 1;
			y = Active[index]->getY();
			validMove(index,x,y,&res_safe,&res_taken,print); 
			if(res_safe){
				Active[index]->setX(x);
				return 0;
			}else{
				if (res_taken){
					if (!strcmp(pieceName,"6Switch")){
						switch_pieces(index,x,y);
						return 0;
					}else{ return -1;}
				}else{
					return -1;
				}
			}
			

		case W:
			x = Active[index]->getX();
			y = Active[index]->getY() -1;
			validMove(index,x,y,&res_safe,&res_taken,print);
			if(res_safe){
				Active[index]->setY(y);
				return 0;
			}else{
				if (res_taken){
					if (!strcmp(pieceName,"6Switch")){
						switch_pieces(index,x,y);
						return 0;
					}else{ return -1;}
				}else{
					return -1;
				}
			}

		case S:
			x = Active[index]->getX() + 1;
			y = Active[index]->getY();
			validMove(index,x,y,&res_safe,&res_taken,print);
			if(res_safe){
				Active[index]->setX(x);
				return 0;
			}else{
				if (res_taken){
					if (!strcmp(pieceName,"6Switch")){
						switch_pieces(index,x,y);
						return 0;
					}else{ return -1;}
				}else{
					return -1;
				}
			}

		case SE:
			x = Active[index]->getX() + 1;
			y = Active[index]->getY() + 1;
			validMove(index,x,y,&res_safe,&res_taken,print);
			if(res_safe){
				Active[index]->setX(x);
				Active[index]->setY(y);
				return 0;
			}else{
				if (res_taken){
					if (!strcmp(pieceName,"6Switch")){
						switch_pieces(index,x,y);
						return 0;
					}else{ return -1;}
				}else{
					return -1;
				}
			}
		
		case SW:
			x = Active[index]->getX() + 1;
			y = Active[index]->getY() - 1;
			validMove(index,x,y,&res_safe,&res_taken,print);
			if(res_safe){
				Active[index]->setX(x);
				Active[index]->setY(y);
				return 0;
			}else{
				if (res_taken){
					if (!strcmp(pieceName,"6Switch")){
						switch_pieces(index,x,y);
						return 0;
					}else{ return -1;}
				}else{
					return -1;
				}
			}
			
		case NW:
			x = Active[index]->getX() - 1;
			y = Active[index]->getY() - 1;
			validMove(index,x,y,&res_safe,&res_taken,print);
			if(res_safe){
				Active[index]->setX(x);
				Active[index]->setY(y);
				return 0;
			}else{
				if (res_taken){
					if (!strcmp(pieceName,"6Switch")){
						switch_pieces(index,x,y);
						return 0;
					}else{ return -1;}
				}else{
					return -1;
				}
			}

		default: 
			cout << "Not an eligible move";
			return -1;
	}
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

int** Board::getLaserTrack(void) {
	return laser_track;
};
void Board::Delete_active_vector(void){
	Active.clear();
}
void Board::playerChoiceDialog(){		
	if(Blue_turn){cout << "Player One (Blue turn)" <<endl;}
	else{cout<< "Player Two (Red turn)" << endl;}
	cout << "First choose what piece to move:" << endl;
	bool col_choice,row_choice,chosing_piece,chose_the_move = true;
	int x,y,piece_index;
	char col,row;
	regex regex_pattern_col("[a-j]");
	regex regex_pattern_row("[1-8]");
	std::cin.clear();
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
			else if(!strcmp(typeid(Active[piece_index][0]).name(),"5Laser")){
				clear();
				cout << "This is the laser, you can't move this, choice another piece." << endl;
				col_choice = row_choice = true;
			}
			
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
				if(move(piece_index,N,true) != 0){break;}
				else{chose_the_move = false; break;}
			
			case 1:
				if(move(piece_index,NE,true) != 0){break;}
				else{chose_the_move = false; break;}
			
			case 2:
				if(move(piece_index,E,true) != 0){break;}
				else{chose_the_move = false; break;}
			
			case 3:
				if(move(piece_index,SE,true) != 0){break;}
				else{chose_the_move = false; break;}
			
			
			case 4:
				if(move(piece_index,S,true) != 0){break;}
				else{chose_the_move = false; break;}
			
			case 5:
				if(move(piece_index,SW,true) != 0){break;}
				else{chose_the_move = false; break;}
			
			case 6:
				if(move(piece_index,W,true) != 0){break;}
				else{chose_the_move = false; break;}
			
			case 7:
				if(move(piece_index,NW,true) != 0){break;}
				else{chose_the_move = false; break;}
			
			
			case 8:
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
int Board::Do_action(int index, int choice){
	int piece_index;
	if(Blue_turn)
	{
	  piece_index = search(BlueActive[index]->getX(),BlueActive[index]->getY());
	}
	else{
	  piece_index = search(RedActive[index]->getX(),RedActive[index]->getY());
	}

	switch(choice){
		case 0:
			return move(piece_index,N,false);
		
		case 1:
			return move(piece_index,NE,false);
		
		case 2:
			return move(piece_index,E,false);
		
		case 3:
			return move(piece_index,SE,false);
		
		
		case 4:
			return move(piece_index,S,false);
		
		case 5:
			return move(piece_index,SW,false);
		
		case 6:
			return move(piece_index,W,false);
		case 7:
			return move(piece_index,NW,false);		
		
		case 8:
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
			return 0;
		
		case 9:
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
			return 0;

		default:
			cout << "No case match, continue." << endl;
			return -1;
	}
}


int Board::gameDialog(){
	cout << "Welcome to Laser chess, choose what gamemode you will like:" << endl;
	cout << "[1] Player vs. Player" << endl;
	cout << "[2] Player vs. Computer" << endl;
	cout << "[3] Computer vs. Computer" << endl;
	int choice;
	Game_done = false;
	while(true){
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

			case 2:
				//start player vs Computer
				clear();
				return 2;

			case 3:
				//start player vs Computer
				clear();
				return 3;

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
	cout << "blue size: " << BlueActive.size()<<endl;
	cout << "red size: " <<RedActive.size()<<endl;
	
	return false;

}

bool Board::PlayerVsPlayer(){
	playerChoiceDialog();
	update_board();
	update_laser(true);
	update_board();
	calculate_score();
	cout << score << endl;

	if(Blue_turn){Blue_turn=false;}
	else{Blue_turn=true;}
	clear();
	return Game_done;

	
}

bool Board::PlayerVsComputer(){
	//Debug of Do_action
	playerChoiceDialog();
	update_board();
	update_laser(true);
	update_board();
	calculate_score();
	if(Blue_turn){Blue_turn=false;}
	else{Blue_turn=true;}
	clear();
	return Game_done;

}


void clear(){
	cout << "\n\n\n\n\n";
	std::cin.clear();


}


int charToInt(char c){
	array<char,10> chars= {'a','b','c','d','e','f','g','h','i','j'};
	for (int i=0; i<chars.size(); i++){
		if(c == chars[i]){ return i;}
	}
}

