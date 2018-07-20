// www.cplusplus.com/reference/string/stoi/
// http://www.cplusplus.com/reference/istream/istream/getline/

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
  ifstream maze_in;
  
  string w;
  string h;
        
  maze_in.open("maze_in.pbm");
  
  maze_in.ignore(256,'\n');// Se salta la primera línea
  maze_in.ignore(256,'\n');// Se salta la 2da línea
  
  getline(maze_in,w,' ');// Almacena width
  //int width=stoi(w,nullptr,0);// Convierte string a int
  int width=atoi(&w[0]);// Convierte string a int  
  getline(maze_in,h,'\n');// Almacena el hight
  //int hight=stoi(h,nullptr,0);// Convierte string a int
  int hight=atoi(&h[0]);// Convierte string a int   
  
  bool array[hight][width];
  
  string s;
  int f=0;//fila
  int c=0;//columna
  while(getline(maze_in,s)){//Se toma una linea de texto
   
   int sz= s.size();
   for(int k=0;k<sz;k++){
   
      array[f][c]=(s[k]=='1');
      cout<<array[f][c];
      c++;
      
      if(c>width){
         f++;
         c=0;
         cout<<' '<<endl;
      }   
   }   
  }
 }