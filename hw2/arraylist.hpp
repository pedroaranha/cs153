//Author: Pedro Aranha - Section B

#include <iostream>
#include <string>
using namespace std;

template <typename T>
ArrayList<T>::~ArrayList(){
  m_size = 0;
  m_max = 0;
  delete [] m_data;
  m_data = NULL;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs){
  if(this != &rhs){
    m_size = rhs.m_size;
    m_max = rhs.m_max;
    delete [] m_data;
    m_data = new T[m_max];

    for(int k = 0; k < m_size; k++){
      m_data[k] = rhs.m_data[k];
    }
  }
  return *this;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy){
  m_data = NULL;
  *this = cpy;
}

template <typename T>
int ArrayList<T>::size() const{
  return m_size;
}

template <typename T>
const T& ArrayList<T>::first() const{
  if(m_size != 0){
    return m_data[0];
  }
  else{
    cout << "!-- ERROR : PANIC in ARRAYLIST.first()!!  (List is empty)" << endl;
    return m_errobj;
  }
}

template <typename T>
T& ArrayList<T>::operator[](int i){
  if(i < m_size){
    return m_data[i];
  }
  else{
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.[]  (index out of bounds)" << endl;
    return m_errobj;
  }
}

template <typename T>
const T& ArrayList<T>::operator[](int i) const{
  if(i < m_size){
    return m_data[i];
  }
  else{
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.[]  (index out of bounds)" << endl;
    return m_errobj;
  }
}

template <typename T>
int ArrayList<T>::find(const T& x){
  for(int i = 0; i < m_size; i++){
    if(m_data[i] == x){
      return i;
    }
  }
  return -1;
}

template <typename T>
void ArrayList<T>::clear(){
  m_size = 0;
  m_max = 0;
  delete [] m_data;
  m_data = NULL;
}

template <typename T>
void ArrayList<T>::insert_back(const T& x){
  if(m_size < m_max){
    m_data[m_size] = x;
    m_size++;
  }
  else{
    T* tmp;
    tmp = new T[m_size*2];
    for(int k = 0; k < m_size; k++){
      tmp[k] = m_data[k];
    }
    delete [] m_data;
    m_data = tmp;
    m_max = m_size * 2;
    m_data[m_size] = x;
    m_size++;
  }
}

template <typename T>
void ArrayList<T>::insert(const T& x, int i){
  if(i < m_size){
    if(m_size < m_max){
      T* temp;
      temp = new T[m_size+1];
      for(int k = 0; k < m_size; k++){
        if(k < i){
          temp[k] = m_data[k];
        }
        else{
          temp[k+1] = m_data[k];
        }
      }
      delete [] m_data;
      m_data = temp;
      m_data[i] = x;
      m_size++;
    }
    else{
      T* tmp;
      tmp = new T[m_size*2];
      for(int k = 0; k < m_size; k++){
        if(k < i){
          tmp[k] = m_data[k];
        }
        else{
          tmp[k+1] = m_data[k];
        }
      }
      delete [] m_data;
      m_data = tmp;
      m_max = m_size * 2;
      m_data[i] = x;
      m_size++;
    }
  }
  else{
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.insert()  (index out of bounds)" << endl;
  }
}

template <typename T>
void ArrayList<T>::remove(int i){
  if(i < m_size){
    if(m_size > 0){
      for(int h = i; h < m_size; h++){
        if(h != m_size)
          m_data[h] = m_data[h+1];
      }
      m_size--;
      if(m_size < m_max/4){
        T* tmp;
        tmp = new T[m_max/2];
        for(int k = 0; k < m_size; k++){
          tmp[k] = m_data[k];
        }
        delete [] m_data;
        m_data = tmp;
        m_max = m_max / 2;
      }
    }
  }
  else{
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.remove()  (index out of bounds)" << endl;
  }
}

template <typename T>
void ArrayList<T>::swap(int i, int k){
  if(i < m_size && k < m_size){
    T tmp;
    tmp = m_data[i];
    m_data[i] = m_data[k];
    m_data[k] = tmp;
  }
  else{
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.swap()  (index out of bounds)" << endl;
  }
}

template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist){
  for(int i = 0; i < alist.m_size; i++){
    this->insert_back(alist.m_data[i]);
  }
}

template <typename T>
void ArrayList<T>::purge(){
  for(int i = 0; i < m_size; i++){
    for(int j = i+1; j < m_size; j++){
      if(m_data[j] == m_data[i]){
        this->remove(j);
      }
    }
    ;
  }
}

