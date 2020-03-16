#include "piece.h"
#include "Board.h"
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

Board::Board() {};

//all pieces blue are negative. red pieces are positive

int* Board::update_board(Board Playing){
	//Reset board for updating
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 8; j++) {
			Playing.field[i][j] = 0;
		}
	}

	for (int i = 0; i < Playing.Active.size(); i++) {
		if (typeid(Playing.Active[i]).name() == "King"){
			Playing.field[Playing.Active[i]->getX()][Playing.Active[i].getY()] = Playing.Active[i].getColour() * (Playing.Active[i].getOrientation() * 10 + 0 );//Insert king expression;
		}

		else if (typeid(Playing.Active[i]).name() == "Laser"){
		Playing.field[Playing.Active[i].getX()][Playing.Active[i].getY()] = Playing.Active[i].getColour() * (Playing.Active[i].getOrientation() * 10 + 0 );//Insert Laser expression;
		}

		else if (typeid(Playing.Active[i]).name() == "Deflector"){
		Playing.field[Playing.Active[i].getX()][Playing.Active[i].getY()] = Playing.Active[i].getColour() * (Playing.Active[i].getOrientation() * 10 + 0 );//Insert Laser expression;
		}
		else if (typeid(Playing.Active[i]).name() == "Defender") {
			Playing.field[Playing.Active[i].getX()][Playing.Active[i].getY()] = Playing.Active[i].getColour() * (Playing.Active[i].getOrientation() * 10 + 0);//Insert Laser expression;
		}

		else if (typeid(Playing.Active[i]).name() == "Switch") {
			Playing.field[Playing.Active[i].getX()][Playing.Active[i].getY()] = Playing.Active[i].getColour() * (Playing.Active[i].getOrientation() * 10 + 0);//Insert Laser expression;
		}

		else { cout << "Unknow piece"; }
	}
	return *Playing.field;
};


void Board::display_board(Board Playing){

};

void Board::init_ace(void) {
	//Red pieces
	Active.push_back(King(5, 7, S, 1));
	Active.push_back(Laser(S, 1));
	Active.push_back(Defender(4, 7, S, 1));
	Active.push_back(Defender(6, 7, S, 1));

	Active.push_back(Deflector(0, 3, E, 1));
	Active.push_back(Deflector(0, 4, N, 1));
	Active.push_back(Deflector(3, 6, S, 1));
	Active.push_back(Deflector(6, 2, E, 1));
	Active.push_back(Deflector(7, 3, N, 1));
	Active.push_back(Deflector(7, 4, E, 1));
	Active.push_back(Deflector(7, 7, E, 1));

	Active.push_back(Switch(4, 4, N, 1));
	Active.push_back(Switch(5, 4, E, 1));

	//Blue pieces
	Active.push_back(King(4, 0, N, -1));
	Active.push_back(Laser(N,-1));
	Active.push_back(Defender(3, 0, N, -1));
	Active.push_back(Defender(5, 0, N, -1));

	Active.push_back(Deflector(2, 0, W, -1));
	Active.push_back(Deflector(2, 3, W, -1));
	Active.push_back(Deflector(2, 4, S, -1));
	Active.push_back(Deflector(3, 2, W, -1));
	Active.push_back(Deflector(7, 3, N, -1));
	Active.push_back(Deflector(10, 4, S, -1));
	Active.push_back(Deflector(10, 7, W, -1));

	Active.push_back(Switch(4, 3, N, -1));
	Active.push_back(Switch(5, 3, E, -1));
}
