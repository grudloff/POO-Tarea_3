/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "DocumentedMaze.h"

DocumentedMaze::DocumentedMaze(ifstream& sc){
    Maze();
    
    string aux;
    
    sc.ignore(256,'\n');// Se salta la primera l�nea
    //sc.ignore(256,'\n');// Se salta la 2da l�nea
    
    getline(sc,aux,' ');// Almacena entrada x
    int pos_x=atoi(&aux[0]);// Convierte string a int
    
    getline(sc, aux,' ');// Almacena entrada y
    int pos_y=atoi(&aux[0]);// Convierte string a int
    
    getline(sc, aux,' ');// Almacena direccion x
    int dirx=atoi(&aux[0]);// Convierte string a int
    
    getline(sc, aux,' ');// Almacena direccion y
    int diry=atoi(&aux[0]);// Convierte string a int
    
    getline(sc, aux,' ');// Almacena salida x
    int exitx=atoi(&aux[0]);// Convierte string a int
    
    getline(sc, aux,' ');// Almacena salida y
    int exity=atoi(&aux[0]);// Convierte string a int
    
    getline(sc, aux,'\n');// Almacena salida y
    int r=atoi(&aux[0]);// Convierte string a int
    
    
    entrance.setTo(pos_x,pos_y);
    dir.setTo(dirx, diry);
    exit.setTo(exitx,exity);
    setExitRadius(r);
    
    read(sc);    
}

void DocumentedMaze::setEntrance(int x, int y){
   entrance.setTo(x,y);
}

void DocumentedMaze::setDirection(int x, int y){
   dir.setTo(x,y);
}

void DocumentedMaze::setExit(int x, int y){
   exit.setTo(x,y);
}

void DocumentedMaze::setExitRadius(int r){
   exitRadius = r;
}

Vector2D DocumentedMaze::getEntrance() {
   return entrance;
}

Vector2D DocumentedMaze::getDirection() {
   return dir;
}

Vector2D DocumentedMaze::getExit() {
   return exit;
}

double DocumentedMaze::getExitRadius() {
   return exitRadius;
}

