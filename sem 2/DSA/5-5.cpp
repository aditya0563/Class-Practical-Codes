#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to get the precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to check if a character is an operand
bool isOperand(char c) {
    return isalpha(c) || isdigit(c);
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string infix) {
    stack<char> stack;
    string postfix;

    for (char& c : infix) {
        // If the character is an operand, add it to the output string
        if (isOperand(c)) {
            postfix += c;
        }
        // If the character is '(', push it to the stack
        else if (c == '(') {
            stack.push(c);
        }
        // If the character is ')', pop and output from the stack until '(' is found
        else if (c == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop(); // Remove '(' from the stack
        }
        // If the character is an operator
        else {
            while (!stack.empty() && precedence(c) <= precedence(stack.top())) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }

    // Pop all remaining operators from the stack
    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int main() {
    string infix = "A+B*C";
    cout << "Infix Expression: " << infix << endl;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
