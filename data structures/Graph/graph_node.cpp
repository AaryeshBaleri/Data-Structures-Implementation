#include<iostream>
#include "graph_node.hpp"

using namespace std;

template <class T>
GraphNode<T>::GraphNode(T d) {
	_data = d;
	_color = 'w';
	_parent = NULL;
	_next = NULL;
	_prev = NULL;
	_distance = -1;
	_d = 0;
	_f = 0;
}

template <class T>
GraphNode<T>::GraphNode() {
	_data = 0;
	_color = 'w';
	_parent = NULL;
	_next = NULL;
	_prev = NULL;
	_distance = -1;
	_d = 0;
	_f = 0;
}

template <class T> 
void GraphNode<T>::printDetails() {
	cout << "data = " << _data << endl;
	cout << "color = " <<  _color << endl;
	if(_parent != NULL) cout << "parent = " <<  _parent->_data << endl;	
	else cout << "parent = NULL" << endl;
	cout << "distance = " <<  _distance << endl;
	cout << "discovery time = " << _d << endl;
	cout << "finish time = " << _f << endl;
}

template class GraphNode<int>;
