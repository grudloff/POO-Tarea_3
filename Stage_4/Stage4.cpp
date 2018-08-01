#include "Vector2D.h"
#include "MyWorld.h"
#include "Robot.h"
#include "DocumentedMaze.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
	ifstream maze_in;
	ofstream maze_out;
	if (argc <3){
			printf("Uso: ./stage4Test maze_in.pbm  maze_out.pbm  [ix iy  dx  dy  fx  fy  r]\n");
			maze_in.open("maze_in.pbm");
			maze_out.open("maze_out.pbm");

		}

	else{
	maze_in.open(argv[1]);
	maze_out.open(argv[2]);

	}

	DocumentedMaze maze=DocumentedMaze(maze_in);
	Maze route = Maze(maze);


	if (argc > 3)
		maze.setEntrance(atoi(argv[3]),atoi(argv[4]));
	if (argc > 5)
		maze.setDirection(atoi(argv[4]),atoi(argv[5]));
	if (argc > 7)
		maze.setExit(atoi(argv[6]),atoi(argv[7]));
	if (argc > 8)
		maze.setExitRadius(atoi(argv[8]));

	double deltaTime = 0.1;    // [s]
	MyWorld world;

	world.setMaze(&maze);
	Vector2D position = maze.getEntrance();;  //Col ln 15 5 [m]
    //Vector2D position(10,20);  //Col ln 15 5 [m]
	double speed = 1.0;
	Vector2D velocity = maze.getDirection().getUnitary()*speed;
	//Vector2D velocity(0.0,1.0);     // [m/s]
	double sensorRange = 3;
	Robot r(position, velocity, sensorRange, &world);
	world.setRobot(&r);
	//world.printStateDescription(); //debug
	world.simulate(deltaTime, &route); // delta time[s], total simulation time [s].
	route.write(maze_out);
}
