//Class for Student
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;

public:
    void setDetails(string n, int r, float m) {
        name = n;
        rollNumber = r;
        marks = m;
    }

    void getDetails() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student s1;
    s1.setDetails("Aditya", 101, 95.5);
    s1.getDetails();
    return 0;
}
