#include <string>

using namespace std;

//Used for creating sender and receiver
//Helps in preventing duplication of code
//Prevents having the constructor too many arguments

class Client {

private:
    string name;
    string address;
    string city;
    string state;
    int zipCode;

public:

    Client(string name, string address, string city, string state, int zipCode)
        : name(name), address(address), city(city), state(state), zipCode(zipCode) {}
};