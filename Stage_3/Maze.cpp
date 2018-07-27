#include "Maze.h"

Maze::Maze(ifstream &maze_in){
  string w;
  string h;
  
  maze_in.ignore(256,'\n');// Se salta la primera l�nea
  maze_in.ignore(256,'\n');// Se salta la 2da l�nea
  
  getline(maze_in,w,' ');// Almacena width
  width=atoi(&w[0]);// Convierte string a int
  getline(maze_in,h,'\n');// Almacena el hight
  hight=atoi(&h[0]);// Convierte string a int
  
  array = new bool*[hight];

  for(int i = 0; i < hight; i++)  {
      array[i] = new bool[width];
  }
     
  string s;
  int f=0;//fila
  int c=0;//columna
  
  while(1){//Se toma una linea de texto
  getline(maze_in,s);
  s.push_back('\n');
   int k=0;
   while(s[k]!='\n'){
      array[f][c]=(s[k]=='1');
      c++;
      k++;
      if(c==width){
         f++;
         c=0;
      }   
      if(f==hight){
    	  goto MACRO1;
      }
   }
   
  }
MACRO1:
  maze_in.close();
}

bool Maze::isThere_a_wall(int x, int y){
   return this->array[y][x];      
}


void Maze::markPoint(Vector2D p){
   array[(int)p.getY()][(int)p.getX()]=true;
}

void Maze::rotate(){
	bool** array_aux = new bool*[hight];

	  // allocate memories related to the number of columns of each row
	  for(int i = 0; i < hight; i++)
	  {
	      array_aux[i] = new bool[width];
	  }
   
   for(int w=0;w<(width);w++){
      for(int h=0;h<(hight);h++){
         array_aux[w][h]=array[h][(width)-1-w];
      }
	}
	int hight_aux=hight;
	hight=width;
	width=hight_aux;

	//Free each sub-array
	for(int i = 0; i < hight; ++i) {
		delete[] array[i];
	}
	//Free the array of pointers
	delete[] array;

	array=array_aux;
   
}

void Maze::write(ofstream &out){
   out <<"P1"<<endl;
   out << "#Created by UTFSM ELO329"<<endl;
   out << width <<" "<< hight <<endl;
   for(int i=0;i<hight;i++){
      for(int j=0;j<width;j++){
         out<<array[i][j];
      }
      out<<endl;
   }
   
   out.close();
}

Maze::~Maze(){
	//Free each sub-array
	for(int i = 0; i < hight; ++i) {
		delete[] array[i];
	}
	//Free the array of pointers
	delete[] array;
}
