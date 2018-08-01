
stage4Test: Stage4.o MyWorld.o Robot.o Vector2D.o DocumentedMaze.o 
	g++ stage1Test.o MyWorld.o Robot.o Vector2D.o -o stage1Test
	
Stage4.o: Stage4.cpp
	g++ -c Stage4.cpp

DocumentedMaze.o: DocumentedMaze.cpp DocumentedMaze.h Maze.h
	g++ -c DocumentedMaze.cpp

MyWorld.o: MyWorld.cpp MyWorld.h Robot.h Maze.h
	g++ -c MyWorld.cpp

Maze.o: Maze.cpp Maze.h Vector2D.h
	g++ -c Maze.cpp

Robot.o: Robot.cpp Robot.h Vector2D.h Maze.h 
	g++ -c Robot.cpp

Vector2D.o: Vector2D.cpp Vector2D.h
	g++ -c Vector2D.cpp
	
clean:
	rm *.o 