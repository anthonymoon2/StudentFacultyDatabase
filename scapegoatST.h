#ifndef SCAPEGOATST_H
#define SCAPEGOATST_H
#include "TreeNode.h"
#include <cmath>
#include <iostream>
using namespace std;

/*
a. scapeGoatST.h
b. none
c. class 
d. none 
*/

template <typename T>
class scapegoatST{
public:
  scapegoatST();
  virtual ~scapegoatST();
  int getSize();
  double calcSize(TreeNode<T>* newNode);
  void insert(T d);
  void remove(T d);
  bool contains(T d);
  void makeArrayInOrder();
  void printTree();
  T getMin();
  T getMax();
  T getMedian();

  bool isEmpty();
  void printOnePerson(int idHold);
  bool personExistCheck(int ID);
  T* copyPerson(int ID);

private:
  int m_size;
  int depth;
  int m; 
  TreeNode<T>* m_root;
  T getMinHelper(TreeNode<T>* subTreeRoot);
  T getMaxHelper(TreeNode<T>* subTreeRoot);
  int insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode);
  bool containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode);
  void makeArrayInOrderHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* inOrderArray);
  void printTreeHelper(TreeNode<T>* subTreeRoot);
  void findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent);
  TreeNode<T>* getSuccessor(TreeNode<T>* rightChild);
  TreeNode<T>* getParent(TreeNode<T>* newNode);
  void rebuildTree(TreeNode<T>* newNode);

  int storeInArray(TreeNode<T>* placer, TreeNode<T>* inOrderArray[], int i);
  TreeNode<T>* buildbalanced(TreeNode<T>** inOrderArray, int i, int n);
};
template <typename T>
scapegoatST<T>::scapegoatST(){
  m_root = NULL;
  m_size = 0;
  depth = 0;
}
template <typename T>
scapegoatST<T>::~scapegoatST(){
  if(m_root != NULL){
    delete m_root;
  }
}
template <typename T>
int scapegoatST<T>::getSize(){
  cout << m_size << endl;
  return m_size;
}

template <typename T>
double scapegoatST<T>::calcSize(TreeNode<T>* newNode){
  if (newNode == NULL)
    return 0;
  return calcSize(newNode->m_left) + calcSize(newNode->m_right) + 1;
}

template <typename T>
void scapegoatST<T>::insert(T d){
  depth = 0;
  TreeNode<T>* newNode = new TreeNode<T>(d);
  depth = insertHelper(m_root, newNode);
  
  ++m_size; // actual # of things in tree
  ++m; // everytime insert is called increment

  if (depth > 1.7*log(m)){
    // current node that is visited
    TreeNode<T>* p = getParent(newNode); // parent of newNode

    if(calcSize(p) / calcSize(newNode) <= 2/3){
      rebuildTree(p);
    }
  }
}
template <typename T>
int scapegoatST<T>::insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode){
  if(subTreeRoot == NULL){
    subTreeRoot = newNode;
    depth += 0;
  } else if(newNode->m_data < subTreeRoot->m_data){
    insertHelper(subTreeRoot->m_left,newNode);
    depth +=1;
  } else if(newNode->m_data > subTreeRoot->m_data){
    insertHelper(subTreeRoot->m_right,newNode);
    depth +=1;
  }
  return depth;
}

template <typename T>
void scapegoatST<T>::remove(T d){
  //check if empty
  TreeNode<T>* target = NULL;
  TreeNode<T>* parent = NULL;
  target = m_root;
  findTarget(d,target,parent);
  if(target == NULL){ //value wasn't in tree, nothing to do
    return;
  }
  //check if leaf (including the root)
  if(target->m_left == NULL && target->m_right == NULL){ //no children, it's a leaf
    if(target == m_root){ //leaf is the root of tree
      m_root = NULL;
    } else{ //it's not the root
      if(target ==  parent->m_left){
        parent->m_left = NULL;
      } else{
        parent->m_right = NULL;
      }
    }
    //delete target; //free the memory
  } else if(target->m_left != NULL && target->m_right != NULL){ //2 child case
    TreeNode<T>* suc = getSuccessor(target->m_right);
    T value = suc->m_data;
    remove(value); //remove successor treenode
    target->m_data = value;
  } else{ //1 child
    TreeNode<T>* child;
    if(target->m_left != NULL){
      child = target->m_left;
    } else{
      child = target->m_right;
    }
    if(target ==  m_root){
      m_root = child;
    } else{
      if(target == parent->m_left){
        parent->m_left = child;
      } else{
        parent->m_right = child;
      }
    }
      //delete target;
  }
  --m_size;
  if (m > 2*m_size && m_size > 0){
    rebuildTree(m_root);
    m = m_size;
  }
}

template<typename T> 
void scapegoatST<T>::rebuildTree(TreeNode<T>* newNode){
  int k = calcSize(newNode); 
  TreeNode<T>* p = newNode->m_parent;
  TreeNode<T>** inOrderArray = new TreeNode<T>*[k];
  storeInArray(newNode, inOrderArray, 0);

  if (p == NULL){
    m_root = buildbalanced(inOrderArray, 0, k);
    m_root->m_parent = NULL;
  }
  else if (p->m_right == newNode){
    p->m_right = buildbalanced(inOrderArray, 0, k);
    p->m_right->m_parent = p;
  }
  else {
    p->m_left = buildbalanced(inOrderArray, 0, k);
    p->m_left->m_parent = p;
  }
}

template<typename T> 
TreeNode<T>* scapegoatST<T>::buildbalanced(TreeNode<T>** inOrderArray, int i, int n){
  if (n==0){
    return NULL;
  }
  int m = n/2;
  inOrderArray[i+m]->m_left = buildbalanced(inOrderArray, i, m);

  if (inOrderArray[i+m]->m_left != NULL){
    inOrderArray[i+m]->m_left->m_parent = inOrderArray[i+m];
  }

  inOrderArray[i+m]->m_right = buildbalanced(inOrderArray, i+m+1, n-m-1);
  if (inOrderArray[i+m]->m_right != NULL){
    inOrderArray[i+m]->m_right->m_parent = inOrderArray[i+m];
  }
  return inOrderArray[i+m];
}


template<typename T> 
int scapegoatST<T>::storeInArray(TreeNode<T>* placer, TreeNode<T>* inOrderArray[], int i){
  if (placer == NULL){
    return i;
  }
  i = storeInArray(placer->m_left, inOrderArray, i);
  inOrderArray[i++] = placer;
  return storeInArray(placer->m_right, inOrderArray, i);
}

template<typename T> 
TreeNode<T>* scapegoatST<T>::getParent(TreeNode<T>* newNode){
  TreeNode<T>* current = m_root;
  TreeNode<T>* parent = NULL;

  while (current->m_data != newNode->m_data){ 
    if (newNode->m_data < current->m_data){
      parent = current;
      current = current->m_left;
    }
    else if (newNode->m_data > current->m_data){
      parent = current;
      current = current->m_right;
    }
  }
  return parent;
}

template <typename T>
bool scapegoatST<T>::contains(T d){
  TreeNode<T>* newNode = new TreeNode<T>(d);
  return containsHelper(m_root, newNode);
}
template <typename T>
bool scapegoatST<T>::containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode){
  if(subTreeRoot == NULL){
    return false;
  } else if(newNode->m_data == subTreeRoot->m_data){
    return true;
  } else if(newNode->m_data < subTreeRoot->m_data){
    return containsHelper(subTreeRoot->m_left,newNode);
  } else{
    return containsHelper(subTreeRoot->m_right,newNode);
  }
}

template <typename T>
void scapegoatST<T>::printTree(){
  printTreeHelper(m_root);
}
template <typename T>
void scapegoatST<T>::printTreeHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot == NULL){
    return;
  }
  cout << subTreeRoot->m_data << endl;
  printTreeHelper(subTreeRoot->m_left);
  printTreeHelper(subTreeRoot->m_right);
}

template <typename T>
T scapegoatST<T>::getMin(){
  //check if empty
  return getMinHelper(m_root);
}
template <typename T>
T scapegoatST<T>::getMinHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot->m_left==NULL){
    return subTreeRoot->m_data;
  } else{
    return getMinHelper(subTreeRoot->m_left);
  }
}
template <typename T>
T scapegoatST<T>::getMax(){
  //check if empty
  return getMaxHelper(m_root);
}
template <typename T>
T scapegoatST<T>::getMaxHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot->m_right==NULL){
    return subTreeRoot->m_data;
  } else{
    return getMaxHelper(subTreeRoot->m_right);
  }
}
template <typename T>
T scapegoatST<T>::getMedian(){
  //check if empty
  return m_root->m_data;
}
template <typename T>
void scapegoatST<T>::findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent){
  while(target != NULL && target->m_data != key){
    parent = target;
    if(key < target->m_data){
      target = target->m_left;
    } else{
      target = target->m_right;
    }
  }
}
template <typename T>
TreeNode<T>* scapegoatST<T>::getSuccessor(TreeNode<T>* rightChild){
  while(rightChild->m_left != NULL){
    rightChild = rightChild->m_left;
  }
  return rightChild;
}

template <typename T>
bool scapegoatST<T>::isEmpty(){
  return(m_root == NULL);
}

template <typename T>
void scapegoatST<T>::printOnePerson(int idHold){
  TreeNode<T> *current = m_root;
  
  if (m_root == NULL){
    return;
  }
  
  while(current->m_data.m_id != idHold){
    if (idHold < current->m_data.m_id){
      current = current->m_left;
    }
    else{
      current = current->m_right;
    }
    if (current == NULL){
      return;
    }
  }
  cout << current->m_data << endl;
  
}

template <class T>
bool scapegoatST<T>::personExistCheck(int ID){
    TreeNode<T> *current = m_root;
    if(m_root == NULL){
        return false;
    }
    while(current->m_data.m_id != ID){
        if(ID < current->m_data.m_id){
            current = current->m_left;
        }
        else{
            current = current->m_right;
        }
        if(current == NULL){
            return false;
        }
    }
    return true;
}

template <class T>
T* scapegoatST<T>::copyPerson(int ID){
    TreeNode<T> *current = m_root;

    if(m_root == NULL){
        return nullptr;
    }
    while(current->m_data.m_id != ID){
        if(ID < current->m_data.m_id){
            current = current->m_left;
        }
        else{
            current = current->m_right;
        }
        if(current == NULL){
            return nullptr;
        }
    }
    return &(current->m_data);
}

#endif