#include <set>

using namespace std;

class Point {

public:
    double x;
    double y;

    Point() {
        x = 0;
        y = 0;
    }

    Point(double x, double y) {
        setCoordinates(x, y);
    }

    void setCoordinates(double x, double y) {
        this->x = x;
        this->y = y;
    }

    void setX(double x) {
        this->x = x;
    }

    void setY(double y) {
        this->y = y;
    }

    double getX() {
        return x;
    }

    double geetY() {
        return y;
    }

    int getQuadrant() {
        if (x  >= 0 && y >= 0) {
            return 1;
        } else if (x < 0 && y >= 0){
            return 2;
        } else if (x < 0 && y < 0){
            return 3;
        } else {
            return 4;
        }
    }

    bool isInRange(double minValue, double maxValue) {
        //Returns true or false
        return x >= minValue && x <= maxValue && y >= minValue && y <= maxValue;
    }

    //Overloading '<' operator
    bool operator< (const Point p) const {
        return (x < p.x && y < p.y );
    }
};

class Rectangle {
    Point p1, p2, p3, p4;

    double MIN_VALUE = 0;
    double MAX_VALUE = 20;

    void setPoint(Point p, double minValue, double maxValue) {
        if (p.x <= maxValue && p.x >= minValue && p.y <= maxValue && p.y >= minValue ) {

        }
    }

public:
    Rectangle(Point p1, Point p2, Point p3, Point p4) {

        if(!isInFirstQuadrant()) {
            throw "All points not in first quadrant";
        }

        if (p1.isInRange(MIN_VALUE, MAX_VALUE))
            this->p1 = p1;
        else
            throw "Point not in range";

        if (p2.isInRange(MIN_VALUE, MAX_VALUE))
            this->p2 = p2;
        else
            throw "Point not in range";

        if (p3.isInRange(MIN_VALUE, MAX_VALUE))
            this->p3 = p3;
        else
            throw "Point not in range";

        if (p4.isInRange(MIN_VALUE, MAX_VALUE))
            this->p4 = p4;
        else
            throw "Point not in range";
    }

    /*Rectangle(double x1, double y1, double x2, double y2,
              double x3, double y3, double x4, double y4) {
        p1.x = x1;
        p1.y = y1;
        p2.x = x2;
        p2.y = y2;
        p3.x = x3;
        p3.y = y3;
        p4.x = x4;
        p4.y = y4;
    }*/

    bool isRectangle() {
        set<Point> pointSet;
        pointSet.insert(p1);
        pointSet.insert(p2);
        pointSet.insert(p3);
        pointSet.insert(p4);

        if(pointSet.size() == 4) {

        }
    }



    bool isInFirstQuadrant() {
        return ((p1.getQuadrant() == 1) && (p2.getQuadrant() == 1) &&
                 (p3.getQuadrant() == 1) && (p4.getQuadrant() == 1));
    }
};
