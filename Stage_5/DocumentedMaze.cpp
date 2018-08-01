/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "DocumentedMaze.h"

DocumentedMaze::DocumentedMaze(ifstream& sc){
    string aux;
    int valores[7];
    int i=0;

    sc.ignore(256,'\n');// Se salta la primera l�nea
    
    getline(sc,aux,' ');//Se salta el #

    //Podria hacerse esto con un for para los 7 elementos
    //pero no se garantiza no tener espacios extra
    aux="";
    while(aux.empty()&&i<7){
    	getline(sc,aux,' ');
    	if(!aux.empty()){
    		valores[i]=atoi(&aux[0]);
    		aux="";
    		i++;
    	}
    }
    
    entrance.setTo(valores[1],valores[0]);
    dir.setTo(valores[3], valores[2]);
    exit.setTo(valores[5],valores[4]);
    setExitRadius(valores[6]);
    
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

