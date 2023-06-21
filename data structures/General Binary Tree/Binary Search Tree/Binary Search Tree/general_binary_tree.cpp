#include <iostream>
#include "general_binary_tree.hpp"
#include "node.hpp"

using namespace std;

template <class T>
void GeneralBinaryTree<T>::preorder(Node<T> *n) {
	if(n == NULL) return;
	cout << n->returnData() << " ";
	preorder(n->returnLeft());
	preorder(n->returnRight());
}

template <class T>
void GeneralBinaryTree<T>::inorder(Node<T> *n) {
	if(n == NULL) return;
	inorder(n->returnLeft());
	cout << n->returnData() << " ";
	inorder(n->returnRight());
}

template <class T>
void GeneralBinaryTree<T>::postorder(Node<T> *n) {
	if(n == NULL) return;
	postorder(n->returnLeft());
	postorder(n->returnRight());
	cout << n->returnData() << " ";
}

template <class T>
int GeneralBinaryTree<T>::search(T a[], int begin, int end, T v) {
	for(int i = begin; i <= end; i++)
		if(a[i] == v) return i;
}

template <class T>
Node<T> *GeneralBinaryTree<T>::constructTree(T pre[], int pstart, int pend, T in[], int istart, int iend) {
	if(istart > iend) return NULL;
	if(istart == iend) return new Node<T>(pre[pstart]);
	Node<T> *root = new Node<T>(pre[pstart]);
	int index = search(in, istart, iend, pre[pstart]);
	pstart++;
	root->setLeft(constructTree(pre, pstart, pend, in, istart, index - 1));
	pstart += index - istart;
	root->setRight(constructTree(pre, pstart, pend, in, index + 1, iend));
	return root;
	
}

template class Node<int>;
template class GeneralBinaryTree<int>;
