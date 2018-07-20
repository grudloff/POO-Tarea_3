#include "Maze.h"
//using namespace std;
Maze::Maze(int a, int b){
   hight=a;
   width=b;
}

Maze::Maze(){
  cout<<"holamen";   
  string w;
  string h;
  ifstream maze_in;      
  maze_in.open("maze_in.pbm");
  
  maze_in.ignore(256,'\n');// Se salta la primera línea
  maze_in.ignore(256,'\n');// Se salta la 2da línea
  
  getline(maze_in,w,' ');// Almacena width
  int width=stoi(w,nullptr,0);// Convierte string a int
  this->width=width;
  getline(maze_in,h,'\n');// Almacena el hight
  int hight=stoi(h,nullptr,0);// Convierte string a int
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
      cout<<array[f][c];
      c++;
      
      
      if(c>=width){
         f++;
         c=0;
         cout<<"\n";
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
   
   for(int w=0;w<(this->width);w++){
      for(int h=0;h<(this->hight);h++){
         array_aux[w][h]=this->array[h][(this->width)-1-w];
      }
   }
   int hight_aux=hight;
	this->hight=this->width;
	this->width=hight_aux;
	this->array=array_aux;
   
}

void Maze::write(){
   ofstream out;
   int h=this->array.size();
   int w=this->array[0].size();
   out.open ("maze_out.pbm");
   out <<"P1"<<endl;
   out << "#Created by UTFSM ELO329"<<endl;
   out << h <<" "<< w<<endl;  
   for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
         out<<this->array[i][j];
      }
      out<<endl;
   }
   
   out.close();
}