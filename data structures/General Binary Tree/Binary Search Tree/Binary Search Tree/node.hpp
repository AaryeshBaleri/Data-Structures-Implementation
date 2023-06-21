#ifndef __NODE_HPP__
#define __NODE_HPP__

template <class T>
class Node {
	private:
		T _data;
		Node *_left;
		Node *_right;
		Node *_parent;

	public:
		Node(T d);
		Node(T d, Node *n1, Node * n2);
		T returnData() { return _data; }
		Node *returnLeft() { return _left; }
		Node *returnRight() { return _right; }
		Node *returnParent() { return _parent; }
		void setParent(Node<T> *n) { _parent = n; }
		void setLeft(Node<T> *n);
		void setRight(Node<T> *n);
		void setData(T data) { _data = data; }
};

#endif
