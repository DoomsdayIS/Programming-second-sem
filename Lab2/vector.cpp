#include "vector.h"
#include <cmath>
#include <iostream>

Vector::Vector()
        : x_(0)
        , y_(0)
        , z_(0)
{}

Vector::Vector(const float &x, const float &y, const float &z)
        : x_(x)
        , y_(y)
        , z_(z)
{}

Vector::Vector(const Vector &vec)
        : x_(vec.x_)
        , y_(vec.y_)
        , z_(vec.z_)
{}


void Vector::add_Vector(const Vector &vec) {
    x_ += vec.x_;
    y_ += vec.y_;
    z_ += vec.z_;
}

void Vector::sub_Vector(const Vector &vec) {
    x_ -= vec.x_;
    y_ -= vec.y_;
    z_ -= vec.z_;
}

float Vector::length() {
    return std::sqrtf(powf(x_,2) + powf(y_,2) + powf(z_,2));
}

void Vector::find_angle(const Vector &vec) {
    if ((powf(x_,2) + powf(y_,2) + powf(z_,2)) == 0 or (powf(vec.x_,2) + powf(vec.y_,2) + powf(vec.z_,2)) == 0){
        std::cout << "Нельзя искать угол с нулевым вектором!" << std::endl;
    } else {
        std::cout << "Угол между векторами равен "
                  << acosf((x_ * vec.x_ + y_ * vec.y_ + z_ * vec.z_) / (std::sqrtf(powf(x_, 2) + powf(y_, 2) + powf(z_, 2))
                                                                        * std::sqrtf(
                          powf(vec.x_, 2) + powf(vec.y_, 2) + powf(vec.z_, 2)))) << " радиан"<< std::endl;
    }
}

void Vector::print() {
    std::cout << "(" << x_ << ", " << y_ << ", " << z_ << ")" << std::endl;
}