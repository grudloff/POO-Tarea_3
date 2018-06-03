/*
 * MyWorld.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: gabrielrudloff
 */

#include "MyWorld.h"

MyWorld::MyWorld() {
	t=0;
	r=new Robot();
}

void MyWorld::setRobot(Robot* r) {
	   this->r=r;
   }
void MyWorld::printStateDescription(){
   cout << "Time" << ",\t" << r->getDescription()<< endl;
}

void MyWorld::printState(double t){
   cout << t << ",\t" << r->toString()<< endl;
}

void MyWorld::simulate (double delta_t, double endTime) {  // simulate time passing by
	for (; t < endTime; t += delta_t) {
		r->moveDelta_t(delta_t);
		printState(t);
	}
}

MyWorld::~MyWorld() {
}

