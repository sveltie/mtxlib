#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <vector>

template <typename T>
class Matrix {
    private:
        T** p;
        size_t rows, columns;
    public:
        // Type definition lowercase matrix for return type.
        typedef std::vector<std::vector<T>> matrix;

        // Constructor.
        Matrix() = default;
        Matrix(matrix m);

        // Void methods.
        void print();

        matrix ret();
        matrix transpose();
        matrix add(Matrix& mtx);
        matrix subtract(Matrix& mtx);
        matrix dothing(Matrix& mtx);
};

#endif