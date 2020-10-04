#include "interface.h"
#include <cmath>
#include <iostream>


double Eq_triangle::square() const {
    return pow(a,2)*pow(3,0.5)/4;
}

Eq_triangle::Eq_triangle()
    :a(0)
    ,mass(0)
    ,position(0,0)
{}

double Eq_triangle::perimeter() const {
    return a*3.;
}

double Eq_triangle::getMass() const {
    return mass;
}

Vector2D Eq_triangle::getPosition() const {
    return position;
}

bool Eq_triangle::operator==(const IPhysObject &x) const {
    return mass == x.getMass();
}

bool Eq_triangle::operator<(const IPhysObject &x) const {
    return mass < x.getMass();
}

void Eq_triangle::draw() const {
    std::cout << "name = " << name << "\na = " << a << "\n";
    std::cout << "mass = " << mass << "\nsize = " << getSize() << "\n";
    std::cout << "position: x = " << position.x << ", y = " << position.y << "\n\n";
}

void Eq_triangle::initFromDialog() {
    double a_, mass_;
    Vector2D position_;
    std::cout << "Enter equilateral triangle side, mass and position (x and y) \n";
    std::cin >> a_ >> mass_ >> position_.x >> position_.y;
    a = a_;
    mass = mass_;
    position = position_;
    std::cout << "Created successfully.\n";
}

std::string Eq_triangle::getClassName() const {
    return name;
}

unsigned Eq_triangle::getSize() const {
    return sizeof(*this);
}

Eq_triangle::Eq_triangle(const Eq_triangle &x)
    : a(x.a)
    , mass(x.mass)
    , name(x.name)
    , position(x.position)
{}

Eq_triangle::Eq_triangle(double a_, double mass_, Vector2D &position_)
    : a(a_)
    , mass(mass_)
    , position(position_)
{}


Parallelogram::Parallelogram()
    : a(0)
    , b(0)
    , alpha(0)
    , mass(0)
    , position(0,0)
{}

Parallelogram::Parallelogram(const Parallelogram &x)
    : a(x.a)
    , b(x.b)
    , alpha(x.alpha)
    , mass(x.mass)
    , position(x.position)
{}

double Parallelogram::square() const {
    return a*b*sin(alpha);
}

Parallelogram::Parallelogram(double a_, double b_, double alpha_, double mass_, Vector2D &position_)
    : a(a_)
    , b(b_)
    , alpha(alpha_)
    , mass(mass_)
    , position(position_)
{}

double Parallelogram::perimeter() const {
    return (a + b)*2.;
}

double Parallelogram::getMass() const {
    return mass;
}

Vector2D Parallelogram::getPosition() const {
    return position;
}

bool Parallelogram::operator==(const IPhysObject &x) const {
    return mass == x.getMass();
}

bool Parallelogram::operator<(const IPhysObject &x) const {
    return mass < x.getMass();
}

void Parallelogram::draw() const {
    std::cout << "name = " << name << ";\na = " << a << ", b = " << b << ", angle = " << alpha << "\n";
    std::cout << "mass = " << mass << ";\nsize = " << getSize() << ";\n";
    std::cout << "position: x = " << position.x << ", y = " << position.y << ";\n\n";
}

void Parallelogram::initFromDialog() {
    double a_, b_, alpha_, mass_;
    Vector2D position_;
    std::cout << "Enter Parallelogram sides: a, b and angle (0; Pi); Then enter mass and position (x and y)\n";
    std::cin >> a_ >> b_ >> alpha_ >> mass_ >> position_.x >> position_.y;
    a = a_; b = b_;
    alpha = alpha_;
    mass = mass_;
    position = position_;
    std::cout << "Created successfully.\n";
}

std::string Parallelogram::getClassName() const {
    return name;
}

unsigned Parallelogram::getSize() const {
    return sizeof(*this);
}


