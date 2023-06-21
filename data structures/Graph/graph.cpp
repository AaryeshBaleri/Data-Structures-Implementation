#include<iostream>
#include "graph_node.hpp"
#include "graph.hpp"
#include "queue.hpp"

using namespace std;

template <class T>
Graph<T>::Graph(int n) {
	_n = n;
	_adj_list = new GraphNode<T>[_n];
	for(int i = 0; i < _n; i++) 
		_adj_list[i]._data = (T) i;
	_time = 0;
	createAdjList();
}

template <class T>
void Graph<T>::insertAtEnd(int i, T j) {
	GraphNode<T> *curr = &_adj_list[i];
	while(curr->_next != NULL)curr = curr->_next;
	GraphNode<T> *t = new GraphNode<T>(j);
	curr->_next = t;
	t->_prev = curr;
	
}

template <class T> 
void Graph<T>::createAdjList() {
	for(int i = 0; i < _n; i++) {
		GraphNode<T> *curr = &_adj_list[i];
		for(int j = i + 1; j < _n; j++)
			if(rand() % 2 == 1){
				insertAtEnd(i, (T) j);
				insertAtEnd(j, (T) i);
			}
	}
}

template <class T>
void Graph<T>::printGraph() {
	for(int i = 0; i < _n; i++) {
		GraphNode<T> *curr = _adj_list[i]._next;
		while(curr != NULL){ 
			cout << "(" << _adj_list[i]._data << "," << curr->_data << ")" << " ";
			curr = curr->_next;
		}
		cout << endl;
	}
}

template <class T>
void Graph<T>::BFS() {
	for(int i = 0; i < _n; i++) {
		_adj_list[i]._color = 'w';
		_adj_list[i]._distance = -1;
		_adj_list[i]._parent = NULL;
	}
	GraphNode<T> *s = &_adj_list[0];
	s->_color = 'g';
	s->_distance = 0;
	s->_parent = NULL;
	//if(s->_data == d) return s;
	Queue<GraphNode<T> *> Q(_n); 
	Q.enqueue(s);
	while(!Q.isEmpty()) {
		GraphNode<T> *u = Q.dequeue();
		GraphNode<T> *v = u->_next;
		while(v != NULL) {
			if(_adj_list[(int) v->_data]._color == 'w') {
				_adj_list[(int) v->_data]._color = 'g';
				_adj_list[(int) v->_data]._distance = 1 + _adj_list[(int) u->_data]._distance;
				_adj_list[(int) v->_data]._parent = &_adj_list[(int) u->_data];
				//if(d == v->_data) return &_adj_list[(int) v->_data];
				GraphNode<T> *curr = &_adj_list[(int) v->_data];
				Q.enqueue(curr);
			}
			v = v->_next;

		}
		_adj_list[(int) u->_data]._color = 'b';
	}
	//return NULL;
}

template <class T>
void Graph<T>::DFSVisit(GraphNode<T> *u) {
	_time++;
	u->_d = _time;
	u->_color = 'g';
	GraphNode<T> *v = u->_next;
	while(v != NULL) {
		if(_adj_list[(int) v->_data]._color == 'w') {
			_adj_list[(int) v->_data]._parent = u;
			GraphNode<T> *curr = &_adj_list[(int) v->_data];
			DFSVisit(curr);
		}
		u->_color = 'b';
		_time++;
		u->_f = _time;
		v = v->_next;
	}
}

template <class T>
void Graph<T>::DFS() {
	for(int i = 0; i < _n; i++) {
		_adj_list[i]._color = 'w';
		_adj_list[i]._parent = NULL;
		_adj_list[i]._distance = 0;
	}
	_time = 0;
	for(int i = 0; i < _n; i++){
		GraphNode<T> *u = &_adj_list[i];
		if(u->_color == 'w') DFSVisit(u);

	}
}

template <class T>
void Graph<T>::printGraphDetails() {
	for(int i = 0; i < _n; i++) {
		GraphNode<T> *curr = &_adj_list[i];
		curr->printDetails();
		cout << endl;
	}
}

int main() {
	Graph<int> g(4);
	g.printGraph();
	cout << endl;
	g.BFS();
	g.printGraphDetails();
}

template class GraphNode<int>;
template class Graph<int>;
template class Queue<GraphNode<int> *>;
