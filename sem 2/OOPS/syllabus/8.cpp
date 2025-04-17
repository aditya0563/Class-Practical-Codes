#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string color;
public:
    Shape(string c) : color(c) {}
    virtual ~Shape() {
        cout << "Shape destroyed: " << color << endl;
    }
    
    // Pure virtual functions
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
    
    virtual void display() {
        cout << "Color: " << color << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(string c, double r) : Shape(c), radius(r) {}
    
    double calculateArea() override {
        return M_PI * radius * radius;
    }
    
    double calculatePerimeter() override {
        return 2 * M_PI * radius;
    }
    
    void display() override {
        Shape::display();
        cout << "Type: Circle\nRadius: " << radius 
             << "\nArea: " << calculateArea()
             << "\nPerimeter: " << calculatePerimeter() << endl;
    }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(string c, double l, double w) : Shape(c), length(l), width(w) {}
    
    double calculateArea() override {
        return length * width;
    }
    
    double calculatePerimeter() override {
        return 2 * (length + width);
    }
    
    void display() override {
        Shape::display();
        cout << "Type: Rectangle\nLength: " << length 
             << "\nWidth: " << width
             << "\nArea: " << calculateArea()
             << "\nPerimeter: " << calculatePerimeter() << endl;
    }
};

class Triangle : public Shape {
private:
    double side1, side2, side3;
public:
    Triangle(string c, double s1, double s2, double s3) 
        : Shape(c), side1(s1), side2(s2), side3(s3) {}
    
    double calculatePerimeter() override {
        return side1 + side2 + side3;
    }
    
    double calculateArea() override {
        double s = calculatePerimeter() / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    
    void display() override {
        Shape::display();
        cout << "Type: Triangle\nSides: " << side1 << ", " << side2 << ", " << side3
             << "\nArea: " << calculateArea()
             << "\nPerimeter: " << calculatePerimeter() << endl;
    }
};

int main() {
    Shape* shapes[3];
    
    shapes[0] = new Circle("Red", 5.0);
    shapes[1] = new Rectangle("Blue", 4.0, 6.0);
    shapes[2] = new Triangle("Green", 3.0, 4.0, 5.0);
    
    for (int i = 0; i < 3; ++i) {
        shapes[i]->display();
        cout << endl;
        delete shapes[i];
    }
    
    return 0;
}