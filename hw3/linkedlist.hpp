//Author: Pedro Aranha - Section B

#include <iostream>
#include <string>
using namespace std;

//not sure...
template <class T>
const LinkedList<T>&  LinkedList<T>::operator= (const LinkedList<T>& rhs){
  if(!(this == &rhs)){

    LinkedList* tmp = this;
    LinkedList* current_next = rhs.m_next;
    T current_data = rhs.m_data;

    while(current_next != NULL){
      tmp->m_next = new LinkedList;
      tmp->m_data = current_data;

      tmp = tmp->m_next;
      current_data = current_next->m_data;
      current_next = current_next->m_next;
    }

    delete current_next;
  }
  return *this;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs){
  m_next = NULL;
  *this = rhs;
}

template <class T>
int LinkedList<T>::size() const{
  const LinkedList* indy = this;
  int counter = 0;

  while(indy->m_next != NULL){
    counter++;
    indy = indy->m_next;
  }
  return counter;
}

template <class T>
bool LinkedList<T>::isEmpty() const{
  return (this->m_next == NULL);
}

template <class T>
LinkedList<T>* LinkedList<T>::getFirstPtr(){
  if(!isEmpty()){
    return this;
  }
  else{
    cout << "PANIC in LinkedList.getFirstPtr() - empty list" << endl;
    return NULL;
  }
}

template <class T>
LinkedList<T>* LinkedList<T>::getLastPtr(){
  if(!isEmpty()){

    LinkedList* current = this;

    while(current->m_next->m_next != NULL){
      current = current->m_next;
    }

    return current;
  }
  else{
    cout << "PANIC in LinkedList.getLastPtr() - empty list" << endl;
    return NULL;
  }
}

template <class T>
LinkedList<T>* LinkedList<T>::getAtPtr(int i){
  if(!isEmpty()){
    if(i < this->size()){

      LinkedList* current = this;

      for(int k = 0; k < i; k++){
        current = current->m_next;
      }

      return current;

    }
    else{
      cout << "PANIC in LinkedList.getAtPtr() - invalid index" << endl;
      return NULL;
    }
  }
  else{
    cout << "PANIC in LinkedList.getAtPtr() - empty list" << endl;
    return NULL;
  }

}

template <class T>
void LinkedList<T>::clear(){

  LinkedList* current = this;

  while(current->m_next != NULL){
    current = current->m_next;
    remove(this);
  }
}

template <class T>
void LinkedList<T>::insert_front(const T& x){

  LinkedList* tmp;
  tmp = new LinkedList;
  tmp->m_data = this->m_data;
  tmp->m_next = this->m_next;

  this->m_data = x;

  this->m_next = tmp;
}

template <class T>
void LinkedList<T>::insert(const T& x, LinkedList<T>* pos){
    LinkedList* tmp;
    tmp = new LinkedList;
    tmp->m_data = pos->m_data;
    tmp->m_next = pos->m_next;

    pos->m_data = x;

    pos->m_next = tmp;
}

template <class T>
void LinkedList<T>::remove(LinkedList<T>* pos){
  if(pos->m_next != NULL){
    LinkedList *tmp = pos->m_next;

    pos->m_data = tmp->m_data;
    pos->m_next = tmp->m_next;
    delete tmp;
  }
}

template <class T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const{
  LinkedList* current_this = this->m_next;
  LinkedList* current_rhs = rhs.m_next;

  if(this->m_data != rhs.m_data){
    return false;
  }

  while(current_this->m_next != NULL || current_rhs->m_next != NULL){
    if(current_this->m_data != current_rhs->m_data){
      return false;
    }
    current_this = current_this->m_next;
    current_rhs = current_rhs->m_next;
  }
  return true;
}

template <class T>
LinkedList<T>* LinkedList<T>::find(const T& x){
  LinkedList* p = this;

  while(p->m_next != NULL){
    if(p->m_data == x){
      return p;
    }
    p = p->m_next;
  }
  return NULL;
}

template <class T>
void LinkedList<T>::reverse(){

  LinkedList* current = this;
  LinkedList* reversed = new LinkedList;
  LinkedList* reversed_start = reversed;
  int size = this->size();

  for(int i = 0; i < size; i++){
    reversed->m_data = this->getLastPtr()->m_data;
    reversed->m_next = new LinkedList;

    reversed = reversed->m_next;
    remove(this->getLastPtr());
  }

  this->m_next = reversed_start->m_next;
  this->m_data = reversed_start->m_data;

  // while(reversed_start->m_next != NULL){
  //   reversed = reversed_start;

  //   current->m_data = reversed_start->m_data;
  //   current->m_next = new LinkedList;


  //   reversed_start = reversed_start->m_next;
  //   current = current->m_next;

  //   delete reversed;
  // }
  delete reversed_start;
}

template <class T>
void LinkedList<T>::append(const LinkedList<T>& xlist){
  LinkedList* last_this = this;
  LinkedList* p = xlist.m_next;

  while(last_this->m_next != NULL){
    last_this = last_this->m_next;
  }

  last_this->insert_front(xlist.m_data);
  last_this = last_this->m_next;

  while(p->m_next != NULL){
    last_this->insert_front(p->m_data);
    p = p->m_next;
    last_this = last_this->m_next;
  }
}
