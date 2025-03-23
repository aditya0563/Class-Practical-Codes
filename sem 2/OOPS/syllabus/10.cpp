// File Handling in C++
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ofstream outFile("data.txt");
    outFile << "Hello, File Handling in C++!" << endl;
    outFile.close();

    ifstream inFile("data.txt");
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
    return 0;
}
