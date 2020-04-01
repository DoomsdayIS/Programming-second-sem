#ifndef LAB2_Vector_H
#define LAB2_Vector_H

#include <string>

class Vector {
private:
    float x_;
    float y_;
    float z_;
public:
    Vector();
    Vector(const float&, const float&, const float&);
    Vector(const Vector&);
    void add_Vector(const Vector&);
    void sub_Vector(const Vector&);
    float length();
    void find_angle(const Vector&);
    void print();
};


#endif //LAB2_Vector_H