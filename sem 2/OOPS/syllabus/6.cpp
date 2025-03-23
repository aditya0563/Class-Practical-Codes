// Overloading + and - for Complex Numbers
#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex &c) {
        return Complex(real - c.real, imag - c.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(4, 5), c2(2, 3);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;

    cout << "Addition: ";
    c3.display();
    cout << "Subtraction: ";
    c4.display();
    return 0;
}
