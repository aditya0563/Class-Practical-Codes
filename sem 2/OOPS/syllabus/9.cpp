// Exception Handling Using Try-Catch
#include <iostream>
using namespace std;

int main() {
    try {
        int a = 10, b = 0;
        if (b == 0) throw "Division by zero error!";
        cout << a / b << endl;
    } catch (const char *msg) {
        cerr << "Error: " << msg << endl;
    }
    return 0;
}
