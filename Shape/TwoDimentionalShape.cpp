//
// Created by devansh on 11/13/18.
//

#include "ThreeDimentionalShape.cpp"

class TwoDimentionalShape : public Shape{

    const static int DIMENSION = 2;

public:

    double getArea() override = 0;

    virtual const int getDimension() {
        return DIMENSION;
    }
};