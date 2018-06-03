/*
 * MyWorld.h
 *
 *  Created on: Jun 2, 2018
 *      Author: gabrielrudloff
 */

#ifndef MYWORLD_H_
#define MYWORLD_H_

#include "Robot.h"
#include <iostream>
using namespace std;

class MyWorld {
private:
	double t;
	Robot* r;
public:
	MyWorld();
	void setRobot(Robot*);
	void printStateDescription();
	void printState(double);
	void simulate (double, double);
	virtual ~MyWorld();
};

#endif /* MYWORLD_H_ */
