#ifndef __NODE_HPP__
#define __NODE_HPP__

template <class T>
class Node {
	private:
		T _data;
		int _hl;
		int _hr;
		int _bf;
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
		int returnBf() { return _bf; }
		void setParent(Node<T> *n) { _parent = n; }
		void setLeft(Node<T> *n);
		void setRight(Node<T> *n);
		void setData(T data) { _data = data; }
		void setHl(int x) { _hl = x; }
		void setHr(int x) { _hr = x; }
		void setBf() { _bf = _hl - _hr; }
		int returnHeight();
		void update(Node<T> *n);
		void detach();

};

#endif
