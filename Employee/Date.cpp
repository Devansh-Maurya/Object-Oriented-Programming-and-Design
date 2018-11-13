#include "Number.cpp"

using namespace std;

class Date {

    int day;
    int month;
    int year;

public:

    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    void setDay(int day) {
        if (day <=31 && day > 0)
            Date::day = day;
    }

    void setMonth(int month) {
        if (month <=12 && month > 0)
            Date::month = month;
    }

    void setYear(int year) {
        if (year > 0)
            Date::year = year;
    }

    void printDate() {
        cout << day << " / " << month << " / " << year;
    }

    friend istream& operator>>(istream& in, Date& date);
    friend ostream& operator<<(ostream& out, Date& date);
};

istream& operator>>(istream& in, Date& date) {
    int d;

    cout << "\nEnter day: ";
    cin >> d;
    date.setDay(d);

    cout << "Enter month: ";
    cin >> d;
    date.setMonth(d);

    cout << "Enter year: ";
    cin >> d;
    date.setYear(d);

    return in;
}

ostream& operator<<(ostream& out, Date& date) {
    out << date.day << " / " << date.month << " / " << date.year;

    return out;
}