#ifndef PIECE_H_
#define PIECE_H_
enum direction { NE, E, N, W, S, SE, SW, NW, None };

class piece {
protected:
//	//Desciptive values of each piece in the class
	int positionX, positionY, colour;
	direction orientation;
public:
	piece(); //to be added
	int getX();
	int getY();
	direction getOrientation();
	void setX(int x);
	void setY(int y);
	void setOrientation(direction orientation);
	int getColour();
	virtual int laser_in(int laser_direction)=0;
};
class King : public piece{
public:
	King(int positionX, int positionY, direction orientation, int colour);
	int laser_in(int laser_direction);
	//~King();
};
class Laser : public piece{
public:
	Laser(direction orientation, int colour);
	int laser_in(int laser_direction);
};
class Deflector : public piece{
public:
	Deflector(int positionX, int positionY, direction orientation, int colour);
	int laser_in(int laser_direction);

};
class Defender : public piece{
public:
	Defender(int positionX, int positionY, direction orientation, int colour);
	int laser_in(int laser_direction);
};
class Switch : public piece{
public:
	Switch(int positionX, int positionY, direction orientation, int colour);
	int laser_in(int laser_direction);
};

#endif /* PIECE_H_ */
