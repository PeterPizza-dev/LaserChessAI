#include "Board.h"
#include "piece.h"
#include <iostream>
#include <string>

using namespace std;

Board::Board() {
	Blue_turn = true;
};

//all pieces blue are negative. red pieces are positive

void Board::update_board(Board Playing){
	//Reset board for updating
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 8; j++) {
			Playing.field[i][j] = 0;
		}
	}

	for (unsigned int i = 0; i < Playing.Active.size(); i++) {
		if (typeid(Playing.Active[i][0]).name() == "King"){
			Playing.field[Playing.Active[i]->getX()][Playing.Active[i]->getY()] = Playing.Active[i]->getColour() * (Playing.Active[i]->getOrientation()+50);//Insert king expression;
		}

		else if (typeid(Playing.Active[i][0]).name() == "Laser"){
		Playing.field[Playing.Active[i]->getX()][Playing.Active[i]->getY()] = Playing.Active[i]->getColour() * (Playing.Active[i]->getOrientation()+10);//Insert Laser expression;
		}

		else if (typeid(Playing.Active[i][0]).name() == "Deflector"){
		Playing.field[Playing.Active[i]->getX()][Playing.Active[i]->getY()] = Playing.Active[i]->getColour() * (Playing.Active[i]->getOrientation()+20);//Insert Deflector expression;
		}
		else if (typeid(Playing.Active[i][0]).name() == "Defender") {
			Playing.field[Playing.Active[i]->getX()][Playing.Active[i]->getY()] = Playing.Active[i]->getColour() * (Playing.Active[i]->getOrientation()+30);//Insert Defender expression;
		}

		else if (typeid(Playing.Active[i][0]).name() == "Switch") {
			Playing.field[Playing.Active[i]->getX()][Playing.Active[i]->getY()] = Playing.Active[i]->getColour() * (Playing.Active[i]->getOrientation()+40);//Insert Switch expression;
		}

		else { cout << "Unknown piece"; }
	}
	return;
};


void Board::display_board(Board Playing){

};

void Board::init_ace(void) {
	//Red pieces

	Active.push_back(new King(5,7,S,1));
	Active.push_back(new Laser(S, 1));
	Active.push_back(new Defender(4, 7, S, 1));
	Active.push_back(new Defender(6, 7, S, 1));

	Active.push_back(new Deflector(0, 3, E, 1));
	Active.push_back(new Deflector(0, 4, N, 1));
	Active.push_back(new Deflector(3, 6, S, 1));
	Active.push_back(new Deflector(6, 2, E, 1));
	Active.push_back(new Deflector(7, 3, N, 1));
	Active.push_back(new Deflector(7, 4, E, 1));
	Active.push_back(new Deflector(7, 7, E, 1));

	Active.push_back(new Switch(4, 4, N, 1));
	Active.push_back(new Switch(5, 4, E, 1));

	//Blue pieces

	Active.push_back(new King(5, 7, S, -1));
	Active.push_back(new Laser(S, -1));
	Active.push_back(new Defender(4, 7, S, -1));
	Active.push_back(new Defender(6, 7, S, -1));

	Active.push_back(new Deflector(0, 3, E, -1));
	Active.push_back(new Deflector(0, 4, N, -1));
	Active.push_back(new Deflector(3, 6, S, -1));
	Active.push_back(new Deflector(6, 2, E, -1));
	Active.push_back(new Deflector(7, 3, N, -1));
	Active.push_back(new Deflector(7, 4, E, -1));
	Active.push_back(new Deflector(7, 7, E, -1));

	Active.push_back(new Switch(4, 4, N, -1));
	Active.push_back(new Switch(5, 4, E, -1));
	return;
}
