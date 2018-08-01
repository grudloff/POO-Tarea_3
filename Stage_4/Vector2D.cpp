/*
 * Vector2D.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: gabrielrudloff
 */

#include "Vector2D.h"

Vector2D::Vector2D() {
	x=y=0;
}

Vector2D::Vector2D(double x, double y) {
	this->x=x;
	this->y=y;
}

Vector2D Vector2D::getUnitary() {
	   return (*this)*(1/getModule());
   }

double Vector2D::getModule() {
	   return sqrt(x*x+y*y);
   }
void Vector2D::setX(double x) {
	this->x=x;
}

void Vector2D::setY(double y) {
	this->y=y;
}

double Vector2D::getX() {
	return x;
}

double Vector2D::getY() {
	return y;
}

void Vector2D::turnLeft(){
	double x_aux=x;
	x=y;
	y=-x_aux;
}

void Vector2D::turnRight(){
	double x_aux=x;
	x=-y;
	y=x_aux;
}

void Vector2D::setTo(double x, double y){
	   this->x=x;
	   this->y=y;
   }

Vector2D Vector2D::operator=(Vector2D vector){
	x=vector.getX();
	y=vector.getY();
	return *this;
}

Vector2D Vector2D::operator+(Vector2D vector){
	Vector2D temp;
	temp.setX(x+vector.getX());
	temp.setY(y+vector.getY());
	return temp;
}

Vector2D Vector2D::operator-(Vector2D vector){
	Vector2D temp;
	temp.setX(x-vector.getX());
	temp.setY(y-vector.getY());
	return temp;
}

Vector2D Vector2D::operator*(double a){
	Vector2D temp;
	temp.setX(x*a);
	temp.setY(y*a);
	return temp;
}

Vector2D operator*(int a,Vector2D vector){
	Vector2D temp;
	temp.setX(vector.getX()*a);
	temp.setY(vector.getY()*a);
	return temp;
}

Vector2D operator*(double a,Vector2D vector){
	Vector2D temp;
	temp.setX(vector.getX()*a);
	temp.setY(vector.getY()*a);
	return temp;
}

string Vector2D::getDescription(){
	return "x, \t y";
}

string Vector2D::toString(){
	stringstream aux;
	aux << getX() << "\t" << getY();
	return aux.str();
}


Vector2D::~Vector2D() {

}

