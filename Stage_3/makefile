#FLAGS=-g -DDEBUG 

Stage3: Stage3.o Maze.o MyWorld.o Robot.o Vector2D.o
	g++ Maze.o MyWorld.o Robot.o Stage3.o Vector2D.o -o Stage3
	
Stage3.o: Stage3.cpp Vector2D.h MyWorld.h Robot.h
	g++ -c Stage3.cpp

Maze.o: Maze.cpp Maze.h Vector2D.h
	g++ -c Maze.cpp

MyWorld.o: MyWorld.cpp MyWorld.h Robot.h Maze.h
	g++ -c MyWorld.cpp

Robot.o: Robot.cpp Robot.h Maze.h Vector2D.h MyWorld.h
	g++ -c Robot.cpp

Vector2D.o: Vector2D.cpp Vector2D.h
	g++ -c Vector2D.cpp
	
clean:
	rm *.o 

	
