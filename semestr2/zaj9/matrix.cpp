#include <iostream>
#include "matrix.hpp"

int main() {
    Matrix mat1(2, 3);
    Matrix mat2;
    mat1(0, 0) = 7;
    mat2 = mat1;
    mat2(0, 1) = 8;
    Matrix mat3 = mat2;
    mat3(0, 2) = 9;
    std::cout << mat1(0, 0) << " " << mat1(0, 1) <<
    " " << mat1(0, 2) << std::endl;
    std::cout << mat2(0, 0) << " " << mat2(0, 1) <<
    " " << mat2(0, 2) << std::endl;
    std::cout << mat3(0, 0) << " " << mat3(0, 1) <<
    " " << mat3(0, 2) << std::endl;
    return 0;
}
