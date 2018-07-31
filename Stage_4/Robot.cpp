/*
 * Robot.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: gabrielrudloff
 */

#include "Robot.h"

Robot::Robot(Vector2D pos, Vector2D v,double sensorRange, MyWorld* w) {
	this->pos=pos;
	this->v=v;
	world=w;
	Vector2D dir= v.getUnitary();
	rightSensor=DistanceSensor(Vector2D(-dir.getY(), dir.getX()), sensorRange,this);
	frontSensor = DistanceSensor(dir, sensorRange,this);
	leftSensor = DistanceSensor(Vector2D(dir.getY(), -dir.getX()), sensorRange,this);
	lookingForRightWall=true;
        pilot=Pilot;
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
    pilot.setCourse(delta_t);
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

Robot::DistanceSensor::DistanceSensor(){}

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

Robot::Pilot::Pilot(){
    lookingForRightWall(!rightSensor.senseWall());
}

Robot::Pilot::~Pilot(){}

void Robot::Pilot::setCourse(double delta_t){
        if(leftSensor.senseWall()) {
                turnRight();
                return;
                }
        if(frontSensor.senseWall()) {
                turnLeft();
                return;
        }
        if(rightSensor.senseWall()) {
                lookingForRightWall=false;
                pos = pos.plus(v.times(delta_t));  
                return;
        }
        if(lookingForRightWall) {
                pos = pos.plus(v.times(delta_t));  
                return;
        }
        turnRight();
        lookingForRightWall=true;
        return;   
}


Robot::DistanceSensor::~DistanceSensor(){}
Robot::~Robot() {}

// Nuevo para Stage4
/*
DistanceSensor Robot::getRightSensor(){
    return rightSensor;
}

DistanceSensor Robot::getLeftSensor(){
    return leftSensor;
}

DistanceSensor Robot::getFrontSensor(){
    return frontSensor;
}*/
