
#include "heap.hpp"

template <class T>
PriorityQueue<T>::PriorityQueue(T *a, int n) { 
	Heap<T>::_capacity = n; 
	Heap<T>::_heapsize = n;
	Heap<T>::_arr = new T[n];
	for(int i = 0; i < n; i++)Heap<T>::_arr[i] = a[i]; 
}

template <class T>
T PriorityQueue<T>::maximum() { return Heap<T>::_arr[0]; }

template <class T>
T PriorityQueue<T>::extractMax() {
	int max = Heap<T>::_arr[0];
	Heap<T>::swap(0, --Heap<T>::_heapsize);
	Heap<T>::maxHeapify(0);
	return max;
}

template <class T>
void PriorityQueue<T>::heapifyFromBottom(int i) {
	if(Heap<T>::_arr[Heap<T>::parent(i)] < Heap<T>::_arr[i] && Heap<T>::parent(i) >= 0){
		Heap<T>::swap(i, Heap<T>::parent(i));
		heapifyFromBottom(Heap<T>::parent(i));
	}
}

template <class T>
void PriorityQueue<T>::increaseKey(int i, int v) {
	Heap<T>::_arr[i] = v;
	heapifyFromBottom(i);
}

template <class T>
void PriorityQueue<T>::insert(T x) {
	Heap<T>::_arr[++Heap<T>::_heapsize - 1] = x;
	heapifyFromBottom(Heap<T>::_heapsize - 1);
}

template class PriorityQueue<int>;
