#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/497b77f9/Maze.o \
	${OBJECTDIR}/_ext/497b77f9/MyWorld.o \
	${OBJECTDIR}/_ext/497b77f9/Robot.o \
	${OBJECTDIR}/_ext/497b77f9/Stage3.o \
	${OBJECTDIR}/_ext/497b77f9/Vector2D.o \
	${OBJECTDIR}/DocumentedMaze.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/stage4.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/stage4.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/stage4 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/497b77f9/Maze.o: ../Tarea\ 3\ POO/Stage_4/Maze.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/497b77f9
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/497b77f9/Maze.o ../Tarea\ 3\ POO/Stage_4/Maze.cpp

${OBJECTDIR}/_ext/497b77f9/MyWorld.o: ../Tarea\ 3\ POO/Stage_4/MyWorld.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/497b77f9
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/497b77f9/MyWorld.o ../Tarea\ 3\ POO/Stage_4/MyWorld.cpp

${OBJECTDIR}/_ext/497b77f9/Robot.o: ../Tarea\ 3\ POO/Stage_4/Robot.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/497b77f9
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/497b77f9/Robot.o ../Tarea\ 3\ POO/Stage_4/Robot.cpp

${OBJECTDIR}/_ext/497b77f9/Stage3.o: ../Tarea\ 3\ POO/Stage_4/Stage3.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/497b77f9
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/497b77f9/Stage3.o ../Tarea\ 3\ POO/Stage_4/Stage3.cpp

${OBJECTDIR}/_ext/497b77f9/Vector2D.o: ../Tarea\ 3\ POO/Stage_4/Vector2D.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/497b77f9
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/497b77f9/Vector2D.o ../Tarea\ 3\ POO/Stage_4/Vector2D.cpp

${OBJECTDIR}/DocumentedMaze.o: DocumentedMaze.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DocumentedMaze.o DocumentedMaze.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
