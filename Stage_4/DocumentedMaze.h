/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DocumentedMaze.h
 * Author: LeonardoSolisZamora
 *
 * Created on 30 de julio de 2018, 20:22
 */

#ifndef DOCUMENTEDMAZE_H
#define DOCUMENTEDMAZE_H
#include "Maze.h"
#include <iostream>

class DocumentedMaze : public Maze{
private:
	Vector2D entrance, dir, exit;
	double exitRadius;
public:
    DocumentedMaze(ifstream&);
    void setEntrance(int ,int);
    void setDirection(int,int);
    void setExit(int, int);
    void setExitRadius(int);
    Vector2D getEntrance();
    Vector2D getDirection();
    Vector2D getExit();
    double getExitRadius();
};
#endif /* DOCUMENTEDMAZE_h */



