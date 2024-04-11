#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <cstdlib>
#include <iostream>
using namespace std;

/*
a. TreeNode.h
b. none
c. class 
d. none 
*/

template <typename T>
class TreeNode{
public:
  TreeNode(T d);
  virtual ~TreeNode();
  T getData();

  template <typename S>
  friend class scapegoatST;

private:
  T m_data;
  TreeNode<T>* m_left;
  TreeNode<T>* m_right;
  TreeNode<T>* m_parent;
};

template <typename T>
TreeNode<T>::TreeNode(T d){
  m_data = d;
  m_left = NULL;
  m_right = NULL;
  m_parent = NULL;
}

template <typename T>
TreeNode<T>::~TreeNode(){
  if(m_left != NULL){
    delete m_left;
  }
  if(m_right != NULL){
    delete m_right;
  }
  if(m_parent != NULL){
    delete m_parent;
  }
}

template <typename T>
T TreeNode<T>::getData(){
  return m_data;
}

#endif
