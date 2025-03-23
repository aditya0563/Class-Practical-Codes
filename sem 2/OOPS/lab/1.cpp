#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    // Constructor with default values
    Complex(double r = 0.0, double i = 0.0) {
        real = r;
        imaginary = i;  // Fixed variable name
    }

    // Function to add two complex numbers
    Complex add(const Complex &other) const {
        return Complex(real + other.real, imaginary + other.imaginary);  // Directly return
    }

    // Function to subtract two complex numbers
    Complex subtract(const Complex &other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    // Function to print complex number
    void print() const {
        cout << "(" << real << ", " << imaginary << ")" << endl;
    }
};

int main() {
    Complex num1(3.5, 2.5);
    Complex num2(1.2, 1.8);

    cout << "First complex number: ";
    num1.print();
    cout << "Second complex number: ";
    num2.print();

    Complex sum = num1.add(num2);
    cout << "Sum: ";
    sum.print();

    Complex difference = num1.subtract(num2);
    cout << "Difference: ";
    difference.print();

    return 0;
}
