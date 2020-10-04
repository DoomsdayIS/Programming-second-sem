#include <iostream>
#include "cube.h"
#include "algo.h"
#include "Exceptions.h"
#include "cube.h"



int main() {
    Cube cube;
    cube.input("input.txt");
    cube.output("start_scan.txt");
    try {
        my_sol::solve(cube);
        cube.output("output.txt");
    } catch (my_exception &exception) {
        std::cout << exception.what() << std::endl;
    }
    return 0;
}