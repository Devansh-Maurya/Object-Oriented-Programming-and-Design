//
// Created by devansh on 11/13/18.
//

#include "ThreeDShape.cpp"

int main() {

    Shape *shapes[6];

    shapes[0] = new Circle(4);
    shapes[1] = new Square(4);
    shapes[2] = new Triangle(4, 4);
    shapes[3] = new Sphere(4);
    shapes[4] = new Cube(4);
    shapes[5] = new Tetrahedron(4);

    for (int i = 0; i < 6; ++i) {
        cout << shapes[i]->getArea() << endl;
        if (shapes[i]->getDimension() == 3)
            cout << ((ThreeDimensionalShape*) shapes[i])->getVolume() << endl;
        cout << endl;
        delete shapes[i];
    }

    return 0;
}