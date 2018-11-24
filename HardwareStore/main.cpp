#include <fstream>
#include <iostream>
#include <cstdio>
#include "Tool.cpp"

using namespace std;

int findRecordRow(int, fstream&);
void seekToBeg(fstream&);
void getRecordDetails(int, fstream&, int&, string&, int&, double&);
void seekToLine(int, fstream&);
void modifyQuantity(int, fstream&, int);
void modifyCost(int, fstream&, double);
void deleteRecord(int, fstream&);


int main() {

    int id, quantity;
    string name;
    double cost;

    //trunc is needed because we have a non-existent file
    fstream fout("hardware.csv", fstream::in | fstream::out | fstream::trunc);

    Tool tools[10] = {Tool(3, "Electric sandler", 0, 0),
                     Tool(17, "Hammer", 0, 0),
                     Tool(24, "Jig saw", 0, 0),
                     Tool(39, "lawn mover", 0, 0),
                     Tool(56, "Power saw", 0, 0),
                     Tool(68, "Screwdriver", 0, 0),
                     Tool(77, "Sledge hammer", 0, 0),
                     Tool(83, "Wrench", 0, 0),
                     Tool(86, "File", 0, 0),
                     Tool(95, "Hack saw", 0, 0)};

    for (int i = 0; i < 10; ++i) {
        fout << tools[i].getId() << ", " << tools[i].getName() << ", ";
        fout << tools[i].getQuantity() << "0, " << tools[i].getCost() << "0.00" << endl;
    }

    seekToBeg(fout);

    cout << "Listing all records: \n\n";
    cout << "RECORD\t\t\t\t" << "NAME\t\t\t\t" << "QUANTITY\t\t\t" << "COST\t\t\t\t\n\n";

    for (int j = 0; j < 10; ++j) {
        printf("%-20d%-20s%-20d%-20f\n", tools[j].getId(), tools[j].getName().c_str(),
                tools[j].getQuantity(), tools[j].getCost());
    }

    int temp, row;
    double temp2;

    cout << "Enter id of record that you want to edit: ";
    cin >> temp;

    row = findRecordRow(temp, fout);

    if(row == -1) {
        cout << "Record not found\n";
        return -1;
    }

    cout << "Record details:\n";
    getRecordDetails(row, fout, id, name, quantity, cost);
    printf("%-20d%-20s%-20d%-20f\n", id, name.c_str(), quantity, cost);

    cout << "What do you want to do?\n";
    cout << "1: Modify\n2: Delete\n";
    cout << "Enter your choice: ";
    cin >> temp;

    string record;

    if (temp == 1) {
        cout << "What do you want to modify?\n";
        cout << "1: Quantity\n2: Cost\n\nEnter your choice: ";
        cin >> temp;

        cout << "Enter new value: ";
        cin >> temp2;


        if (temp == 1) {
            modifyQuantity(row, fout, temp2);
        } else if (temp == 2) {
            modifyCost(row, fout, temp2);
        }

    } else if (temp == 2) {
        cout << "Enter record id to delete: ";
        cin >> temp;

        deleteRecord(temp, fout);

    }

    return 0;
}

void getRecordDetails(int row, fstream &file, int &id, string &name, int &quantity, double &cost) {

    unsigned long tokenPos;
    string record;
    char delimiter = ',';

    seekToBeg(file);

    //Reach to the correct row
    seekToLine(row, file);

    getline(file, record);

    tokenPos = record.find(delimiter);
    id = stoi(record.substr(0, tokenPos));

    record = record.substr(tokenPos+1, record.length());
    tokenPos = record.find(delimiter);
    name = record.substr(0, tokenPos);

    record = record.substr(tokenPos+1, record.length());
    tokenPos = record.find(delimiter);
    quantity = stoi(record.substr(0, tokenPos));

    record = record.substr(tokenPos+1, record.length());
    cost = stod(record.substr(0, record.length()));
}

int findRecordRow(int rId, fstream &file) {

    string record;
    int row = 0;

    while (file) {
        getline(file, record);
        row++;
        if (rId == stoi(record.substr(0, record.find(',')))) {
            cout << "Record found\n";
            return row;
        }
    }

    return -1;
}

void seekToBeg(fstream& file) {

    file.clear();
    file.seekg(0, fstream::beg);
}

void seekToLine(int row, fstream& file) {

    int currentRow = 1;
    string line;

    while (file && (currentRow != row)) {
        getline(file, line);
        currentRow++;
    }
}

void modifyQuantity(int row, fstream &file, int newQuantity) {
    int id, quantity;
    string name;
    double cost;

    getRecordDetails(row, file, id, name, quantity, cost);
    seekToBeg(file);
    seekToLine(row, file);

    file << id << ", " << name << ", ";
    file << newQuantity << ", " << cost << endl;
}

void modifyCost(int row, fstream &file, double newCost) {
    int id, quantity;
    string name;
    double cost;

    getRecordDetails(row, file, id, name, quantity, cost);
    seekToBeg(file);
    seekToLine(row, file);

    file << id << ", " << name << ", ";
    file << quantity << ", " << newCost << endl;
}

void deleteRecord(int row, fstream &file) {
    string record;

    seekToBeg(file);
    seekToLine(row, file);
    getline(file, record);

    seekToBeg(file);
    seekToLine(row, file);
    file << "";

}