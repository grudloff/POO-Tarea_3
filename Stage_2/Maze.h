/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Maze.h
 * Author: LeonardoSolisZamora
 *
 * Created on 21 de julio de 2018, 10:15
 */

#ifndef MAZE_H
#define MAZE_H

#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h> 
#include "Vector2D.h"

using namespace std;

class Maze{
      int hight;
      int width;
      vector<vector<bool> > array;
   public:
      Maze(ifstream &maze_in);
      Maze(int,int);
      bool isThere_a_wall(int x, int y);
      void markPoint(Vector2D p);
      void rotate();
      void write(ofstream &out);
      virtual ~Maze();
   	
};




#endif /* MAZE_H */

