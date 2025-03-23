// Base Class Shape with Derived Classes
#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string color;
public:
    void setColor(string c) {
        color = c;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() { return M_PI * radius * radius; }
    double calculatePerimeter() { return 2 * M_PI * radius; }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double calculateArea() { return length * width; }
    double calculatePerimeter() { return 2 * (length + width); }
};

int main() {
    Circle c(5.0);
    cout << "Circle Area: " << c.calculateArea() << endl;
    cout << "Circle Perimeter: " << c.calculatePerimeter() << endl;

    Rectangle r(4.0, 6.0);
    cout << "Rectangle Area: " << r.calculateArea() << endl;
    cout << "Rectangle Perimeter: " << r.calculatePerimeter() << endl;
    return 0;
}
