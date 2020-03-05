#ifndef LAB1_FUNC_H
#define LAB1_FUNC_H
#include <complex>
#include <vector>
#include <iostream>

void swap(int&, int&);
void swap(int*, int*);
void rounding(float&);
void rounding(float*);
void multiply(std::complex<double>&,const double&);
void multiply(std::complex<double>*, double*);
struct Matrix{
    std::vector<std::vector<int>> arr{3,std::vector<int>{3,0}};
};
void transpose(Matrix&);
void transpose(Matrix*);
void my_matrix(Matrix&,std::vector<std::vector<int>>&);
void my_matrix(Matrix*,std::vector<std::vector<int>>&);
void print(const Matrix&);
#endif //LAB1_FUNC_H
