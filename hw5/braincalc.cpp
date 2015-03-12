//Author: Pedro Aranha. Section: B
#include <iostream>
#include <string>
#include <cstdlib>
#include "stack.cpp"

using namespace std;

int main () {
  string input;
  int val1, val2;
  BrainStack<int> bstack;

  cin >> input;
  while(true){
    if(input == "+"){
      val1 = bstack.top();
      bstack.pop();
      val2 = bstack.top();
      bstack.pop();
      bstack.push(val2 + val1);
    }
    else if(input == "-"){
      val1 = bstack.top();
      bstack.pop();
      val2 = bstack.top();
      bstack.pop();
      bstack.push(val2 - val1);
    }
    else if(input == "*"){
      val1 = bstack.top();
      bstack.pop();
      val2 = bstack.top();
      bstack.pop();
      bstack.push(val2 * val1);
    }
    else if(input == "/"){
      val1 = bstack.top();
      bstack.pop();
      val2 = bstack.top();
      bstack.pop();
      bstack.push(val2 / val1);
    }
    else if(input == "\%"){
      val1 = bstack.top();
      bstack.pop();
      val2 = bstack.top();
      bstack.pop();
      bstack.push(val2 % val1);
    }
    else if(input == "!"){
      val1 = bstack.top();
      bstack.pop();
      bstack.push(val1 * -1);
    }
    else if(input != "$" && input != "#"){
      bstack.push(atoi( input.c_str() ));
    }

    cin >> input;
    if(input == "#") break;
    if(input == "$"){
      int size = bstack.size();
      cout << "[ ";
      for(int i = 0; i < size; i++){
        try{
          cout << bstack.top();
        }
        catch( Oops e ){
          cout << e.m_errormsg;
        }
        if(i < size - 1)
          cout << ", ";
        bstack.pop();
      }
      cout << " ]" << endl;
      bstack.clear();
    }
  }

  return 0;
}