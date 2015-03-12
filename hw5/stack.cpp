//Author: Pedro Aranha. Section: B
#include "abstractstack.h"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class BrainStack : public AbstractStack<T>{
private:
  int m_top;
  int m_max;
  T* m_data;

public:
  BrainStack(): m_top(0), m_max(0), m_data(NULL) {};

	virtual void clear(){
    m_top = 0;
    m_max = 0;
    delete [] m_data;
    m_data = NULL;
	};

	virtual void push(const T& x){
    if(m_top < m_max){
      m_data[m_top] = x;
      m_top++;
    }
    else{
      T* tmp;
      tmp = new T[m_top*2];
      for(int k = 0; k < m_top; k++){
        tmp[k] = m_data[k];
      }
      delete [] m_data;
      m_data = tmp;
      m_max = m_top * 2;
      m_data[m_top] = x;
      m_top++;
    }
	};

  virtual void pop(){
    if(m_top > 0)
      m_top--;
    if(m_top < m_max/4){
      m_max = m_max/4;
    }
  };

  virtual const T& top() const throw ( Oops ){
    Oops e = Oops("something\n");
    if(m_top > 0){
      return m_data[m_top - 1];
    }
    else{
      throw(e);
    }
  };

  virtual bool isEmpty() const{
    if(m_top == 0) return true;
    else return false;
  };

  int size() const{
    return m_top;
  }

};