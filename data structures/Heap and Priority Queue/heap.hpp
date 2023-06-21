#ifndef __HEAP_HPP__
#define __HEAD_HPP__

using namespace std;

template <class T>
class Heap {
	private:
		
		int left(int i);
		int right(int i);
		
	protected:
		T *_arr;
		int _capacity; 
		int _heapsize;
		
		int parent(int i);
		void swap(int i, int j);
		void maxHeapify(int i);

	public:
		Heap(T * arr, int a);
		Heap();
		void buildHeap();
	  	void heapSort();
		void heapTest();
		void sortTest();
		void printArr();
		void printHeap();
		
};

template<class T>
class PriorityQueue: public Heap<T> {
	private:
		void increaseKey(int i, int v);
		void heapifyFromBottom(int i);
		
	public:
		PriorityQueue(T *a, int n);
		T maximum();
		T extractMax();
		void insert(T x);
		
};

#endif
