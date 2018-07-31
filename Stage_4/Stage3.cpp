#include "Vector2D.h"
#include "MyWorld.h"
#include "Robot.h"

int main(int argc, char *argv[]){

	if (argc !=3){
			printf("El input tiene que ser el nombre del maze de entrada y luego el de salida\n");
			return -1;
		}

	ifstream maze_in;
	maze_in.open(argv[1]);
//	maze_in.open("maze_in.pbm");

	ofstream maze_out;
	maze_out.open(argv[2]);
//	maze_out.open("maze_out.pbm");

	Maze maze=Maze(maze_in);
	maze_in.open("maze_in.pbm");
	Maze route = Maze(maze_in);

	double deltaTime = 0.1;    // [s]
	MyWorld world;

	world.setMaze(&maze);
	Vector2D position(10,20);  //Col ln 15 5 [m]
	Vector2D velocity(0.0,1.0);     // [m/s]
	double sensorRange = 3;
	Robot r(position, velocity, sensorRange, &world);
	world.setRobot(&r);
	world.printStateDescription();
	world.simulate(deltaTime, 120, &route); // delta time[s], total simulation time [s].
	route.write(maze_out);

}
