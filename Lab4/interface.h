#ifndef LAB4_INTERFACE_H
#define LAB4_INTERFACE_H

#include <string>

class IGeoFig{
public:
    virtual double square() const = 0;
    virtual double perimeter() const = 0;
};

class Vector2D{
public:
    double x,y;
    Vector2D(){
        x = y = 0;
    }
    Vector2D(double x_, double y_){
        x = x_;
        y = y_;
    }
};

class IPhysObject {
public:
    virtual double getMass() const = 0;
    virtual Vector2D getPosition() const = 0;
    virtual bool operator==(const IPhysObject& x) const = 0;
    virtual bool operator<(const IPhysObject& x) const = 0;
};

class IPrintable {
public:
    virtual void draw() const = 0;
};

class IDialogInitiable {
public:
    virtual void initFromDialog() = 0;
};

class IBaseObject {
public:
    virtual std::string getClassName() const = 0;
    virtual unsigned getSize() const = 0;
};

class IFigure : public IGeoFig, public IPhysObject, public IPrintable, public IDialogInitiable, public IBaseObject{};

class Eq_triangle : public IFigure{
private:
    const std::string name = "Equilateral triangle";
    double a;
    double mass;
    Vector2D position{};
public:
    Eq_triangle();
    Eq_triangle(const Eq_triangle&);
    Eq_triangle(double a_, double mass_, Vector2D& position_);
    double square() const override;
    double perimeter() const override;
    double getMass() const override;
    Vector2D getPosition() const override;
    bool operator==(const IPhysObject&) const override;
    bool operator<(const IPhysObject&) const override;
    void draw() const override;
    void initFromDialog() override;
    std::string getClassName() const override;
    unsigned getSize() const override;
};

class Parallelogram : public IFigure {
private:
    const std::string name = "Parallelogram";
    double a, b, alpha;
    double mass;
    Vector2D position{};
public:
    Parallelogram();
    Parallelogram(const Parallelogram&);
    Parallelogram(double a_,double b_,double alpha_,double mass_, Vector2D& position_);
    double square() const override;
    double perimeter() const override;
    double getMass() const override;
    Vector2D getPosition() const override;
    bool operator==(const IPhysObject&) const override;
    bool operator<(const IPhysObject&) const override;
    void draw() const override;
    void initFromDialog() override;
    std::string getClassName() const override;
    unsigned getSize() const override;
};



#endif //LAB4_INTERFACE_H
