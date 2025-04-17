// WAP on Dynamic Memory Allocation (new and delete keywords):
#include <iostream>
using namespace std;

int main() {
    int *ptr = new int; // Dynamic memory allocation
    *ptr = 150;         // Assign value
    cout << "Value: " << *ptr << endl;
    delete ptr;         // Free memory
    return 0;
}