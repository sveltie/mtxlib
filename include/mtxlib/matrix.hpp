#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <vector>
#include <stdexcept>

// Type definition lowercase matrix for return type.
template <typename T>
using matrix = std::vector<std::vector<T>>;

template <typename T>
class Matrix {
    private:
        T** p;
        size_t rows, columns;
    public:

        // Constructor.
        Matrix() = default;
        Matrix(matrix<T> m);

        // Void methods.
        void print();
        void printAddress();

        // matrix return type.
        matrix<T> ret();
        matrix<T> transpose();
        matrix<T> add(Matrix& m);
        matrix<T> subtract(Matrix& m);

        // some stuffs.
        template <typename U>
        std::vector<std::vector<U>> scalarMul(U s);
};

/**
 * Initialize a matrix.
 *
 * @tparam T The data type of the matrix
 * @param[in] arr 2D-Array of generic type
 */
template <typename T>
Matrix<T>::Matrix(std::vector<std::vector<T>> arr) {
    rows = arr.size();
    columns = arr[0].size();

    // Initialize the double pointer which is the matrix data.
    p = new T*[rows];
    for (size_t i = 0; i < rows; i++) {
        p[i] = new T[columns];
    }

    // Copy the content of the array to the matrix pointer.
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            p[i][j] = arr[i][j];
        }
    }
}

/**
 * Print out the matrix with nice square bracket formatting.
 *
 * @tparam T The data type of the matrix
 */
template <typename T>
void Matrix<T>::print() {
    // Iterate through the matrix.
    for (size_t i = 0; i < rows; i++) {
        std::cout << "[";
        for (size_t j = 0; j < columns; j++) {
            // Some ternary operator to print closing square bracket.
            std::cout << p[i][j] << ((j < columns - 1) ? ", " : "]");
        }
        std::cout << "\n";
    }
}

/**
 * Print out the matrix address.
 *
 * @tparam T The data type of the matrix
 */
template <typename T>
void Matrix<T>::printAddress() {
    std::cout << &p << std::endl;
    std::cout << typeid(&p).name() << std::endl;
}

/**
 * Return the value of a Matrix class.
 *
 * @tparam T The data type of the matrix
 * @return matrix
 */
template <typename T>
matrix<T> Matrix<T>::ret() {
    matrix<T> res(rows, std::vector<T>(columns, 0));
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            res[i][j] = p[i][j];
        }
    }
    return res;
}

/**
 * Transpose the matrix, it flips a matrix over its diagonal.
 *
 * @tparam T The data type of the matrix
 * @return matrix transpose
 */
template <typename T>
matrix<T> Matrix<T>::transpose() {
    // Declare a zero matrix, matrix is flipped diagonally.
    matrix<T> res(columns, std::vector<T>(rows, 0));

    // Flip the matrix, iterate through each value and store it to a temporary matrix.
    for (size_t i = 0; i < columns; i++) {
        for (size_t j = 0; j < rows; j++) {
            res[i][j] = p[j][i];
        }
    }
    return res;
}

/**
 * Scalar multiplication with a matrix, scalar is basically a fancy way of saying a number.
 *
 * @tparam T The data type of the matrix
 * @return matrix multiplied by a scalar
 */
template<typename T>
template<typename U>
std::vector<std::vector<U>> Matrix<T>::scalarMul(U scalar) {
    std::vector<std::vector<U>> res(rows, std::vector<U>(columns, 0));
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            res[i][j] += (U) p[i][j] * scalar;
        }
    }
    return res;
}


/**
 * Matrix addition.
 * @TODO: Accept 2D-Array as the parameter
 *
 * @tparam T The data type of the matrix
 * @param  m Class object
 * @return matrix
 */
template <typename T>
matrix<T> Matrix<T>::add(Matrix& m) {
    matrix<T> temp(rows, std::vector<T>(columns, 0)); // store m.
    matrix<T> res(rows, std::vector<T>(columns, 0));
    temp = m.ret();
    size_t mRows = temp.size();
    size_t mColumns = temp[0].size();
    if (mRows != rows || mColumns != columns) {
        throw std::invalid_argument("INVALID: Matrix is not the same size.");
    } else {
         for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < columns; j++) {
                res[i][j] += p[i][j] + temp[i][j];
            }
        }
    }
    return res;
}

/**
 * Matrix subtraction.
 * @TODO: Accept 2D-Array as the parameter
 *
 * @tparam T The data type of the matrix
 * @param  m Class object
 * @return matrix
 */
template <typename T>
matrix<T> Matrix<T>::subtract(Matrix& m) {
    matrix<T> temp(rows, std::vector<T>(columns, 0)); // store m.
    matrix<T> res(rows, std::vector<T>(columns, 0)); 
    temp = m.ret();
    size_t mRows = temp.size();
    size_t mColumns = temp[0].size();
    if (mRows != rows || mColumns != columns) {
        throw std::invalid_argument("INVALID: Matrix is not the same size.");
    } else {
         for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < columns; j++) {
                res[i][j] += p[i][j] - temp[i][j];
            }
        }
    }
    return res;
}

#endif