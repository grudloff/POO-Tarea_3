// basic file operations
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream myfile;
  int a=2;
  myfile.open ("example.pbm");
  myfile << "Writing this to a file.\n";
  myfile << "ajajjaja \n";
  myfile << a << " es un numero";
  myfile.close();
  return 0;
}