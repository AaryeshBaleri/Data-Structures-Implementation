#ifndef __GENERAL_BINARY_TREE_HPP__
#define __GENERAL_BINARY_TREE_HPP__
#include "node.hpp"

template <class T>
class GeneralBinaryTree {
	private:
		Node<T> *_root;
		int search(T a[], int begin, int end, T v);
	
	public:
		GeneralBinaryTree(Node<T> *n): _root(n) { }
		Node<T> *returnRoot() { return _root; }
		void preorder(Node<T> *n);
		void inorder(Node<T> *n);
		void postorder(Node<T> *n);
		Node<T> *constructTree(T pre[], int pstart, int pend, T in[], int istart, int iend);
		void setRoot(Node<T> *n) { _root = n; }
};

#endif
