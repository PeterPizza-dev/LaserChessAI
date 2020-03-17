#include "Board.h"
#include "piece.h"
#include <iostream>
#include <string.h>


using namespace std;


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
	if (!Blue_turn) { cout << "Red turn to play"; }
	else if (move_direc != None && turn_dire != None) { cout << "Only one move is allowed per turn"; }
	else {
		int index = search( PosX, PosY);
		if (move_direc != None) {
			int res = move( index, move_direc);
		}
		else {
			int res = turn( index, turn_dire);
		}
	}
};

int Board::search( int PosX, int PosY) {
	int index = -1;
	for (unsigned int i; i > Active.size(); i++) {
		if (Active[i]->getX() == PosX && Active[i]->getY() == PosY) { index = i; }
	};
	return index;
};

int Board::move( int index, direction move_dire) {
	switch (move_dire)
	{
	case NE:
		Active[index]->setX(Active[index]->getX() + 1);
		Active[index]->setY(Active[index]->getY() - 1);
		break;
	case E:
		Active[index]->setX(Active[index]->getX() + 1);
		break;
	case N:
		Active[index]->setY(Active[index]->getY() - 1);
		break;
	case W:
		Active[index]->setX(Active[index]->getX() - 1);
		break;
	case S:
		Active[index]->setY(Active[index]->getY() + 1);
		break;
	case SE:
		Active[index]->setX(Active[index]->getX() + 1);
		Active[index]->setY(Active[index]->getY() + 1);
		break;
	case SW:
		Active[index]->setX(Active[index]->getX() - 1);
		Active[index]->setY(Active[index]->getY() + 1);
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
	case E:
		Active[index]->setOrientation(turn_dire);
		break;
	case N:
		Active[index]->setOrientation(turn_dire);
		break;
	case W:
		Active[index]->setOrientation(turn_dire);
		break;
	case S:
		Active[index]->setOrientation(turn_dire);
		break;
	default:
		cout << "Not an eligible move";
			return -1;
	}
	return 0;
};

int** Board::getstate(void) {
	return field;
};
