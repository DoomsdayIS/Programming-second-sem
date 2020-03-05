#include "matrix.h"
#include "queue.h"
#include <iostream>

//enum Operation{
//    close,
//    push,
//    pop,
//    print,
//};

int main() {
// Задание 4
    Matrix mx1{};
    std::vector<float> buffer = {3.25,5,2,5.5,1,7,34,-5,8};
    Matrix mx2{buffer};
    mx1.print();
    mx2.print();
    Matrix mx3 = mx1 * 3;
    mx3.print();
    Matrix mx4 = mx1 * mx2;
    mx4.print();
    mx3 = mx1 + mx2;
    mx3.print();
    mx4 = mx1 - mx2;
    mx4.print();
    if (mx1 == mx2){
        std::cout << "Это равные матрицы" << std::endl;
    } else {
        std::cout << "Это не равные матрицы" << std::endl;
    }
    Matrix mx5(mx2);
    if (mx5 == mx2){
        std::cout << "Это равные матрицы" << std::endl;
    } else {
        std::cout << "Это не равные матрицы" << std::endl;
    }
// Задание 8
    Queue queue;
    std::cout << "При работе с очередью введите 1 чтобы добавить значение,потом введите значение. Введите 2 чтобы получить значение."
                 "Введите 3 чтобы вывести всю очередь. Введите 0 чтобы закончить работу";
    int operation;
    bool x = true;
    while (x){
        std::cin >> operation;
        switch(operation){
            case(1): queue >> std::cin;
                break;
            case (2): queue << std::cout;
                break;
            case (3): queue.print_all();
                break;
            case(0): x = false;
                break;
            default: std::cout << "Неверная операция!" << std::endl;
        }
    }
    return 0;
}
