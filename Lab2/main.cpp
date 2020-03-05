#include <iostream>
#include "vector.h"

int main() {
    // Вариант 3
    Vector vector{};
    Vector vector1{vector};
    Vector vector2{1, 2, 3};
    Vector vector3{4, 2, 1};
    vector.add_Vector(vector2);
    vector.length();
    vector3.sub_Vector(vector1);
    vector.find_angle(vector3);
    vector3.print();
    return 0;
}
