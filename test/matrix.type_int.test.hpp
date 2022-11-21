#ifndef __MATRIX_TYPE_INT_TEST_H__
#define __MATRIX_TYPE_INT_TEST_H__

#include <iostream>
#include "../include/mtxlib/matrix.hpp"

void matrix_type_int_test() {
    /**
    * Testing int matrix
    */
    std::cout << "Matrix<int>" << std::endl;
    Matrix<int> m{{{1, 2, 3}, {4, 5, 6}}};
    Matrix<int> n{{{9, 8, 7}, {6, 5, 4}}};
    m.printAddress();
    m.print();

    std::cout << "\nTranspose Matrix<int>" << std::endl;
    Matrix<int> mt{m.transpose()};
    mt.printAddress();
    mt.print();

    std::cout << "\nScalar Multiplication Matrix<int>" << std::endl;
    Matrix<int> ms{m.scalarMul(2)};
    ms.printAddress();
    ms.print();

    std::cout << "\nMatrix addition<int>" << std::endl;
    Matrix<int> madd(m.add(m));
    madd.printAddress();
    madd.print();

    std::cout << "\nMatrix subtraction<int>" << std::endl;
    Matrix<int> msub(m.subtract(n));
    msub.printAddress();
    msub.print();
}

#endif