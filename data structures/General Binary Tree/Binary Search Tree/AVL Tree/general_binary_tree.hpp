#ifndef __GENERAL_BINARY_TREE_HPP__
#define __GENERAL_BINARY_TREE_HPP__
#include "node.hpp"

template <class T>
class GeneralBinaryTree {
	private:
		int search(T a[], int begin, int end, T v);

	protected:
		Node<T> *_root;
		Node<T> *returnRoot() { return _root; }
	
	public:
		GeneralBinaryTree(Node<T> *n): _root(n) { }
		void preorder(Node<T> *n);
		void inorder(Node<T> *n);
		void postorder(Node<T> *n);
		Node<T> *constructTree(T pre[], int pstart, int pend, T in[], int istart, int iend);
		void setRoot(Node<T> *n) { _root = n; }
};

template <class T>
class BinarySearchTree: public GeneralBinaryTree<T> {

	private:
		Node<T> *findMax(Node<T> *root);
	
	public:
		BinarySearchTree(Node<T> *n): GeneralBinaryTree<T>::GeneralBinaryTree(n) { }
		Node<T> *search(T x, Node<T> *root);
		void insert(T x, Node<T> *root);
		void sortedSequence() { GeneralBinaryTree<T>::inorder(GeneralBinaryTree<T>::_root); }
		Node<T> *returnRoot() { GeneralBinaryTree<T>::returnRoot(); }
		Node<T> *del(T x);
		
};

template <class T>
class AVLTree: public BinarySearchTree<T> {
	private:
		void LL(Node<T> *n);
		void RL(Node<T> *n);
		void LR(Node<T> *n);
		void RR(Node<T> *n);
		Node<T> *backprop(Node<T> *n);
	
	public:
		AVLTree(Node<T> *n): BinarySearchTree<T>::BinarySearchTree(n) { }
		void preorder(Node<T> *n) { GeneralBinaryTree<T>::preorder(n); }
		void insert(T x, Node<T> *root);
		void printDetails(Node<T> *root);
		Node<T> *returnRoot() { GeneralBinaryTree<T>::returnRoot(); }
		void del(T x);

};

#endif
