#include "Array.cpp"

int main() {

    int size;

    cout << "Enter size for integer array: ";
    cin >> size;

    cout << "Instantiating an array of ints\n";
    Array<int> intArray(size);

    cout << "Enter size for float array: ";
    cin >> size;

    cout << "Instantiating an array of floats\n";
    Array<float> floatArray(size);

    return 0;
}