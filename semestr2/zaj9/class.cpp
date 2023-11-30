#include "matrix.hpp"
#include <cstdlib>
#include <cstring>

// konstruktory
Matrix::Matrix(int col, int row) : row_num(row) , col_num(col) {
        data = (double*)(std::malloc(row_num * col_num * sizeof(double)));

        std::memset(data, 0, row_num * col_num * sizeof(double));
};

Matrix::Matrix(const Matrix &m){

        row_num = m.row_num;
        col_num = m.col_num;

        data = (double*)(std::malloc(row_num * col_num * sizeof(double)));

        std::memcpy(data, m.data, row_num * col_num * sizeof(double));

};

Matrix& Matrix::operator=(Matrix const &m){
        row_num = m.row_num;
        col_num = m.col_num;

        data = (double*)(std::malloc(row_num * col_num * sizeof(double)));
        std::memcpy(data, m.data, row_num * col_num * sizeof(double));
        return *this;
};

 Matrix::~Matrix(){
        std::free(data);
        row_num=0;
        col_num=0;
};

double& Matrix::operator()(int r, int c){
            return data[r * col_num + c];
};
const double& Matrix::operator()(int r, int c) const{
            return data[r * col_num + c];
};
