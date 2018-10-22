//
// Created by devansh on 21/10/18.
//

#include <string>
#include "Client.cpp"

using namespace std;

class Package {

    Client sender;
    Client receiver;
    double weight;
    double costPerKg;

public:

    Package(string sName, string sAddress, string sCity, string sState, int sZipCode,
            string rName, string rAddress, string rCity, string rState, int rZipCode,
            double weight, double costPerKg) :
            sender(sName, sAddress, sCity, sState, sZipCode),
            receiver(rName, rAddress, rCity, rState, rZipCode) {

        if (weight > 0)
            this->weight = weight;
        else
            throw "Illegal weight value";

        if (costPerKg > 0)
            this->costPerKg = costPerKg;
        else
            throw "Illegal cost per kg value";
    }

    Package(Client& sender, Client& receiver, double weight, double costPerKg) :
            sender(sender), receiver(receiver){

        if (weight > 0)
            this->weight = weight;
        else
            throw "Illegal weight value";

        if (costPerKg > 0)
            this->costPerKg = costPerKg;
        else
            throw "Illegal cost per kg value";
    }

    virtual double calculateCost() {
        return weight*costPerKg;
    }

    double getWeight() const {
        return weight;
    }
};