template<class T>
class Stack{
    private:
        Vector<T> v;
        int top;
    public:
        Stack(){top = -1;}

        T pop(){return v[top--];}

        void push(T a){v[++top] = a;}

        void printStack(){for(int i = 0; i <= top; i++)cout << v[i] << " ";}

        T return_top(){return v[top];}

        int stack_capacity(){return top + 1;}
};