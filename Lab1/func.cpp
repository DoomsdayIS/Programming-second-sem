#include "func.h"
#include <cmath>
#include <complex>


void swap(int& x,int& y){
    int t = x;
    x = y;
    y = t;
}

void swap(int* x, int* y){
    int t = *x;
    *x = *y;
    *y = t;
}

void rounding(float& x){
    x = round(x);
}

void rounding(float* x){
    *x = round(*x);
}

void multiply(std::complex<double>& x,const double& y){
    x = x * y;
}

void multiply(std::complex<double>* x, double* y){
    *x = (*x) * (*y);
}

void transpose(Matrix& matrix){
    std::vector<std::vector<int>> buffer = {{matrix.arr[0][0],matrix.arr[1][0],matrix.arr[2][0]},{matrix.arr[0][1],matrix.arr[1][1],matrix.arr[2][1]}
            ,{matrix.arr[0][2],matrix.arr[1][2],matrix.arr[2][2]}};
    my_matrix(matrix,buffer);
}

void transpose(Matrix* matrix){
    std::vector<std::vector<int>> buffer = {{matrix->arr[0][0],matrix->arr[1][0],matrix->arr[2][0]},{matrix->arr[0][1],matrix->arr[1][1],matrix->arr[2][1]}
            ,{matrix->arr[0][2],matrix->arr[1][2],matrix->arr[2][2]}};
    my_matrix(matrix,buffer);
}

void print(const Matrix& matrix) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix.arr[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void my_matrix(Matrix& matrix,std::vector<std::vector<int>>& array) {
    for (int i = 0; i <3 ; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix.arr[i][j] = array[i][j];
        }
    }
}

void my_matrix(Matrix* matrix,std::vector<std::vector<int>>& array) {
    for (int i = 0; i <3 ; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix->arr[i][j] = array[i][j];
        }
    }
}