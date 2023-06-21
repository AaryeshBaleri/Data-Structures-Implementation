#ifndef __STACK_HPP__
#define __STACK_HPP__

#include "linked_list.hpp"

template <class T>
class Stack {
    private:
        LinkedList<T> _stack;

    public:
        Stack() { }
        bool isEmpty() { return _stack.size() == 0; }
        int size() { return _stack.size(); }
        T &top() { return _stack.tail(); }
        void push(const T &e) { _stack.append(e); }
        T pop() { return _stack.remove_last(); }
};

#endif