#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(){
   int h=5;
   int c=8;
   vector<vector<bool>> array;
   
   vector<vector<bool>> aux;
   for(int i = 0; i<h; i++){
    
    vector<bool> col;
    for(int j = 0; j<c; j++){   
        col.push_back(0);
        cout<<col[j];
    }
    array.push_back(col);
    cout<<" "<<endl;
    
   }
   
  aux=array;
  ofstream myfile;
  myfile.open ("VectorExample.pbm");
  myfile <<"P1"<<endl;
  myfile << "#Created by UTFSM ELO329"<<endl;
  myfile << h <<" "<< c<<endl;
  for(int i=0;i<h;i++){
      for(int j=0;j<c;j++){
         myfile<<array[i][j];
      }
      myfile<<endl;
   }
  myfile.close();
   
   /*cout<<"\n"<<endl;
   string s="11111111111111";
   
      
   
   int sz= s.size();
   int f=0;
   int cc=0;
   for(int k=0;k<sz;k++){
   
      array[f][cc]=(s[k]=='1');
      cout<<array[f][cc];
      cc++;
      
      if(cc>5){
         f++;
         cc=0;
         cout<<' '<<endl;
      }   
   } */  
  
      
   return 0;
   
}