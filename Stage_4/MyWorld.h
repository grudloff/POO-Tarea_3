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
#include "Maze.h"
#include "DocumentedMaze.h"
#include "Vector2D.h"

using namespace std;

class MyWorld {
private:
	double t;
	Robot *r;//puntero para no necesitar inicializarlo
	DocumentedMaze *maze;//idem
public:
	MyWorld();
	void setRobot(Robot*);
	void setMaze(DocumentedMaze*);
	bool isThere_a_wall(int,int);
	void printStateDescription();
	void printState(double);
	void simulate (double, Maze*);
	virtual ~MyWorld();
};

#endif /* MYWORLD_H_ */
