/*r
 * MyWorld.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: gabrielrudloff
 */

#include "MyWorld.h"

MyWorld::MyWorld() {
	t=0;
	r=NULL;
	maze=NULL;
}

void MyWorld::setRobot(Robot* r) {
	this->r=r;
}
void MyWorld::setMaze(Maze* m) {
	maze = m;
}
bool MyWorld::isThere_a_wall(int x, int y){
	return maze->isThere_a_wall(x,y);
}
void MyWorld::printStateDescription(){
   cout << "Time" << ",\t" << r->getDescription()<< endl;
}

void MyWorld::printState(double t){
   cout << t << ",\t" << r->toString()<< endl;
}

void MyWorld::simulate (double delta_t, double endTime,Maze* route) {  // simulate time passing by
	for (; t < endTime; t += delta_t) {
		r->moveDelta_t(delta_t);
		printState(t);
		r->markRoute(route);
	}
}

MyWorld::~MyWorld() {
}

