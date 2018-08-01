#include "Vector2D.h"
#include "MyWorld.h"
#include "Robot.h"
#include "DocumentedMaze.h"

int main(int argc, char *argv[]){
	ifstream maze_in;
	ofstream maze_out_1;
	ofstream maze_out_2;
	if (argc <3){
			printf("Uso: ./stage5Test d_maze_in.pbm  maze_out.pbm  [ix iy  dx  dy  fx  fy  r]\n");
			maze_in.open("d_maze_in.pbm");
			maze_out_1.open("maze_out_1.pbm");
			maze_out_2.open("maze_out_2.pbm");
		}

	else{
	maze_in.open(argv[1]);

	string s=argv[2];
	s+="_1";
	const char* c1=s.c_str();
	maze_out_1.open(c1);

	s=argv[2];
	s+="_2";
	const char* c2=s.c_str();
	maze_out_2.open(c2);
	}

	DocumentedMaze maze=DocumentedMaze(maze_in);
	Maze route_1 = Maze(maze);
	Maze route_2 = Maze(maze);

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
	double speed = 1.0;
	Vector2D velocity = maze.getDirection().getUnitary()*speed;     // [m/s]
	double sensorRange = 3;
	Robot r1(position, velocity, sensorRange, &world,false);
	Robot r2(position, velocity, sensorRange, &world,true);
	world.setRobot(&r1,&r2);
	//world.printStateDescription();//debug
	world.simulate(deltaTime, &route_1,&route_2); // delta time[s], total simulation time [s].
	route_1.write(maze_out_1);
	route_2.write(maze_out_2);

}
