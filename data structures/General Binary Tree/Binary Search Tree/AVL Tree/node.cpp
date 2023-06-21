#include <iostream>
#include "node.hpp"

using namespace std;

template <class T>
void Node<T>::update(Node<T> *n) {
	if(n->returnLeft() != NULL)n->setHl(1 + n->returnLeft()->returnHeight());
	if(n->returnRight() != NULL)n->setHr(1 + n->returnRight()->returnHeight());
	n->setBf();
	if(n->returnParent() == NULL)return;
	update(n->returnParent());
}

template <class T>
Node<T>::Node(T d) {
	_data = d;
	_left = NULL;
	_right = NULL;
	_parent = NULL;
	_hl = 0;
	_hr = 0;
	_bf = _hl - _hr;
	if(returnParent() != NULL)update(returnParent());
}

template <class T>
Node<T>::Node(T d, Node *n1, Node *n2) {
	_data = d;
	_left = n1;
	_right = n2;
	_parent = NULL;
	if(n1 == NULL)_hl = 0;
	else _hl = 1 + n1->returnHeight();
	if(n2 == NULL)_hr = 0;
	else _hr = 1 + n2->returnHeight();
	_bf = _hl - _hr;
	if(n1 != NULL) n1->setParent(this);
	if(n2 != NULL) n2->setParent(this);
	if(returnParent() != NULL)update(returnParent());
}

template <class T>
void Node<T>::setLeft(Node<T> *n) { 
	_left = n; 
	if(n != NULL)n->setParent(this);
	if(n != NULL)_hl = 1 + n->returnHeight();
	else _hl = 0;
	_bf = _hl - _hr;
	if(returnParent() != NULL)update(returnParent());
}

template <class T>
void Node<T>::setRight(Node<T> *n) { 
	_right = n; 
	if(n != NULL)n->setParent(this);
	if(n != NULL)_hr = 1 + n->returnHeight();
	else _hr = 0;
	_bf = _hl - _hr;
	if(returnParent() != NULL)update(returnParent());
}

template <class T>
int Node<T>::returnHeight() {
	if(_hl > _hr) return _hl;
	return _hr;
}

template <class T>
void Node<T>::detach() {
	_hl = _hr = 0;
	_bf = 0;
	_left = NULL;
	_right = NULL;
	_parent = NULL;
}

template class Node<float>;
