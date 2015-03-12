//Author: Pedro Aranha - Section B

#include <iostream>
#include <string>
#include "gmatrix.cpp"
using namespace std;

int main(){
  GMatrix gm(5, 3, 1, 2);
  GMatrix gm2(-10, -6, -1, 2);
  cout << "GM1" << endl << gm;
  cout << "GM2" << endl << gm2;

  gm = gm2;

  cout << "GM1" << endl << gm;

  GMatrix gm3(5, 3, 1, 2);

  gm = gm3;

  cout << "GM1" << endl << gm;

  cout << "testing stuff" <<endl <<endl ;

  GMatrix tmp(100,100,1,1);

  GMatrix tmp2(10,10,1,1);

  tmp = tmp2;

  cout << tmp <<endl;
  cout << "hey" << endl;

  GMatrix tmp3(tmp);
  cout << tmp3 <<endl;

}
