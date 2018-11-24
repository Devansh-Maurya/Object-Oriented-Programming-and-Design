//
// Created by devansh on 23/11/18.
//
#include <string>

using namespace std;
class Tool {

    int id;
    string name;
    int quantity;
    double cost;

public:

    Tool(int id, string name, int quantity = 0, double cost = 0) {
        this->id = id;
        this->name = name;
        this->quantity = quantity;
        this->cost = cost;
    }

    int getId() const {
        return id;
    }

    const string &getName() const {
        return name;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int quantity) {
        Tool::quantity = quantity;
    }

    double getCost() const {
        return cost;
    }

    void setCost(double cost) {
        if (cost >= 0)
            Tool::cost = cost;
    }
};

/* Tool tools[10] = {Tool(3, "Electric sandler", 7, 57.98),
                     Tool(17, "Hammer", 26, 11.99),
                     Tool(24, "Jig saw", 21, 11.00),
                     Tool(39, "lawn mover", 3, 79.50),
                     Tool(56, "Power saw", 18, 99.99),
                     Tool(68, "Screwdriver", 106, 6.99),
                     Tool(77, "Sledge hammer", 11, 21.50),
                     Tool(83, "Wrench", 34, 7.50),
                     Tool(86, "File", 34, 9.99),
                     Tool(95, "Hack saw", 18, 14.99)};
                     */