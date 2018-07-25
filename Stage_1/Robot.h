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
using namespace std;

class Robot {
private:
	Vector2D pos;
	Vector2D v;
public:
	Robot();
	Robot(Vector2D,Vector2D);
	Vector2D getPosition();
	void turnLeft();
	void turnRight();
	void moveDelta_t(double);
	string getDescription();
	string toString();
	virtual ~Robot();
};

#endif /* ROBOT_H_ */
