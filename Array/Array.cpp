//
// Created by devansh on 23/11/18.
//

#include <iostream>

using namespace std;

template <typename T>
class Array {

    int size;

public:

    T* array;

    Array(int size) {
        this->size = size;
        array = new T(size);

        cout << "Array created from template with size " << size << "\n\n";
    }

    ~Array() {
        delete[] array;
    }
};

template <>
class Array<float> {

    int size;

public:

    float *array;

    Array(int size) {
        this->size = size;
        array = new float(size);

        cout << "Array of floats created using specific definition with size " << size << "\n\n";
    }

    ~Array() {
        delete[] array;
    }
};
