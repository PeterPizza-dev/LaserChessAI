/*
 * piece.h
 *
 *  Created on: 5 Mar 2020
 *      Author: oliverbehrens
 */

#ifndef PIECE_H_
#define PIECE_H_

class piece {
protected:
//	//Desciptive values of each piece in the class
	int orientation, positionX, positionY, colour;
public:
	int getX();
	int getY();
	int getOrientation();
	void setX(int x);
	void setY(int y);
	void setOrientation(int theta);
	int getColour();
	virtual int laser_in(int laser_direction)=0;
};
class King : public piece{
public:
	King(int positionX, int positionY, int orientation, int colour);
	int laser_in(int laser_direction);
	//~King();
};
class Laser : public piece{
public:
	Laser(int orientation, int colour);
	int laser_in(int laser_direction);
};
class Deflector : public piece{
public:
	Deflector(int positionX, int positionY, int orientation, int colour);
	int laser_in(int laser_direction);

};
class Defender : public piece{
public:
	Defender(int positionX, int positionY, int orientation, int colour);
	int laser_in(int laser_direction);
};
class Switch : public piece{
public:
	Switch(int positionX, int positionY, int orientation, int colour);
	int laser_in(int laser_direction);
};

#endif /* PIECE_H_ */
