#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

template <class T>
class Graph {
	private:
		int _n;
		int _time;
		GraphNode<T> *_adj_list;
		void createAdjList();
		void insertAtEnd(int i, T j);
		void DFSVisit(GraphNode<T> *u);

	public:
		Graph(int n);
		void printGraph();
		void printGraphDetails();
		void BFS();
		void DFS();

};

#endif
