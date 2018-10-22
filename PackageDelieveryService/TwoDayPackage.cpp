//
// Created by devansh on 21/10/18.
//

#include "OvernightPackage.cpp"

class TwoDayPackage : public Package {

    double twoDayDeliveryCharge;

public:

    TwoDayPackage(Client& sender, Client& receiver, double weight, double costPerKg,
                  double twoDayDeliveryCharge) :
            Package(sender, receiver, weight, costPerKg){

        if (twoDayDeliveryCharge > 0) {
            this->twoDayDeliveryCharge = twoDayDeliveryCharge;
        } else {
            throw "Illegal delievery charge value";
        }
    }

    double calculateCost() override {
        return Package::calculateCost() + twoDayDeliveryCharge;
    }


};