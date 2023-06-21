#include <iostream>
#include "general_binary_tree.hpp"
#include "node.hpp"

using namespace std;

template <class T>
void AVLTree<T>::printDetails(Node<T> *root) {
	if(root == NULL) return;
	printDetails(root->returnLeft());
	cout << root->returnData() << ": " << root->returnBf() << endl;
	printDetails(root->returnRight());
	return;
}

template <class T>
Node<T> *AVLTree<T>::backprop(Node<T> *n) {
	if(n == NULL)return NULL;
	if(n->returnBf() >= 2 || n->returnBf() <= -2)return n;
	else backprop(n->returnParent());
}

template <class T>
void AVLTree<T>::LL(Node<T> *n) {
	Node<T> *parent = n->returnParent();
	Node<T> *child = n->returnRight();
	Node<T> *right = child->returnLeft();
	Node<T> *left = n->returnLeft();
	if(parent == NULL) {
		child->setParent(NULL);
		n->detach();
		child->setLeft(n);
		n->setLeft(left);
		n->setRight(right);
		GeneralBinaryTree<T>::_root = child;
	}

	else {
		if(n == parent->returnRight())parent->setRight(child);
		else parent->setLeft(child);
		n->detach();
		child->setLeft(n);
		n->setLeft(left);
		n->setRight(right);
	}
}

template <class T>
void AVLTree<T>::RR(Node<T> *n) {
	Node<T> *parent = n->returnParent();
	Node<T> *child = n->returnLeft();
	Node<T> *left = child->returnRight();
	Node<T> *right = n->returnRight();
	if(parent == NULL) {
		child->setParent(NULL);
		n->detach();
		child->setRight(n);
		n->setLeft(left);
		n->setRight(right);
		GeneralBinaryTree<T>::_root = child;
	}

	else {
		if(n == parent->returnLeft())parent->setLeft(child);
		else parent->setRight(child);
		n->detach();
		child->setRight(n);
		n->setLeft(left);
		n->setRight(right);
	}
}

template <class T>
void AVLTree<T>::LR(Node<T> *n) {
	LL(n->returnLeft());
	RR(n);
}

template <class T>
void AVLTree<T>::RL(Node<T> *n) {
	RR(n->returnRight());
	LL(n);
}

template <class T>
void AVLTree<T>::insert(T x, Node<T> *root) {
	BinarySearchTree<T>::insert(x, root);
	Node<T> *n = BinarySearchTree<T>::search(x, root);
	Node<T> *mistake = backprop(n);
	if(mistake == NULL) return;	
	if(mistake->returnBf() <= -2 && mistake->returnRight()->returnBf() <= 0) {
		LL(mistake);
		return;
	}
	if(mistake->returnBf() >= 2 && mistake->returnLeft()->returnBf() >= 0) {
		RR(mistake);
		return;
	}
	if(mistake->returnBf() >= 2 && mistake->returnLeft()->returnBf() <= -1) {
		LR(mistake);
		return;
	}
	if(mistake->returnBf() <= -2 && mistake->returnRight()->returnBf() >= 1) {
		RL(mistake);
		return;
	}
}

template <class T> 
void AVLTree<T>::del(T x) {
	Node<T> *key = BinarySearchTree<T>::del(x);
	Node<T> *mistake = backprop(key);
	if(mistake == NULL) return;	
	if(mistake->returnBf() <= -2 && mistake->returnRight()->returnBf() <= 0) {
		LL(mistake);
		return;
	}
	if(mistake->returnBf() >= 2 && mistake->returnLeft()->returnBf() >= 0) {
		RR(mistake);
		return;
	}
	if(mistake->returnBf() >= 2 && mistake->returnLeft()->returnBf() <=-1) {
		LR(mistake);
		return;
	}
	if(mistake->returnBf() <= -2 && mistake->returnRight()->returnBf() >= 1) {
		RL(mistake);
		return;
	}
}

template class Node<float>;
template class GeneralBinaryTree<float>;
template class BinarySearchTree<float>;
template class AVLTree<float>;
