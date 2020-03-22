#ifndef PIECE_H_
#define PIECE_H_
enum direction { NE, E=1, N=2, W=3, S=4, SE, SW, NW, None, Dead};


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
	virtual direction laser_in(direction laser_direction)=0;
};

class King : public piece{
public:
	King(int positionX, int positionY, direction orientation, int colour);
	direction laser_in(direction laser_direction);
	//~King();
};
class Laser : public piece{
public:
	Laser(direction orientation, int colour);
	direction laser_in(direction laser_direction);
};
class Deflector : public piece{
public:
	Deflector(int positionX, int positionY, direction orientation, int colour);
	direction laser_in(direction laser_direction);

};
class Defender : public piece{
public:
	Defender(int positionX, int positionY, direction orientation, int colour);
	direction laser_in(direction laser_direction);
};
class Switch : public piece{
public:
	Switch(int positionX, int positionY, direction orientation, int colour);
	direction laser_in(direction laser_direction);
};

//This is now a piece, but behave a lot like all the other classes
class Laser_Track : public piece{
public:
	Laser_Track();
	Laser_Track(int positionX, int positionY, direction orientation);
	void update_pos(void);
	direction laser_in(direction laser_direction);
};

#endif /* PIECE_H_ */
