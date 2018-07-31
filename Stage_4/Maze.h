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
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Vector2D.h"

using namespace std;

class Maze {
   private:
      bool** array;
      int width;
      int hight;
   public:
      Maze();
      Maze(ifstream&);
      void read(ifstream&);
      bool isThere_a_wall(int, int);
      void markPoint(Vector2D);
      void rotate();
      void write(ofstream&);
      virtual ~Maze();
   	
};


#endif /* MAZE_H_ */
