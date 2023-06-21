#include<iostream>
#include "general_binary_tree.hpp"
#include "node.hpp"

using namespace std;

template <class T>
Node<T> *BinarySearchTree<T>::search(T x, Node<T> *root) {
	if(root->returnData() == x) return root;
	if(root->returnData() > x) return search(x, root->returnLeft());
	if(root->returnData() < x) return search(x, root->returnRight());
	return NULL;
}

template <class T>
void BinarySearchTree<T>::insert(T x, Node<T> *root) {
	if(root->returnData() > x) {
		if(root->returnLeft() == NULL) {
			root-> setLeft(new Node<T>(x));
			return;
		}
		insert(x, root->returnLeft());
	}
	if(root->returnData() < x) {
		if(root->returnRight() == NULL) {
			root-> setRight(new Node<T>(x));
			return;
		}
		insert(x, root->returnRight());
	}
}

template <class T>
Node<T> *BinarySearchTree<T>::findMax(Node<T> *root) {
	if(root->returnRight() == NULL)return root;
	findMax(root->returnRight());
}

template <class T>
Node<T> *BinarySearchTree<T>::del(T x) {
	Node<T> *key = search(x, GeneralBinaryTree<T>::_root);
	Node<T> *parent = key->returnParent();
	if(key->returnLeft() == NULL && key->returnRight() == NULL) {
		if(key == parent->returnLeft())parent->setLeft(NULL);
		else parent->setRight(NULL);
		return key;
	}

	if(key->returnLeft() == NULL || key->returnRight() == NULL) {
		if(key->returnRight() != NULL) {
			T data = key->returnRight()->returnData();
			key->setData(data);
			key->setRight(NULL);
		}
		if(key->returnLeft() != NULL) {
			T data = key->returnLeft()->returnData();
			key->setData(data);
			key->setLeft(NULL);
		}
		return key;
	}

	Node<T> *maxLeft = findMax(key->returnLeft());
	T data = maxLeft->returnData();
	maxLeft->setData(key->returnData());
	key->setData(data);
	Node<T> *parent2 = maxLeft->returnParent();
	parent2->setRight(NULL);
	return key;
}

template class Node<float>;
template class GeneralBinaryTree<float>;
template class BinarySearchTree<float>;
