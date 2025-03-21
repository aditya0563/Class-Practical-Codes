#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(string expression) {
    stack<int> stack;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        // If the token is a number, push it to the stack
        if (isdigit(token[0])) {
            stack.push(stoi(token));
        } 
        // If the token is an operator, pop two elements from the stack, perform the operation, and push the result back to the stack
        else {
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();
            int result;
            switch (token[0]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    cout << "Invalid operator" << endl;
                    return -1;
            }
            stack.push(result);
        }
    }
    return stack.top();
}

int main() {
    string expression = "10 2 8 * + 3 -";
    cout << "Postfix Expression: " << expression << endl;
    int result = evaluatePostfix(expression);
    cout << "Result: " << result << endl;
    return 0;
}
