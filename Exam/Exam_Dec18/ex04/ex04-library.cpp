#include "ex04-library.h"
#include <iostream>

using namespace std;

//Do not modify
template<class T>
void Node<T>::printNode(){
	cout << "Name: " << name << ", value: " << value ;
	cout << ", children: " << children.size() << endl;
}

//Exercise 4 (a) Check and correct if necessary
template<class T>
Node<T>::Node(string name, T value){
	this->name = name;
	this->value = value;
}

//Exercise 4 (b) Implement getName, getValue, and addChild
template<class T>
string Node<T>::getName(){
	//put your code here
	return this->name;
}

template<class T>
T Node<T>::getValue(){
	//put your code here
	return this->value;
}

template<class T>
void Node<T>::addChild(Node<T> * child){
	//put your code here
	children.push_back(child);
}

//Exercise 4 (c) Implement this method
template<class T>
void Node<T>::printLeafNodes(){
	//put your code here
	if(children.size() <= 0)
		cout << this->name << ' ' << this->value << ' ';
	for(int i=0; i<children.size();i++)
		children[i]->printLeafNodes();
}

//Exercise 4 (d) Implement this method
template<class T>
int Node<T>::countMembersOfSubTree(){
	//put your code here
	int counter = 1;
	for(int i = 0; i<children.size();i++)
		counter += children[i]->countMembersOfSubTree();
	return counter;
}

//Do not modify
template class Node<string>;