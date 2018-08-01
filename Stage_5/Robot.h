/*
 * Robot.h
 *
 *  Created on: Jun 2, 2018
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
	class Pilot{
	public:
//		Pilot();
		virtual void setCourse(double)=0;
//		virtual ~Pilot();
	};
	class PilotL: public Pilot{
	private:
		Robot* r;
		bool lookingForWall;
	public:
		PilotL();
		PilotL(Robot* r);
		void setCourse(double);
		~PilotL();
	};
	class PilotR: public Pilot{
	private:
		Robot* r;
		bool lookingForWall;
	public:
		PilotR();
		PilotR(Robot*);
		void setCourse(double);
		~PilotR();
	};
	Pilot* pilot;
public:
	Robot(Vector2D,Vector2D,double, MyWorld*,bool);
	Vector2D getPosition();
	void turnLeft();
	void turnRight();
	void moveDelta_t(double);
	string getDescription();
	string toString();
	void markRoute(Maze*);
	virtual ~Robot();
};

#include "MyWorld.h"

#endif /* ROBOT_H_ */
