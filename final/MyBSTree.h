//Author: Pedro Aranha. Section: B
#include "abstractbstree.h"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct TreeNode{
   T m_data;
   TreeNode* m_right;
   TreeNode* m_left;
};

template <typename T>
class MyBSTree : public AbstractBSTree<T>{
private:
   TreeNode<T>* m_root;
   int m_size;

   void prettyPrint (const TreeNode<T>* t, int pad) const{
      string s(pad, ' ');
      if (t == NULL)
         cout << endl;
      else{
         prettyPrint(t->m_right, pad+4);
         cout << s << t->m_data << endl;
         prettyPrint(t->m_left, pad+4);
      }  
   }

   void recursiveInsert(const T &x, TreeNode<T>* &t){
      if(t == NULL){
         t = new TreeNode<T>;
         t->m_data = x;
         t->m_right = NULL;
         t->m_left = NULL;
         m_size++;
      }
      else{
         if(x < t->m_data){
            recursiveInsert(x, t->m_left);
         }
         else if(x > t->m_data){
            recursiveInsert(x, t->m_right);
         }
         else{ //x == t->m_data
            return;
         }
      }
   }


   void recursiveRemove(const T &x, TreeNode<T>* &t){
      if(t == NULL)
         return;
      else if(x < t->m_data)
         recursiveRemove(x, t->m_left);
      else if(x > t->m_data)
         recursiveRemove(x, t->m_right);
      else if(t->m_left != NULL && t->m_right != NULL){
         t->m_data = recursiveFindMax(t->m_left);
         recursiveRemove(t->m_data, t->m_left);
      }
      else{
         TreeNode<T>* tmp = t;
         t = tmp->m_left;
         if(t == NULL)
            t = tmp->m_right;
         delete tmp;
      }
   }

   int recursiveHeight(const TreeNode<T>* t) const{
      if(t == NULL)
         return 0;

      int lefth = recursiveHeight(t->m_left);
      int righth = recursiveHeight(t->m_right);

      if(lefth > righth)
         return lefth + 1;
      else
         return righth + 1;
   }

   void recursiveDeepCopy(TreeNode<T>* c){
      this->insert(c->m_data);

      if(c->m_left != NULL)
           recursiveDeepCopy(c->m_left);
      if(c->m_right != NULL)
           recursiveDeepCopy(c->m_right);
   }

   const T& recursiveFindMax(const TreeNode<T>* t) const throw ( string ){
      if( t == NULL )
         throw(string("PANIC : Tree is Empty!!"));
      if( t->m_right == NULL )
         return t->m_data;
      return recursiveFindMax( t->m_right);
   }

   const T& recursiveFindMin(const TreeNode<T>* t) const throw ( string ){
      if( t == NULL )
         throw(string("PANIC : Tree is Empty!!"));
      if( t->m_left == NULL )
         return t->m_data;
      return recursiveFindMin( t->m_left);
   }

   void recursivePreOrder(const TreeNode<T>* t) const{
      if(t != NULL){
         cout << t->m_data << endl;
         recursivePreOrder(t->m_left);
         recursivePreOrder(t->m_right);
      }
   }

   void recursivePostOrder(const TreeNode<T>* t) const{
      if(t != NULL){
           recursivePostOrder(t->m_left);
           recursivePostOrder(t->m_right);
           cout << t->m_data << endl;
      }
   }

   void recursiveClear(TreeNode<T>* t) const{
      if(t != NULL){
        recursiveClear(t->m_left);
        recursiveClear(t->m_right);
        if(t->m_left != NULL)
            t->m_left = NULL;
        if(t->m_right!=NULL)
            t->m_right=NULL;
        delete t;
     }
   }

   int recursiveContains(const T &x, const TreeNode<T>* t, int level) const{
      if(t == NULL){
         return (level + 1) * -1;
      }
      else{
         if (x == t->m_data){
            return level;
         }
         else if (x < t->m_data)
            return recursiveContains(x, t->m_left, level + 1);
         else if (x > t->m_data)
            return recursiveContains(x, t->m_right, level + 1);
      }
      return (level + 1) * -1;
   }

public:
   MyBSTree(): m_size(0), m_root(NULL) {};


   MyBSTree(const MyBSTree<T>& cpy){
     m_root = NULL;
     *this = cpy;
   }

   MyBSTree<T>& operator=(const MyBSTree& rhs)
   {
       if(this != &rhs)
       {
           this->clear();
           TreeNode<T>* c = rhs.m_root;
           recursiveDeepCopy(c);
       }
       return *this;
   }

   virtual int size() const{
      return m_size;
   };

   virtual bool isEmpty() const{
      if(m_root == NULL) return true;
      else return false;
   };

   virtual int height() const{
      if(m_root == NULL) return 0;
      else return recursiveHeight(m_root);
   };

   virtual const T& findMax() const{
      return recursiveFindMax(m_root);
   };

   virtual const T& findMin() const throw ( string ){
      return recursiveFindMin(m_root);
   };

   virtual int contains(const T& x) const{
      return recursiveContains(x, m_root, 0);
   };

   virtual void clear(){
      recursiveClear(m_root);
      m_root = NULL;
      m_size = 0;
   };

   virtual void insert(const T& x){
      recursiveInsert(x, m_root);
   };

   virtual void remove(const T& x){
      recursiveRemove(x, m_root);
   };

   virtual void printPreOrder() const{
      recursivePreOrder(m_root);
   };

   virtual void printPostOrder() const{
      recursivePostOrder(m_root);
   };


   virtual void print() const{
      prettyPrint(m_root, 0);
   }

   ~MyBSTree(){this->clear();};
};
