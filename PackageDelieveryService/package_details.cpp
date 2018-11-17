//
// Created by devansh on 17/11/18.
//

#include <iostream>
#include "TwoDayPackage.cpp"

int main() {

    double costPerKg = 100, twoDayCharge = 50, overnightCharge = 80;

    Package *packages[2];
    double costs[2];

    Client client1("Devansh Maurya", "Mahanagar", "Lucknow", "Uttar Pradesh", 226006);
    Client client2("Deepak Sah", "Araria", "Katihar", "Bihar", 500050);

    packages[0] = new TwoDayPackage(client1, client2, 5, costPerKg, twoDayCharge);
    packages[1] = new Overnightpackage(client2, client1, 10, costPerKg, overnightCharge);

    for (int i = 0; i < 2; ++i) {
        cout << "\nPackage " << (i+1) << " details:\n\n";
        cout << "Sender:\n";
        cout << packages[i]->getSenderName() << "\n";
        cout << packages[i]->getSenderAddress() << ", " << packages[i]->getSenderCity() << "\n";
        cout << packages[i]->getSenderState() << ", " << packages[i]->getSenderZipCode() << "\n\n";

        cout << "Receiver:\n";
        cout << packages[i]->getReceiverName() << "\n";
        cout << packages[i]->getReceiverAddress() << ", " << packages[i]->getReceiverCity() << "\n";
        cout << packages[i]->getReceiverState() << ", " << packages[i]->getReceiverZipCode() << "\n\n";

        costs[i] = packages[i]->calculateCost();
        cout << "Package delivery cost: " << costs[i] << "\n\n";
    }

    cout << "Packages' delievery costs:\n";

    for (int j = 0; j < 2; ++j) {
        cout << "Package " << (j+1) << "'s total delivery cost = " << costs[j] << "\n";
    }
}