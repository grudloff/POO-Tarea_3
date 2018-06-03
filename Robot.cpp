/*
 * Robot.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: gabrielrudloff
 */

#include "Robot.h"

Robot::Robot() {
}

Robot::Robot(Vector2D pos, Vector2D v) {
	this->pos=pos;
	this->v=v;
}

Vector2D Robot::getPosition() {
	return pos;
}

void Robot::turnRight(){
	double temp=v.getX();
		v.setX(v.getY());
		v.setY(-temp);
	}
void Robot::turnLeft(){
	double temp=v.getX();
	v.setX(-v.getY());
	v.setY(temp);
}
void Robot::moveDelta_t(double delta_t) {
	pos=pos+v*delta_t;
}
string Robot::getDescription() {
	return pos.getDescription();
}
string Robot::toString() {
	return pos.toString();
}

Robot::~Robot() {
}

