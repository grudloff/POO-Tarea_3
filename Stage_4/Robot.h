/*
 * Robot.h
 *
 *  Created on: Jun 31, 2018
 *      Author: gabrielrudloff
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include <iostream>
#include <string>
#include "Vector2D.h"
#include "Maze.h"
using namespace std;

class MyWorld;

class Robot {
private:
	Vector2D pos;
	Vector2D v;
	MyWorld* world;//Se utilza puntero porque hay dependencia circular (?)
	class Pilot{
        private: 
            bool lookingForRightWall;
            Robot* r;//clase interna tiene acceso a private de su padre pero no la referencia
        public:
            Pilot();
            Pilot(Robot*);
            void setCourse(double);
           // ~Pilot();
        };
        Pilot pilot;
        class DistanceSensor{
	private:
		Vector2D dir;  
		double range;
		double presition;
		Robot* r;//clase interna tiene acceso a private de su padre pero no la referencia
	public:
		DistanceSensor();
		DistanceSensor(Vector2D,double,Robot*);
		void turnLeft();
		void turnRight();
		bool senseWall();
		string toString();
		~DistanceSensor();
	};
	DistanceSensor rightSensor, frontSensor, leftSensor;
	bool lookingForRightWall;
public:
	Robot(Vector2D,Vector2D,double, MyWorld*);
	Vector2D getPosition();
        Vector2D getVelocity();
        void setPosition(double,double);
	void turnLeft();
	void turnRight();
	void moveDelta_t(double);
	string getDescription();
	string toString();
	void markRoute(Maze*);
	virtual ~Robot();
        // Para Stage4
        
        /*DistanceSensor getRightSensor();
        DistanceSensor getFrontSensor();
        DistanceSensor getLeftSensor();*/
        
};

#include "MyWorld.h"

#endif /* ROBOT_H_ */
