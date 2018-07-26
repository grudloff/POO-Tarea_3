/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector2D.h
 * Author: LeonardoSolisZamora
 *
 * Created on 21 de julio de 2018, 13:00
 */

#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <string>
#include <sstream>
using namespace std;

class Vector2D {
private:
	double x,y;
public:
	Vector2D();
	Vector2D(double, double);
	double getX();
	double getY();
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



#endif /* VECTOR2D_H */

