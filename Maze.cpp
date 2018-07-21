#include "Maze.h"


using namespace std;

Maze::Maze(int a, int b){
   hight=a;
   width=b;
}

Maze::Maze(ifstream &maze_in){
  string w;
  string h;
  
  maze_in.ignore(256,'\n');// Se salta la primera línea
  maze_in.ignore(256,'\n');// Se salta la 2da línea
  
  getline(maze_in,w,' ');// Almacena width
  int width=atoi(&w[0]);// Convierte string a int
  this->width=width;
  getline(maze_in,h,'\n');// Almacena el hight
  int hight=atoi(&h[0]);// Convierte string a int
  this->hight=hight;
  
  //Se crea la matriz booleana, llena de ceros
  for(int i = 0; i<hight; i++){
    
    vector<bool> col;
    for(int j = 0; j<width; j++){   
        col.push_back(0);
    }
    this->array.push_back(col);
  
  }
     
  string s;
  int f=0;//fila
  int c=0;//columna
  
  while(getline(maze_in,s)){//Se toma una linea de texto
   
   int sz= s.size();
   for(int k=0;k<sz;k++){
      this->array[f][c]=(s[k]=='1');
      //cout<<array[f][c];
      c++;
      
      
      if(c>=width){
         f++;
         c=0;
         //cout<<"\n";
      }   
   }
   
  }
  maze_in.close();
  
}

bool Maze::isThere_a_wall(int x, int y){
   return this->array[y][x];      
}


/*void Maze::markPoint(Vector2D p){
   array[(int)p.getY()][(int)p.getX()]=true;
}*/

void Maze::rotate(){
   vector<vector<bool>>array_aux;
   
   
    for(int j = 0; j<width; j++){//columnas  
     vector<bool> col;
     for(int i = 0; i<hight; i++){//filas   
         col.push_back(array[i][width-1-j]);
     }
     array_aux.push_back(col);
    }
    int hight_aux=hight;
    hight=width;
    width=hight_aux;
    array=array_aux;
  
    for(int j=0; j<array_aux.size();j++){//Destruye las columnas de array_aux
      array_aux[j].clear();  
    }
  
    array_aux.clear();//Destruye la fila de array_aux
  
}

void Maze::write(ofstream &out){
   int h=array.size();
   int w=array[0].size();
   out <<"P1"<<endl;
   out << "#Created by UTFSM ELO329"<<endl;
   out << h <<" "<< w<<endl;  
   for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
         out<<array[i][j];
      }
      out<<endl;
   }
   
   out.close();
}

Maze::~Maze(){
}