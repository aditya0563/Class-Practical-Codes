// BankAccount Class
#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    void setDetails(int accNo, double bal, double rate) {
        accountNumber = accNo;
        balance = bal;
        interestRate = rate;
    }

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
};

int main() {
    BankAccount acc;
    acc.setDetails(123456, 10000.0, 5.0);
    acc.deposit(2000);
    acc.withdraw(500);
    acc.calculateInterest();
    return 0;
}
