#include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

// Function to evaluate a prefix expression
int evaluatePrefix(string expression) {
    stack<int> stack;
    stringstream ss(expression);
    string token;
    vector<string> tokens;

    // Tokenize the input expression
    while (ss >> token) {
        tokens.push_back(token);
    }

    // Reverse the tokens to process them from right to left
    reverse(tokens.begin(), tokens.end());

    for (const string& token : tokens) {
        // If the token is a number, push it to the stack
        if (isdigit(token[0])) {
            stack.push(stoi(token));
        } 
        // If the token is an operator, pop two elements from the stack, perform the operation, and push the result back to the stack
        else {
            int operand1 = stack.top();
            stack.pop();
            int operand2 = stack.top();
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
    string expression = "- + 10 * 2 3 5";
    cout << "Prefix Expression: " << expression << endl;
    int result = evaluatePrefix(expression);
    cout << "Result: " << result << endl;
    return 0;
}
