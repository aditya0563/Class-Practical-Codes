#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Stack class to implement stack operations using a linked list
class Stack {
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Function to push an element onto the stack
    void push(int x) {
        Node* newNode = new Node();
        if (!newNode) {
            cout << "Heap overflow" << endl;
            return;
        }
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        cout << x << " pushed onto stack" << endl;
    }

    // Function to pop an element from the stack
    int pop() {
        if (top == nullptr) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        Node* temp = top;
        top = top->next;
        int popped = temp->data;
        delete temp;
        return popped;
    }

    // Function to peek the top element of the stack
    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to traverse and print the stack
    void traverse() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
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
