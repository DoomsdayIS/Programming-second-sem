#include <iostream>
#include <complex>
#include "func.h"




int main() {
    // ex 1
    int x,y;
    std::cin >> x >> y;
    swap(x,y);
    std::cout << x << "\t" << y << "\n";
    swap(&x, &y);
    std::cout << x << "\t" << y << "\n";
    // ex 6
    float a, a_copy;
    std::cin >> a;
    a_copy = a;
    rounding(a);
    rounding(&a_copy);
    std::cout << a << "\t" << a_copy << "\n";
    // ex 9
    double real, image, mult;
    std:: cin >> real >> image >> mult;
    std::complex<double> z{real,image};
    multiply(z,mult);
    std::cout << z << "\n";
    multiply(&z,&mult);
    std::cout << z << "\n";
    // ex 14
    Matrix matrix;
    std::vector<std::vector<int>> array = {{1,2,3},{4,5,6},{7,8,9}};
    my_matrix(matrix,array);
    print(matrix);
    transpose(matrix);
    print(matrix);
    transpose(&matrix);
    print(matrix);
    return 0;
}