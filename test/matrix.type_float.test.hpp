#ifndef __MATRIX_TYPE_FLOAT_TEST_H__
#define __MATRIX_TYPE_FLOAT_TEST_H__

#include <iostream>
#include "../include/mtxlib/matrix.hpp"

void matrix_type_float_test() {
    /**
    * Testing float matrix
    */
    std::cout << "\nMatrix<float>" << std::endl;
    Matrix<float> mf{{{0.1, 0.2, 0.3}, {0.4, 0.5, 0.6}}};
    Matrix<float> nf{{{0.9, 0.8, 0.7}, {0.6, 0.5, 0.4}}};
    mf.printAddress();
    mf.print();

    std::cout << "\nTranspose Matrix<float>" << std::endl;
    Matrix<float> mtf{mf.transpose()};
    mtf.printAddress();
    mtf.print();

    std::cout << "\nScalar Multiplication Matrix<int>" << std::endl;
    Matrix<double> mfs{mf.scalarMul(2.1)};
    mfs.printAddress();
    mfs.print();

    std::cout << "\nMatrix addition<float>" << std::endl;
    Matrix<float> mfadd(mf.add(mf));
    mfadd.printAddress();
    mfadd.print();

    std::cout << "\nMatrix subtraction<float>" << std::endl;
    Matrix<float> nfsub(mf.subtract(nf));
    nfsub.printAddress();
    nfsub.print();
}

#endif