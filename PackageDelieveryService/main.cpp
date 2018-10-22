#include <iostream>
#include "TwoDayPackage.cpp"

Client setDetails(const string&);


int main() {

    Client sender = setDetails("sender");
    Client receiver = setDetails("receiver");

    double weight, costPerKg = 100;
    double twoDayDeliveryCharge = 50, overnightCharge = 100;

    cout << "\nEnter the package weight: ";
    cin >> weight;

    cout << "Enter cost per kg: ";
    cin >> costPerKg;

    cout << "Enter two day delievery charge: ";
    cin >> twoDayDeliveryCharge;

    cout << "Enter overnight delievery charge: ";
    cin >> overnightCharge;

    TwoDayPackage twoDayPackage(sender, receiver, weight, costPerKg, twoDayDeliveryCharge);
    Overnightpackage overnightPackage(sender, receiver, weight, costPerKg, overnightCharge);

    cout << "\n\nCost for two day delivery: " << twoDayPackage.calculateCost() << "\n";
    cout << "Cost for overnight delivery: " << overnightPackage.calculateCost() << "\n";

    return 0;
}

Client setDetails(const string& clientType) {
    string name, address, city, state;
    int zipCode;

    cout << "Enter " << clientType << " details:\n\n";
    cout << "Name: ";
    cin >> name;
    cout << "Address: ";
    cin >> address;
    cout << "City: ";
    cin >> city;
    cout << "State: ";
    cin >> state;
    cout << "ZIP Code: ";
    cin >> zipCode;

    return Client(name, address, city, state, zipCode);
}