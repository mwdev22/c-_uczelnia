#include "class.cpp"
#ifndef matrix.hpp
#define matrix.hpp

class Matrix{
    private:
        int row_num;
        int col_num;
        double* data;

    public:
//      konstruktory
        Matrix() : row_num(0), col_num(0) {
            data = nullptr;
        };
        Matrix(int col, int row);
//      kopiujący
        Matrix(const Matrix &m);
//      destruktor
        ~Matrix();
        
        Matrix& operator=(Matrix const &m);

        double& operator()(int r, int c);

        const double& operator()(int r, int c) const;
};

#endif

