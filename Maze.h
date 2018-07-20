/*
 * Maze.h
 *
 *  Created on: Jul 9, 2018
 *      Author: leonardosoliszamora
 */

// https://stackoverflow.com/questions/12375591/vector-of-vectors-to-create-matrix
// http://www.cplusplus.com/reference/vector/vector/push_back/
// http://www.cplusplus.com/reference/ostream/basic_ostream/write/

#ifndef MAZE_H_
#define MAZE_H_

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
//#include "Vector2D.h"

using namespace std;

class Maze{
   public:
      int hight;
      int width;
      vector<vector<bool>> array;
   public:
      Maze();
      Maze(int,int);
      bool isThere_a_wall(int x, int y);
      //void markPoint(Vector2D p);
      void rotate();
      void write();
      //virtual ~Maze();
   	
};


#endif /* MAZE_H_ */
