/* 
 * File:   main.cpp
 * Author: LeonardoSolisZamora
 *
 * Created on 21 de julio de 2018, 10:08
 */

#include <iostream>
#include "Maze.h"
using namespace std;

int main() {
   ifstream in;
   in.open("maze_in.pbm");
   Maze MyMaze(in);
   
   //ofstream init;
   //init.open("init_maze.pbm");
   //MyMaze.write(init);
   
   MyMaze.rotate();
   
   ofstream out;
   out.open ("maze_out.pbm");
   MyMaze.write(out);
   
   return 0;

}

