#include "ThrowAny.cpp"

using namespace std;

int main() {

    int type;

    cout << "Select exception type:\n";
    ThrowAny::showExceptionTypes();
    cout << "Enter choice: ";

    cin >> type;

    try {
        ThrowAny::throwException(type);
    } catch (...) {
        cout << "Exception caught\n";
    }


    return 0;
}