/*
 * Vector2D.h
 *
 *  Created on: Jun 2, 2018
 *      Author: gabrielrudloff
 */

#ifndef VECTOR2D_H_
#define VECTOR2D_H_

#include <string>
#include <sstream>
using namespace std;

class Vector2D {
private:
	double x,y;
public:
	Vector2D();
	Vector2D(double, double);
	Vector2D getUnitary();
	double getX();
	double getY();
	void turnLeft();
	void turnRight();
	void setTo(double,double);
	void setX(double);
	void setY(double);
	Vector2D operator=(Vector2D);
	Vector2D operator+(Vector2D);
	Vector2D operator-(Vector2D);
	Vector2D operator*(double);
	string getDescription();
	string toString();

	virtual ~Vector2D();
};

#endif /* VECTOR2D_H_ */
