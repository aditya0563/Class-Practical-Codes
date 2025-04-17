#include <iostream>
using namespace std;

int gcd(int a, int b) {
    // Euclidean algorithm
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Rational {
private:
    int numerator;
    int denominator;

    void reduce() {
        int divisor = gcd(numerator, denominator);  // use custom gcd
        numerator /= divisor;
        denominator /= divisor;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Rational(int num = 1, int den = 2) {
        if (den == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        numerator = num;
        denominator = den;
        reduce();
    }

    Rational add(const Rational &other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }

    Rational subtract(const Rational &other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }

    Rational multiply(const Rational &other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }

    Rational divide(const Rational &other) const {
        if (other.numerator == 0) {
            throw invalid_argument("Cannot divide by zero.");
        }
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Rational(num, den);
    }

    void printFraction() const {
        cout << numerator << "/" << denominator;
    }

    void printFloat() const {
        cout << static_cast<double>(numerator) / denominator;
    }
};

int main() {
    try {
        Rational r1(6, 3);
        Rational r2(7, 8);

        cout << "First Rational number: ";
        r1.printFraction();
        cout << endl;

        cout << "Second Rational number: ";
        r2.printFraction();
        cout << endl;

        Rational sum = r1.add(r2);
        cout << "Sum: ";
        sum.printFraction();
        cout << " (as float: ";
        sum.printFloat();
        cout << ")" << endl;

        Rational diff = r1.subtract(r2);
        cout << "Difference: ";
        diff.printFraction();
        cout << " (as float: ";
        diff.printFloat();
        cout << ")" << endl;

        Rational prod = r1.multiply(r2);
        cout << "Product: ";
        prod.printFraction();
        cout << " (as float: ";
        prod.printFloat();
        cout << ")" << endl;

        Rational quot = r1.divide(r2);
        cout << "Quotient: ";
        quot.printFraction();
        cout << " (as float: ";
        quot.printFloat();
        cout << ")" << endl;
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
