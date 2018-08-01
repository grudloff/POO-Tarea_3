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
using namespace std;

class MyWorld {
private:
	double t;
	Robot *r1,*r2;//puntero para no necesitar inicializarlo
	DocumentedMaze *maze;//idem
public:
	MyWorld();
	void setRobot(Robot*,Robot*);
	void setMaze(DocumentedMaze*);
	bool isThere_a_wall(int,int);
	void printStateDescription();
	void printState(double,bool u);
	void simulate (double,Maze*,Maze*);
	virtual ~MyWorld();
};

#endif /* MYWORLD_H_ */
