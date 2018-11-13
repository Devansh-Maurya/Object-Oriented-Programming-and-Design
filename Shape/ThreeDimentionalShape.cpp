//
// Created by devansh on 11/13/18.
//

#include "Shape.cpp"

class ThreeDimensionalShape : public Shape{

    const static int DIMENSION = 3;

public:

    double getArea() override = 0;

    virtual double getVolume() = 0;

    virtual const int getDimension() {
        return DIMENSION;
    }
};