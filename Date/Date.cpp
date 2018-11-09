#include <iostream>

using namespace std;

class Date {

    int day;
    int month;
    int year;

    int numberOfDays(int month) {
        switch(month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return 31;
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            case 2:
                return isLeapYear() ? 29 : 28;
            default:
                return 0;
        }
    }

    bool isLeapYear() {
        if (year%100 == 0 && year%400 != 0)
            return false;
        else if (year%4 == 0)
            return true;
    }

    void incrementDate() {
        //Check last date of year
        if (month == 12 && day == 31) {
            month = 1;
            day = 1;
            year++;
        } else {
            int lastDay = numberOfDays(month);
            //If last date of month, increment month and reset date
            if (day == lastDay) {
                month++;
                day = 1;
            } else
                day++;
        }
    }

    void decrementDate() {
        //Check first date of the year
        if (month == 1 && day == 1) {
            month = 12;
            day = 31;
            year--;
        } else {
            int lastDay = numberOfDays(month-1);
            //If first date of month, decrement month and reset date
            if (day == 1) {
                month--;
                day = lastDay;
            } else
                day--;
        }
    }

public:

    Date() = default;

    Date(int day, int month, int year) {
        setDay(day);
        setMonth(month);
        setYear(year);
    }

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

    //Prefix ++
    Date& operator++() {
        incrementDate();
        return *this;
    }

    //Postfix ++
    const Date operator++(int x) {
        Date newDate(day, month, year);
        incrementDate();
        return newDate;
    }

    //Prefix --
    Date& operator--() {
        decrementDate();
        return *this;
    }

    //Postfix --
    const Date operator--(int x) {
        Date newDate(day, month, year);
        decrementDate();
        return newDate;
    }

    friend istream& operator>>(istream& in, Date& date);
    friend ostream& operator<<(ostream& out, Date date);
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

ostream& operator<<(ostream& out, Date date) {
    out << date.day << " / " << date.month << " / " << date.year;

    return out;
}