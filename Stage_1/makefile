
stage1Test: stage1Test.o MyWorld.o Robot.o Vector2D.o
	g++ stage1Test.o MyWorld.o Robot.o Vector2D.o -o stage1Test
	
Stage3.o: stage1Test.cpp
	g++ -c stage1Test.cpp

MyWorld.o: MyWorld.cpp MyWorld.h Robot.h
	g++ -c MyWorld.cpp

Robot.o: Robot.cpp Robot.h Vector2D.h
	g++ -c Robot.cpp

Vector2D.o: Vector2D.cpp Vector2D.h
	g++ -c Vector2D.cpp
	
clean:
	rm *.o 

	
