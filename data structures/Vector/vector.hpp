template<class T>
class Vector{
    private:
        T *arr;
        int currsize;
        int capacity;
    public:
        Vector(int n = 1){
            arr = new T[n];
            currsize = 0;
            capacity = n;
        }

        ~Vector(){delete[] arr;}

        T & operator[](int index){
            if(index < currsize){
                currsize++;
                return arr[index];
            }
            if(index > currsize){
                cout << "Error";
                exit(1);
            }
            if(currsize == capacity){
                T *narr = new T[2 * capacity];
                for(int i = 0; i < capacity; i++)narr[i] = arr[i];
                delete[] arr;
                arr = narr;
                capacity *= 2;
            }
            currsize++;
            return arr[index];
        }

        void print(){for(int i = 0; i < currsize; i++)cout << arr[i] << " ";}

        int return_currsize(){return currsize;}

        int del(int index){
            int key = arr[index];
            for(int i = index; i < currsize - 1; i++)arr[i] = arr[i + 1];
            currsize--;
            if(currsize < capacity / 4){
                T *narr = new T[capacity / 2];
                for(int i = 0; i < currsize; i++)narr[i] = arr[i];
                delete[] arr;
                arr = narr;
                capacity /= 2;
            }
            return key;
        }
};