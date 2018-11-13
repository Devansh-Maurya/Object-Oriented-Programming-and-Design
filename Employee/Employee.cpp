//
// Created by user on 11/6/18.
//

#include "Date.cpp"

class Employee {

    string firstName;
    string lastName;
    Number number;
    Date joiningDate;
    Date birthDate;

public:

    void setFirstName(const string &firstName) {
        Employee::firstName = firstName;
    }

    void setLastName(const string &lastName) {
        Employee::lastName = lastName;
    }

    void setJoiningDate(const Date &joiningDate) {
        Employee::joiningDate = joiningDate;
    }

    void setBirthDate(const Date &birthDate) {
        Employee::birthDate = birthDate;
    }

    friend istream& operator>>(istream& in, Employee& employee);
    friend ostream&operator<<(ostream& out, Employee& employee);
};

istream &operator>>(istream& in, Employee& employee) {
    cout << "Enter first name: ";
    in >> employee.firstName;
    cout << "Enter last name: ";
    in >> employee.lastName;
    cout << "Enter contact details: ";
    cin >> employee.number;
    cout << "Enter birth date: ";
    cin >> employee.birthDate;
    cout << "Enter joining date: ";
    cin >> employee.joiningDate;

    return in;
}

ostream& operator<<(ostream& out, Employee& employee) {
    out << "First name: " << employee.firstName;
    out << "\nLast name: " << employee.lastName;
    out << "\nBirth date: " << employee.birthDate;
    out << "\nJoining date: " << employee.joiningDate;
    out << "\nContact information: " << employee.number;

    return out;
}

