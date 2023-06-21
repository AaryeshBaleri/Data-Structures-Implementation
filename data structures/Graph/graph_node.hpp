#ifndef __GRAPH_NODE_HPP__
#define __GRAPH_NODE_HPP__

template <class T>
class GraphNode {
	public:
		int _d;
		int _f;
		T _data;
		char _color;
		int _distance;
		GraphNode<T> *_parent;
		GraphNode<T> *_next;
		GraphNode<T> *_prev;
		GraphNode(T d);	
		GraphNode();
		void printDetails();
};

#endif
