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

    Client() {}

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Client::name = name;
    }

    const string &getAddress() const {
        return address;
    }

    void setAddress(const string &address) {
        Client::address = address;
    }

    const string &getCity() const {
        return city;
    }

    void setCity(const string &city) {
        Client::city = city;
    }

    const string &getState() const {
        return state;
    }

    void setState(const string &state) {
        Client::state = state;
    }

    int getZipCode() const {
        return zipCode;
    }

    void setZipCode(int zipCode) {
        Client::zipCode = zipCode;
    }
};