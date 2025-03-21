#include <iostream>
using namespace std;

#define MAX 1000 // Define maximum size of stack

class Stack {
    int top;

public:
    int arr[MAX]; // Stack array

    Stack() {
        top = -1;
    }

    // Function to push an element onto the stack
    bool push(int x) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow" << endl;
            return false;
        } else {
            arr[++top] = x;
            cout << x << " pushed onto stack" << endl;
            return true;
        }
    }

    // Function to pop an element from the stack
    int pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return 0;
        } else {
            int x = arr[top--];
            return x;
        }
    }

    // Function to peek the top element of the stack
    int peek() {
        if (top < 0) {
            cout << "Stack is Empty" << endl;
            return 0;
        } else {
            int x = arr[top];
            return x;
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return (top < 0);
    }

    // Function to traverse and print the stack
    void traverse() {
        if (top < 0) {
            cout << "Stack is Empty" << endl;
            return;
        } else {
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack;

    // Perform stack operations
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.traverse(); // Display elements in stack

    cout << stack.pop() << " popped from stack" << endl;
    stack.traverse(); // Display elements after pop

    cout << "Top element is " << stack.peek() << endl;
    cout << "Stack is empty: " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
