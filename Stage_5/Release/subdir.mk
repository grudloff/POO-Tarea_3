################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DocumentedMaze.cpp \
../Maze.cpp \
../MyWorld.cpp \
../Robot.cpp \
../Vector2D.cpp \
../stage5Test.cpp 

OBJS += \
./DocumentedMaze.o \
./Maze.o \
./MyWorld.o \
./Robot.o \
./Vector2D.o \
./stage5Test.o 

CPP_DEPS += \
./DocumentedMaze.d \
./Maze.d \
./MyWorld.d \
./Robot.d \
./Vector2D.d \
./stage5Test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


