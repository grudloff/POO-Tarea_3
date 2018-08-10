
Stage4: Stage4.o MyWorld.o Robot.o Vector2D.o Maze.o DocumentedMaze.o 
	g++ Stage4.o MyWorld.o Robot.o Vector2D.o Maze.o DocumentedMaze.o  -o Stage4
	
Stage4.o: Stage4.cpp Vector2D.h MyWorld.h Robot.h Maze.h DocumentedMaze.h
	g++ -c Stage4.cpp

DocumentedMaze.o: DocumentedMaze.cpp DocumentedMaze.h Maze.h Vector2D.h
	g++ -c DocumentedMaze.cpp

MyWorld.o: MyWorld.cpp MyWorld.h Robot.h Maze.h DocumentedMaze.h
	g++ -c MyWorld.cpp

Maze.o: Maze.cpp Maze.h Vector2D.h
	g++ -c Maze.cpp

Robot.o: Robot.cpp Robot.h Vector2D.h Maze.h MyWorld.h
	g++ -c Robot.cpp

Vector2D.o: Vector2D.cpp Vector2D.h
	g++ -c Vector2D.cpp
	
clean:
	rm *.o 
