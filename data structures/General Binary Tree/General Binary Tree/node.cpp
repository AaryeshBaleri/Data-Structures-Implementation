#include <iostream>
#include "node.hpp"

using namespace std;

template <class T>
Node<T>::Node(T d) {
	_data = d;
	_left = NULL;
	_right = NULL;
	_parent = NULL;
}

template <class T>
Node<T>::Node(T d, Node *n1, Node *n2) {
	_data = d;
	_left = n1;
	_right = n2;
	_parent = NULL;
	if(n1 != NULL) n1->setParent(this);
	if(n2 != NULL) n2->setParent(this);
}

template class Node<char>;
