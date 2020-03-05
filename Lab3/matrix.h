#ifndef LAB3_MATRIX_H
#define LAB3_MATRIX_H
#include <vector>

class Matrix {
private:
    std::vector<std::vector<float>> matrix;
public:
    Matrix();
    Matrix(const std::vector<float>&);
    Matrix(const Matrix&);
    Matrix operator*(const float&);
    Matrix operator*(const Matrix&);
    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    bool operator==(const Matrix&) const;
    bool operator!=(const Matrix&) const;

    void print();
};


#endif //LAB3_MATRIX_H
