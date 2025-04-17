#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    // Constructor
    BankAccount(int accNo, double bal, double rate) 
        : accountNumber(accNo), balance(bal), interestRate(rate) {
        cout << "BankAccount created for account number: " << accountNumber << endl;
    }

    // Destructor
    ~BankAccount() {
        cout << "BankAccount with number " << accountNumber << " is being destroyed." << endl;
    }

    // Existing methods
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void calculateInterest() {
        double interest = balance * (interestRate / 100);
        cout << "Interest: " << interest << endl;
    }

    // Display account info
    void display() const {
        cout << "Account Number: " << accountNumber 
             << "\nBalance: " << balance 
             << "\nInterest Rate: " << interestRate << "%" << endl;
    }
};

int main() {
    // Using constructor instead of setDetails
    BankAccount acc(792764, 15000.0, 3.0);
    acc.deposit(5000);
    acc.withdraw(800);
    acc.calculateInterest();
    acc.display();
    
    return 0;
}