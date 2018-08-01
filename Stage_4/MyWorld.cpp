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
void MyWorld::setMaze(DocumentedMaze* m) {
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

void MyWorld::simulate (double delta_t ,Maze* route) {  // simulate time passing by
	while (!((r->getPosition()-maze->getExit()).getModule()<maze->getExitRadius())&&(t<2000)){
		//printState(t);  //debug
		r->moveDelta_t(delta_t);
		r->markRoute(route);
		t+=delta_t;
	}
}

MyWorld::~MyWorld() {
}

