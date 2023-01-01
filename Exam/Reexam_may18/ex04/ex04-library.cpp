#include "ex04-library.h"
#include <iostream>

using namespace std;

//Do not modify
template<class T>
mystack<T>::mystack() {
  size=0;
  top=nullptr;
}

//Do not modify
template<class T>
int mystack<T>::getSize() {
  return size;
}

//Do not modify
template<class T>
void mystack<T>::print() {
  if(size==0){
    cout << "The stack is empty.\n";
  }
  else{
    cout << "The stack has size " << size << ":\n";
    Node<T> * current = top;
    while(current!=nullptr){
      cout << "  " <<current->content << "\n";
      current = current->next;
    }
  }
}

//Exercise 4 (a) Check and correct if necessary
template<class T>
mystack<T>::~mystack() {
  Node<T> * current = top;
  while(current!=nullptr){
    Node<T> * next = current->next;
    delete current;  
    current = next;
  }
  cout << "Destructor completed\n";
}

//Exercise 4 (b) Implement this function
template<class T>
void mystack<T>::print_top() {
  //Put your code here
  if (size==0)
    cout << "The stack is empty." << endl;
  else
    cout << top->content;
}

//Exercise 4 (b) Implement this function
template<class T>
void mystack<T>::push(T v) {
  //Put your code here
  Node<T> *node = new Node<T>;
  node->content = v;
  node->next = top;
  top = node;
  size++;
}

//Exercise 4 (d) Implement this function
template<class T>
bool mystack<T>::pop() {
  //Put your code here
  if (top == nullptr)
    return false;
  else{
    Node<T> * node = top;
		top = top->next;
		delete node;
		size--;
		return true;
  }
}

//Do not modify
template class mystack<int>;