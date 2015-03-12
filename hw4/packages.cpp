#include <iostream>
#include <string>
#include <iomanip>
#include "2d_package.cpp"
#include "3d_package.cpp"
#include "4d_package.cpp"

using namespace std;


int main () {
  cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
  cout.precision(2);

  int num, dim;
  float profit = 0;
  string from, to;
  cin >> num;

  AbstractPackage** packages = new AbstractPackage*[num];

  for(int i = 0; i < num; i++){
    cin >> dim;
    cin >> from;
    cin >> to;

    if(dim == 2){
      float d1, d2;
      cin >> d1 >> d2;
      packages[i] = new TwoDPackage(from, to, d1, d2);
    }
    else if(dim == 3){
      float d1, d2, d3, weight;
      cin >> d1 >> d2 >> d3 >> weight;
      packages[i] = new ThreeDPackage(from, to, d1, d2, d3, weight);
    }
    else if(dim == 4){
      float d1, d2, d3, d4, weight;
      cin >> d1 >> d2 >> d3 >> d4 >> weight;
      packages[i] = new FourDPackage(from, to, d1, d2, d3, d4, weight);
    }
    else{
      cout << " Invalid dimension!!" << endl;
    }
  }

  for(int i = 0; i < num; i++){
    cout << "#" << i << ": From " << packages[i]->getFrom() << " to " << packages[i]->getTo() << endl;
    cout << "$" << packages[i]->getCharge() << endl;
    profit += packages[i]->getCharge();
    delete packages[i];
  }

  cout << endl << "TOTAL PROFIT = $" << profit << endl;
  cout << "AVERAGE = $" << (profit/num) << endl;

  delete [] packages;

  return 0;
}