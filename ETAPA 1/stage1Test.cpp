#include "Vector2D.h"
#include "MyWorld.h"
#include "Robot.h"

int main(){

	double deltaTime = 0.1;    // [s]
	MyWorld world;

	Vector2D position(0,0);  // [m]
	Vector2D velocity(0.5,0.0);     // [m/s]
	Robot r(position, velocity);
	world.setRobot(&r);
	world.printStateDescription();
	world.simulate(deltaTime, 0.5); // delta time[s], total simulation time [s].
	r.turnLeft();
	world.simulate(deltaTime, 1); // delta time[s], total simulation time [s].
	r.turnRight();
	world.simulate(deltaTime, 1.5); // delta time[s], total simulation time [s].
	r.turnRight();
	world.simulate(deltaTime, 2); // delta time[s], total simulation time [s].

}
