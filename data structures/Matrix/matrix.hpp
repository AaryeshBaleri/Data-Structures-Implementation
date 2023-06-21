template <class T>
class Matrix{
    private:
        T **_matrix;
        int _rows;
        int _cols;

    public:
        Matrix(int rows, int cols){
            _matrix = new T *[rows];
            for(int i = 0; i < rows; i++)_matrix[i] = new T[cols];
            _rows = rows;
            _cols = cols;
        }

        ~Matrix(){
            for(int i = 1; i <= _rows; i++)
                delete[] _matrix[i - 1];
        }

        T * & operator[](int index){return _matrix[index];}

        void print(){
            for(int i = 0; i < _rows; i++){
                for(int j = 0; j < _cols; j++)cout << _matrix[i][j] << " ";
                cout << endl;
            }
        }

        friend ostream& operator <<(ostream& os, Matrix m){m.print();}
};
