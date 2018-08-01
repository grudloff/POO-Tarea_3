#FLAGS=-g -DDEBUG 

stage5Test: stage5Test.o DocumentedMaze.o Maze.o MyWorld.o Robot.o Vector2D.o
	g++ Maze.o MyWorld.o DocumentedMaze.o Robot.o stage5Test.o Vector2D.o -o stage5Test
	
stage5Test.o: stage5Test.cpp Vector2D.h MyWorld.h Robot.h Maze.h DocumentedMaze.h
	g++ -c stage5Test.cpp

Maze.o: Maze.cpp Maze.h Vector2D.h
	g++ -c Maze.cpp

DocumentedMaze.o: DocumentedMaze.cpp DocumentedMaze.h Maze.h Vector2D.h
	g++ -c DocumentedMaze.cpp

MyWorld.o: MyWorld.cpp MyWorld.h Robot.h Maze.h DocumentedMaze.h
	g++ -c MyWorld.cpp

Robot.o: Robot.cpp Robot.h Maze.h Vector2D.h MyWorld.h
	g++ -c Robot.cpp

Vector2D.o: Vector2D.cpp Vector2D.h
	g++ -c Vector2D.cpp
	
clean:
	rm *.o 

	
