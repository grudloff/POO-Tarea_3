
stage2Test: stage2Test.o Maze.o Vector2D.o
	g++ stage2Test.o Maze.o Vector2D.o -o stage2Test
	
stage2Test.o: stage2Test.cpp Maze.h
	g++ -c stage2Test.cpp

Maze.o: Maze.cpp Maze.h Vector2D.h
	g++ -c Maze.cpp

Vector2D.o: Vector2D.cpp Vector2D.h
	g++ -c Vector2D.cpp
	
clean:
	rm *.o 