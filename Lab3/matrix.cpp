#include <iostream>
#include "matrix.h"

Matrix::Matrix() {
    matrix.resize(3);
    for (std::vector<float>& i: matrix){
        i.resize(3);
    }
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < 3; ++i) {
            matrix[j][i] = j*3 + i;
        }
    }
}

Matrix::Matrix(const Matrix &other_matrix) {
    matrix.resize(3);
    for (std::vector<float>& i: matrix){
        i.resize(3);
    }
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < 3; ++i) {
            matrix[j][i] = other_matrix.matrix[j][i];
        }
    }
}

Matrix::Matrix(const std::vector<float> &vector) {
    matrix.resize(3);
    for (std::vector<float> &i: matrix) {
        i.resize(3);
    }
    if (vector.size() != 9){
        std::cout << "Неверные данные, создана базовая матрица" << std::endl;
        for (int j = 0; j < 3; ++j) {
            for (int i = 0; i < 3; ++i) {
                matrix[j][i] = j*3 + i;
            }
        }
    }
    else {
        for (int j = 0; j < 3; ++j) {
            for (int i = 0; i < 3; ++i) {
                matrix[j][i] = vector[j * 3 + i];
            }
        }
    }
}

Matrix Matrix::operator*(const float &x) {
    Matrix buffer{};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            buffer.matrix[i][j] = matrix[i][j]*3;
        }
    }
    return buffer;
}

Matrix Matrix::operator*(const Matrix &mx) {
    Matrix buffer{};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            buffer.matrix[i][j] = matrix[i][0]*mx.matrix[0][j] + matrix[i][1]*mx.matrix[1][j] + matrix[i][2]*mx.matrix[2][j];
        }
    }
    return buffer;
}

Matrix Matrix::operator+(const Matrix &mx) {
    Matrix buffer{};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            buffer.matrix[i][j] = matrix[i][j] + mx.matrix[i][j];
        }
    }
    return buffer;
}

Matrix Matrix::operator-(const Matrix &mx) {
    Matrix buffer{};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            buffer.matrix[i][j] = matrix[i][j] - mx.matrix[i][j];
        }
    }
    return buffer;
}

bool Matrix::operator==(const Matrix &mx) const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (matrix[i][j] != mx.matrix[i][j]){
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &mx) const {
    bool equ = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (matrix[i][j] != mx.matrix[i][j]){
                 return false;
            }
        }
    }
    return true;
}

void Matrix::print() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

