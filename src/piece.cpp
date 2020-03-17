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

int King::laser_in(int laser_direction){
	return -100;
	//Og lav eventuel destructor
}

//Deflector class
Deflector::Deflector(int positionX, int positionY, direction orientation, int colour){
	this -> positionX = positionX;
	this -> positionY = positionY;
	this -> orientation = orientation;
	this -> colour = colour;
}
int Deflector::laser_in(int laser_direction){
	    switch(laser_direction){
	    case 1:
	    	if(orientation == 1 || orientation == 2)
	    		return orientation % 2 == 0 ? 2:4;
	    	else return -100;
	        break;
	    case 2:
	    	if(orientation == 2 || orientation == 3)
	    		return orientation % 2 == 0 ? 1:3;
	    	else return -100;
	        break;
	    case 3:
	    	if(orientation == 3 || orientation == 4)
	    		return orientation % 2 == 0 ? 4:2;
	    	else return -100;
	        break;
	    case 4:
	    	if(orientation == 4 || orientation == 1)
	        	return orientation % 2 == 0 ? 3:1;
	    	else return -100;
	    	break;
	}
}

//Defender class
Defender::Defender(int positionX, int positionY, direction orientation, int colour){
	this -> positionX = positionX;
	this -> positionY = positionY;
	this -> orientation = orientation;
	this -> colour = colour;
}
int Defender::laser_in(int laser_direction){
	if (laser_direction==orientation){
		return 100;
	}
	else{
		return -100;
	}
}

//Switch calss
Switch::Switch(int positionX, int positionY, direction orientation, int colour){
	this -> positionX = positionX;
	this -> positionY = positionY;
	this -> orientation = orientation;
	this -> colour = colour;
}
int Switch::laser_in(int laser_direction){
    switch(laser_direction){
    case 1:
        return orientation % 2 == 0 ? 2:4;
        break;
    case 2:
        return orientation % 2 == 0 ? 1:3;
        break;
    case 3:
        return orientation % 2 == 0 ? 4:2;
        break;
    case 4:
        return orientation % 2 == 0 ? 3:1;
}
}

//LASER CLASS
Laser::Laser(direction orientation, int colour){
	this -> positionX = positionX;
	this -> positionY = positionY;
	this -> orientation = orientation;
}
int Laser::laser_in(int laser_direction){
	return orientation;
}



