#include <iostream>
#include "heap.hpp"

using namespace std;

template <class T>
Heap<T>::Heap(T * arr, int a): _capacity(a), _heapsize(a) {
	_arr = new T[_capacity];
	for(int i = 0; i < _capacity; i++) _arr[i] = arr[i];
}

template <class T>
Heap<T>::Heap() { }

template <class T>
int Heap<T>::parent(int i) { return (i - 1) / 2; }

template <class T>
int Heap<T>::left(int i) { return (2 * i + 1); }

template <class T>
int Heap<T>::right(int i) { return (2 * i + 2); }

template <class T>
void Heap<T>::swap(int i, int j) {
	int temp = _arr[i];
	_arr[i] = _arr[j];
	_arr[j] = temp;
}

template <class T>
void Heap<T>::maxHeapify(int i) {
	int l = left(i), r = right(i), largest = 0;
	if(l < _heapsize && _arr[l] > _arr[i]) largest = l;
	else largest = i;
	if(r < _heapsize && _arr[r] > _arr[largest])largest = r;
	if(largest != i) {
		swap(i, largest);
		maxHeapify(largest);
	}
}

template <class T>
void Heap<T>::buildHeap() { for(int i = _heapsize/2 - 1; i >= 0; i--) maxHeapify(i); }

template <class T>
void Heap<T>::heapSort() {
	buildHeap();
	for(int i = _capacity - 1; i >= 1; i--) {
		swap(0, i);
		_heapsize--;
		maxHeapify(0);
	}
}

template <class T>
void Heap<T>::heapTest() {
	for(int i = _heapsize - 1; i >= 1; i--) 
		if(_arr[parent(i)] < _arr[i]) {
			cout << "Test failed" << endl;
			return;
		}
	cout << "Test successful" << endl;
}

template <class T>
void Heap<T>::sortTest() {
	for(int i = 0; i < _capacity - 1; i++)
		if(_arr[i] > _arr[i + 1]){
			cout << "Test failed" << endl;
			return;
		}
	cout << "Test successful" << endl;
}

template <class T>
void Heap<T>::printArr() { 
	for(int i = 0; i < _capacity; i++) cout << _arr[i] << " ";
	cout << endl;
}

template <class T>
void Heap<T>::printHeap() {
	for(int i = 0; i < _heapsize; i++) cout << _arr[i] << " ";
	cout << endl;
}

/*void fillArray(int *a, int n) { for(int i = 0; i < n; i++)a[i] = rand(); }

int main () {
	int n;
	cout << "Input array length" << endl;
	cin >> n;
	int *a = new int[n];
	fillArray(a, n);
	Heap<int> h(a, n);
	h.heapSort();
	h.sortTest();
}*/

template class Heap<int>;





