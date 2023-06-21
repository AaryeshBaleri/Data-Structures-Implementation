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
void BinarySearchTree<T>::del(T x) {
	Node<T> *key = search(x, GeneralBinaryTree<T>::_root);
	Node<T> *parent = key->returnParent();
	if(key->returnLeft() == NULL & key->returnRight() == NULL) {
		if(key == parent->returnLeft())parent->setLeft(NULL);
		else parent->setRight(NULL);
		return;
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
		return;
	}

	Node<T> *maxLeft = findMax(key->returnLeft());
	T data = maxLeft->returnData();
	maxLeft->setData(key->returnData());
	key->setData(data);
	Node<T> *parent2 = maxLeft->returnParent();
	parent2->setRight(NULL);
}

int main() {
	Node<int> *n0 = new Node<int>(58);
	Node<int> *n1 = new Node<int>(64);
	Node<int> *n2 = new Node<int>(68);
	Node<int> *n3 = new Node<int>(80);
	Node<int> *n4 = new Node<int>(65, n1, n2);
	Node<int> *n5 = new Node<int>(70, n4, n3);
	Node<int> *root = new Node<int>(60, n0, n5);
	BinarySearchTree<int> tree(root);
	tree.sortedSequence();
	cout << endl;
	tree.insert(90, tree.returnRoot());
	tree.sortedSequence();
	cout << endl;
	tree.del(80);
	tree.sortedSequence();
	cout << endl;
	return 0;
	
}

template class Node<int>;
template class GeneralBinaryTree<int>;
template class BinarySearchTree<int>;
