/*
 * piece.cpp
 *
 *  Created on: 5 Mar 2020
 *      Author: oliverbehrens
 */

#include "piece.h"
#include <math.h>
#include <iostream>
using namespace std;



//Methods for all pieces
piece::piece() {
	this->positionX = 0;
	this->positionY = 0;
	this->orientation = N;
	this->colour = 0;
};
int piece::getX(){
	return positionX;
}
int piece::getY(){
	return positionY;
}
direction piece::getOrientation(){
	return orientation;
}
int piece::getColour(){
	return colour;
}
void piece::setX(int x){
	positionX = x;
}
void piece::setY(int y){
	positionY = y;
}
void piece::setOrientation(direction theta){
	orientation = theta;
}

//Methods for king class
//Constructor
King::King(int positionX, int positionY, direction orientation, int colour){
	this -> positionX = positionX;
	this -> positionY = positionY;
	this -> orientation = orientation;
	this -> colour = colour;
}

direction King::laser_in(direction laser_direction){
	return Dead;
	//Og lav eventuel destructor
}

//Deflector class
Deflector::Deflector(int positionX, int positionY, direction orientation, int colour){
	this -> positionX = positionX;
	this -> positionY = positionY;
	this -> orientation = orientation;
	this -> colour = colour;
}
direction Deflector::laser_in(direction laser_direction){
	    switch(laser_direction){
	    case N:
	    	switch(orientation){
				case S:
					return W;
				case E:
					return E;
				default:
					return Dead;
			}
	    case S:
	    	switch(orientation){
				case N:
					return E;
				case W:
					return W;
				default:
					return Dead;
			}
	    case E:
	    	switch(orientation){
				case S:
					return S;
				case W:
					return N;
				default:
					return Dead;
			}
	    case W:
	    	switch(orientation){
				case E:
					return S;
				case N:
					return N;
				default:
					return Dead;
			}
	}
}

//Defender class
Defender::Defender(int positionX, int positionY, direction orientation, int colour){
	this -> positionX = positionX;
	this -> positionY = positionY;
	this -> orientation = orientation;
	this -> colour = colour;
}
direction Defender::laser_in(direction laser_direction){
	switch(laser_direction){
		case N:
			switch(orientation){
				case S:
					return None;
				default:
					return Dead;
			}
		
		case E:
			switch(orientation){
				case W:
					return None;
				default:
					return Dead;
			}

		case S:
			switch(orientation){
				case N:
					return None;
				default:
					return Dead;
			}

		case W:
			switch(orientation){
				case E:
					return None;
				default:
					return Dead;
			}

		default:
			return None;
	}
}

//Switch calss
Switch::Switch(int positionX, int positionY, direction orientation, int colour){
	this -> positionX = positionX;
	this -> positionY = positionY;
	this -> orientation = orientation;
	this -> colour = colour;
}
direction Switch::laser_in(direction laser_direction){
    switch(laser_direction){
		case N:
			switch(orientation){
				case N:
					return W;
				case S:
					return W;
				case E:
					return E;
				case W:
					return E;
				default:
					return None;
			}
		case E:
			switch(orientation){
				case N:
					return S;
				case S:
					return S;
				case E:
					return N;
				case W:
					return N;
				default:
					return None;
			}
		
		case S:
			switch(orientation){
				case N:
					return E;
				case S:
					return E;
				case E:
					return W;
				case W:
					return W;
				default:
					return None;
			}
		case W:
			switch(orientation){
				case N:
					return N;
				case S:
					return N;
				case E:
					return S;
				case W:
					return S;
				default:
					return None;
			}
		default:
			return None;
	}
}

//LASER CLASS
Laser::Laser(direction orientation, int colour){
	this -> positionX = positionX;
	this -> positionY = positionY;
	this -> orientation = orientation;
	this -> colour = colour;
}
direction Laser::laser_in(direction laser_direction){
	return orientation;
}

//The laser beam
Laser_Track::Laser_Track(int positionX, int positionY, direction orientation){
	this -> positionX = positionX;
	this -> positionY = positionY;
	this -> orientation = orientation;
	this -> colour = colour;
}

void Laser_Track::update_pos(){
	switch(this -> orientation){
		case N:
			this -> positionX--;
			break;
		case E:
			this -> positionY++;
			break;
		case S:
			this -> positionX++;
			break;
		case W:
			this -> positionY--;
			break;
	}
}

direction Laser_Track::laser_in(direction laser_direction){
	return orientation;
}

Laser_Track::Laser_Track() {
	this->positionX = 0;
	this->positionY = 0;
	this->orientation = N;
	this->colour = 0;
};


