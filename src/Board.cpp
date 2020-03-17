#include "Board.h"
#include <iostream>
#include <string>
using namespace std;

Board::Board(){};

//all pieces blue are negative. red pieces are positive

void Board::update_board(Board Playing){
	//Reset board for updating
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 8; j++) {
			Playing.field[i][j] = 0;
		}
	}

	for (unsigned int i = 0; i < Playing.Active.size(); i++) {
		if (typeid(Playing.Active[i]).name() == "King"){
			Playing.field[Playing.Active[i]->getX()][Playing.Active[i]->getY()] = Playing.Active[i]->getColour() * (Playing.Active[i]->getOrientation() * 10 + 0 );//Insert king expression;
		}

		else if (typeid(Playing.Active[i]).name() == "Laser"){
		Playing.field[Playing.Active[i]->getX()][Playing.Active[i]->getY()] = Playing.Active[i]->getColour() * (Playing.Active[i]->getOrientation() * 10 + 0 );//Insert Laser expression;
		}

		else if (typeid(Playing.Active[i]).name() == "Deflector"){
		Playing.field[Playing.Active[i]->getX()][Playing.Active[i]->getY()] = Playing.Active[i]->getColour() * (Playing.Active[i]->getOrientation() * 10 + 0 );//Insert Deflector expression;
		}
		else if (typeid(Playing.Active[i]).name() == "Defender") {
			Playing.field[Playing.Active[i]->getX()][Playing.Active[i]->getY()] = Playing.Active[i]->getColour() * (Playing.Active[i]->getOrientation() * 10 + 0);//Insert Defender expression;
		}

		else if (typeid(Playing.Active[i]).name() == "Switch") {
			Playing.field[Playing.Active[i]->getX()][Playing.Active[i]->getY()] = Playing.Active[i]->getColour() * (Playing.Active[i]->getOrientation() * 10 + 0);//Insert Switch expression;
		}

		else { cout << "Unknow piece"; }
	}
	return;
};


void Board::display_board(Board Playing){

};

void Board::init_ace(void) {
	//Red pieces
	King RK(5, 7, S, 1);
	Laser RL(S, 1);
	Defender RD1(4, 7, S, 1);
	Defender RD2(6, 7, S, 1);
	Deflector RDL1(0, 3, E, 1);
	Deflector RDL2(0, 4, N, 1);
	Deflector RDL3(3, 6, S, 1);
	Deflector RDL4(6, 2, E, 1);
	Deflector RDL5(7, 3, N, 1);
	Deflector RDL6(7, 4, E, 1);
	Deflector RDL7(7, 7, E, 1);
	Switch RS1(4, 4, N, 1);
	Switch RS2(5, 4, E, 1);

	Active.push_back(&RK);
	Active.push_back(&RL);
	Active.push_back(&RD1);
	Active.push_back(&RD2);

	Active.push_back(&RDL1);
	Active.push_back(&RDL2);
	Active.push_back(&RDL3);
	Active.push_back(&RDL4);
	Active.push_back(&RDL5);
	Active.push_back(&RDL6);
	Active.push_back(&RDL7);

	Active.push_back(&RS1);
	Active.push_back(&RS2);

	//Blue pieces
	King BK(5, 7, S, -1);
	Laser BL(S, -1);
	Defender BD1(4, 7, S, -1);
	Defender BD2(6, 7, S, -1);
	Deflector BDL1(0, 3, E, -1);
	Deflector BDL2(0, 4, N, -1);
	Deflector BDL3(3, 6, S, -1);
	Deflector BDL4(6, 2, E, -1);
	Deflector BDL5(7, 3, N, -1);
	Deflector BDL6(7, 4, E, -1);
	Deflector BDL7(7, 7, E, -1);
	Switch BS1(4, 4, N, -1);
	Switch BS2(5, 4, E, -1);

	Active.push_back(&BK);
	Active.push_back(&BL);
	Active.push_back(&BD1);
	Active.push_back(&BD2);

	Active.push_back(&BDL1);
	Active.push_back(&BDL2);
	Active.push_back(&BDL3);
	Active.push_back(&BDL4);
	Active.push_back(&BDL5);
	Active.push_back(&BDL6);
	Active.push_back(&BDL7);

	Active.push_back(&BS1);
	Active.push_back(&BS2);
	return;
}
