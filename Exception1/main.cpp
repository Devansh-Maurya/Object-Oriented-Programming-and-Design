#include "TestClass.cpp"

int main() {

    try {
        TestClass object;
    } catch (int e) {
        cout << "\nException occurred during construction of object " << e << "\n";
    }

    return 0;
}