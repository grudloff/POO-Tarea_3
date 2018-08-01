/*r
 * MyWorld.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: gabrielrudloff
 */

#include "MyWorld.h"

MyWorld::MyWorld() {
	t=0;
	r1=NULL;
	r2=NULL;
	maze=NULL;
}

void MyWorld::setRobot(Robot* r1,Robot* r2) {
	this->r1=r1;
	this->r2=r2;
}
void MyWorld::setMaze(DocumentedMaze* maze) {
	this->maze = maze;
}
bool MyWorld::isThere_a_wall(int x, int y){
	return maze->isThere_a_wall(x,y);
}
void MyWorld::printStateDescription(){
   cout << "Time" << ",\t" << r1->getDescription()<< endl;
}

void MyWorld::printState(double t,bool u){
	if(u)
		cout << t << ",\t" << r1->toString()<< endl;
	else
		cout << t << ",\t" << r2->toString()<< endl;
}

void MyWorld::simulate (double delta_t,Maze* route1,Maze* route2) {  // simulate time passing by
	while (!((r1->getPosition()-maze->getExit()).getModule()<maze->getExitRadius())){
		//printState(t,true);//debug
		r1->moveDelta_t(delta_t);
		r1->markRoute(route1);
		t+=delta_t;
	}
	double t_max=t;
	t=0;
	while (!((r2->getPosition()-maze->getExit()).getModule()<maze->getExitRadius())||t>t_max){
		r2->moveDelta_t(delta_t);
		//printState(t,false);//debug
		r2->markRoute(route2);
		t+=delta_t;
	}
}

MyWorld::~MyWorld() {
}

