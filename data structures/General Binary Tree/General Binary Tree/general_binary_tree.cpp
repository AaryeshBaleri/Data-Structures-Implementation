#include <iostream>
#include "general_binary_tree.hpp"
#include "node.hpp"

using namespace std;

template <class T>
void GeneralBinaryTree<T>::preorder(Node<T> *n) {
	if(n == NULL) return;
	cout << n->returnData();
	preorder(n->returnLeft());
	preorder(n->returnRight());
}

template <class T>
void GeneralBinaryTree<T>::inorder(Node<T> *n) {
	if(n == NULL) return;
	inorder(n->returnLeft());
	cout << n->returnData();
	inorder(n->returnRight());
}

template <class T>
void GeneralBinaryTree<T>::postorder(Node<T> *n) {
	if(n == NULL) return;
	postorder(n->returnLeft());
	postorder(n->returnRight());
	cout << n->returnData();
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

int main() {
	/*Node<char> *n1 = new Node<char>('d');
	Node<char> *n2 = new Node<char>('g');
	Node<char> *n3 = new Node<char>('h');
	Node<char> *n4 = new Node<char>('e', n2, NULL);
	Node<char> *n5 = new Node<char>('f', NULL, n3);
	Node<char> *n6 = new Node<char>('b', n1, n4);
	Node<char> *n7 = new Node<char>('c', NULL, n5);
	Node<char> *n8 = new Node<char>('a', n6, n7);*/

	GeneralBinaryTree<char> tree(NULL);

	int n;
	
	cout << "Input number of elements in sequence" << endl;
	cin >> n;

	char *pre = new char[n]; 
	char *in = new char[n];
	
	cout << "Input preorder sequence" << endl;
	for(int i = 0; i < n; i++) cin >> pre[i];
	cout << "Input inorder sequence" << endl;
	for(int i = 0; i < n; i++) cin >> in[i];
 
	tree.setRoot(tree.constructTree(pre, 0, n - 1, in, 0, n - 1));

	tree.preorder(tree.returnRoot());
	cout << endl;
	tree.inorder(tree.returnRoot());
	cout << endl;
	tree.postorder(tree.returnRoot());
	cout << endl;

	return 0;
}

template class Node<char>;
template class GeneralBinaryTree<char>;
