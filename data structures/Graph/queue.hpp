#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__
#include<iostream>
using namespace std;

template <class T>
class Queue{
    private:
        T *_queue;
        int _front;
        int _rear;
        int _capacity;
        int _numofelements;

    public:
        Queue(int & cap){
            _queue = new T[cap];
            _front = 0;
            _rear = 0;
            _capacity = cap;
            _numofelements = 0;
        }

        ~Queue(){delete[] _queue;}

        bool isEmpty(){return _front == _rear;}

        bool isFull(){return (_rear + 1) % _capacity == _front;}

        void changeSize(bool increase){
            if(increase){
                T *nqueue = new T[2 * _capacity];
                int nrear = 0, curr = _front;
                _front = 0;
                while(curr != _rear){
                    nqueue[nrear++] = _queue[curr];
                    curr = curr + 1;
                }
                delete[] _queue;
                _queue = nqueue;
                _rear = nrear;
                _capacity *= 2;
            }
            else{
                T *nqueue = new T[_capacity / 2];
                int nrear = 0, curr = _front;
                _front = 0;
                while(curr != _rear){
                    nqueue[nrear++] = _queue[curr];
                    curr = (curr + 1) % _capacity;
                }
                delete[] _queue;
                _queue = nqueue;
                _rear = nrear;
                _capacity /= 2;
            } 
        }

        void enqueue(T & data){
            if(isFull()){
                changeSize(true);
                _queue[_rear++] = data;
                _numofelements++;
            }
            else {
                _queue[_rear++] = data;
                _numofelements++;
            }
            if(_numofelements < _capacity / 4)changeSize(false);
        }

        T dequeue(){
            if(isEmpty()){
                cout << "Error: Queue is empty";
                exit(1);
            }
	    T r = _queue[_front];
            _front++;
            _numofelements--;
            if(_numofelements < _capacity / 4)changeSize(false);
	    return r;
        }

        void print(){
            for(int i = _front; i < _rear; i = (i + 1) % _capacity)cout << _queue[i] << " ";
            cout << endl;
        }

        int capacity(){return _capacity;}

        friend ostream& operator <<(ostream& os, Queue q){q.print();}
};

#endif
