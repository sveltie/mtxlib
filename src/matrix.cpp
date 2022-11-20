/**
 * matrix.cpp
 * compile with: g++ -O2 -Wall matrix.cpp -o matrix
*/
#include <iostream>
#include <vector>
#include "../include/mtxlib/matrix.hpp"

template <typename T>
using matrix = std::vector<std::vector<T>>;

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
 * Return the value of a Matrix class.
 *
 * @tparam T The data type of the matrix
 * @return matrix
 */
template <typename T>
matrix<T> Matrix<T>::ret() {
    std::vector<std::vector<T>> res(rows, std::vector<T>(columns, 0));

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
    std::vector<std::vector<T>> res(columns, std::vector<T>(rows, 0));

    // Flip the matrix, iterate through each value and store it to a temporary matrix.
    for (size_t i = 0; i < columns; i++) {
        for (size_t j = 0; j < rows; j++) {
            res[i][j] = p[j][i];
        }
    }
    return res;
}

/**
 * Matrix addition.
 * @TODO: Accept 2D-Array as the parameter
 *
 * @tparam T The data type of the matrix
 * @param  mtx Class object
 * @return matrix
 */
template <typename T>
matrix<T> Matrix<T>::add(Matrix& mtx) {
    std::vector<std::vector<T>> temp(rows, std::vector<T>(columns, 0));
    std::vector<std::vector<T>> res(rows, std::vector<T>(columns, 0));

    temp = mtx.ret();
    size_t mtxRows = temp.size();
    size_t mtxColumns = temp[0].size();

    if (mtxRows != rows || mtxColumns != columns) {
        std::cout << "INVALID: Matrix is not the same size." << std::endl;
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
 * @param  mtx Class object
 * @return matrix
 */
template <typename T>
matrix<T> Matrix<T>::subtract(Matrix& mtx) {
    std::vector<std::vector<T>> temp(rows, std::vector<T>(columns, 0));
    std::vector<std::vector<T>> res(rows, std::vector<T>(columns, 0));

    temp = mtx.ret();
    size_t mtxRows = temp.size();
    size_t mtxColumns = temp[0].size();

    if (mtxRows != rows || mtxColumns != columns) {
        std::cout << "INVALID: Matrix is not the same size." << std::endl;
    } else {
         for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < columns; j++) {
                res[i][j] += p[i][j] - temp[i][j];
            }
        }
    }
    return res;
}

int main() {
    /**
    * Testing int matrix
    */
    std::cout << "Matrix<int>" << std::endl;
    Matrix<int> m{{{1, 2, 3}, {4, 5, 6}}};
    Matrix<int> n{{{9, 8, 7}, {6, 5, 4}}};
    m.print();

    std::cout << "\nTranspose Matrix<int>" << std::endl;
    Matrix<int> mt{m.transpose()};
    mt.print();

    std::cout << "\nMatrix addition<int>" << std::endl;
    Matrix<int> madd(m.add(m));
    madd.print();

    std::cout << "\nMatrix subtraction<int>" << std::endl;
    Matrix<int> msub(m.subtract(n));
    msub.print();

    /**
    * Testing float matrix
    */
    std::cout << "\nMatrix<float>" << std::endl;
    Matrix<float> mf{{{0.1, 0.2, 0.3}, {0.4, 0.5, 0.6}}};
    Matrix<float> nf{{{0.9, 0.8, 0.7}, {0.6, 0.5, 0.4}}};
    mf.print();

    std::cout << "\nTranspose Matrix<float>" << std::endl;
    Matrix<float> mtf{mf.transpose()};
    mtf.print();

    std::cout << "\nMatrix addition<float>" << std::endl;
    Matrix<float> mfadd(mf.add(mf));
    mfadd.print();

    std::cout << "\nMatrix subtraction<float>" << std::endl;
    Matrix<float> nfsub(mf.subtract(nf));
    nfsub.print();
}
