//
// Created by devansh on 21/10/18.
//

#include "Package.cpp"

class Overnightpackage : public Package {

    double additionalFee;

public:

    Overnightpackage(Client sender, Client receiver, double weight,
            double costPerKg, double additionalFee) :
            Package(sender, receiver, weight, costPerKg) {

        if (additionalFee > 0)
            this->additionalFee = additionalFee;
        else
            throw "Illeal overnight fee value";
    }

    double calculateCost() override {
        return Package::calculateCost() + additionalFee*getWeight();
    }
};
