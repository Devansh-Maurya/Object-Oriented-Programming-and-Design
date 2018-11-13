//
// Created by user on 11/13/18.
//
#include <cmath>
#include "TwoDShapes.cpp"

class Sphere : public ThreeDimensionalShape{

    double r;

public:

    Sphere(double r) : r(r) {}

    double getArea() override {
        cout << "Calculating area of sphere: ";
        return 4*M_PI*r*r;
    }

    double getVolume() override {
        cout << "Calculating volume of sphere: ";
        return (4*M_PI*r*r*r)/3;
    }
};

class Cube : public ThreeDimensionalShape {

    double side;

public:

    Cube(double side) : side(side) {}

    double getArea() override {
        cout << "Calculating area of cube: ";
        return 6*side*side;
    }

    double getVolume() override {
        cout << "Calculating volume of cube: ";
        return side*side*side;
    }
};

class Tetrahedron : public ThreeDimensionalShape {

    double side;

public:

    Tetrahedron(double side) : side(side) {}

    double getArea() override {
        cout << "Calculating area of tetrahedron: ";
        return sqrt(3)*side*side;
    }

    double getVolume() override {
        cout << "Calculating volume of tetrahedron: ";
        return (sqrt(2)*side*side*side)/12;
    }
};