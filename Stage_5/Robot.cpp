/*
 * Robot.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: gabrielrudloff
 */

#include "Robot.h"

Robot::Robot(Vector2D pos, Vector2D v,double sensorRange, MyWorld* w,bool u){
	this->pos=pos;
	this->v=v;
	world=w;
	Vector2D dir= v.getUnitary();
	rightSensor=DistanceSensor(Vector2D(-dir.getY(), dir.getX()), sensorRange,this);
	frontSensor = DistanceSensor(dir, sensorRange,this);
	leftSensor = DistanceSensor(Vector2D(dir.getY(), -dir.getX()), sensorRange,this);
	if(u)
		pilot=new PilotL(this);
	else
		pilot=new PilotR(this);
}

Vector2D Robot::getPosition() {
	return pos;
}

void Robot::turnRight(){
	v.turnRight();
	rightSensor.turnRight();
	frontSensor.turnRight();
	leftSensor.turnRight();
	}
void Robot::turnLeft(){
	v.turnLeft();
	rightSensor.turnLeft();
	frontSensor.turnLeft();
	leftSensor.turnLeft();
}
void Robot::moveDelta_t(double delta_t) {
	pilot->setCourse(delta_t);
}
string Robot::getDescription() {
	return pos.getDescription();
}
string Robot::toString() {
	stringstream aux;
		aux << pos.toString() << "," << leftSensor.toString() << frontSensor.toString() << rightSensor.toString() << ", " << v.toString();
	return aux.str();
}

void Robot::markRoute(Maze* m){
	m->markPoint(pos);
}

Robot::DistanceSensor::DistanceSensor(){
	range=0;
	presition=0.4;
	r=NULL;
}

Robot::DistanceSensor::DistanceSensor(Vector2D direction, double rang,Robot* r){
	dir=direction;
	range=rang;
	presition=0.4;
	this->r=r;
}

void Robot::DistanceSensor::turnLeft(){
	dir.turnLeft();
}

void Robot::DistanceSensor::turnRight(){
	dir.turnRight();
}

bool Robot::DistanceSensor::senseWall(){
	Vector2D aux;
	for(float i=0;i<range;i+=presition){
		aux=r->pos+dir*i;
		if(r->world->isThere_a_wall((int)aux.getX(),(int)aux.getY()))
			return true;
	}
	return false;
}

string Robot::DistanceSensor::toString(){
	stringstream aux;
	aux << " "<<senseWall();
	return aux.str();
}

Robot::DistanceSensor::~DistanceSensor(){}

Robot::PilotL::PilotL(Robot* r){
	this->r=r;
	lookingForWall=!r->rightSensor.senseWall();
}

void Robot::PilotL::setCourse(double delta_t){
	if(r->rightSensor.senseWall()) {
		r->turnLeft();
		return;
	}
	if(r->frontSensor.senseWall()) {
		r->turnRight();
		return;
	}
	if(r->leftSensor.senseWall()) {
		lookingForWall=false;
		r->pos = r->pos+r->v*delta_t;
		return;
	}
	if(lookingForWall) {
		r->pos = r->pos+r->v*delta_t;
		return;
	}
	r->turnLeft();
	lookingForWall=true;
	return;
}

Robot::PilotR::PilotR(Robot* r){
	this->r=r;
	lookingForWall=!r->rightSensor.senseWall();
}

void Robot::PilotR::setCourse(double delta_t){
	if(r->leftSensor.senseWall()) {
		r->turnRight();
		return;
	}
	if(r->frontSensor.senseWall()) {
		r->turnLeft();
		return;
	}
	if(r->rightSensor.senseWall()) {
		lookingForWall=false;
		r->pos = r->pos+r->v*delta_t;
		return;
	}
	if(lookingForWall) {
		r->pos = r->pos+r->v*delta_t;
		return;
	}
	r->turnRight();
	lookingForWall=true;
	return;
}

Robot::~Robot() {
	delete pilot;
}

