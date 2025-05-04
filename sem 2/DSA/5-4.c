#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    int top;
    int arr[MAX];
} Stack;

// Function to initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Function to push an element onto the stack
void push(Stack* stack, int x) {
    if (stack->top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = x;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function to evaluate a prefix expression
int evaluatePrefix(char* expression) {
    Stack stack;
    initStack(&stack);

    // Tokenizing the input expression
    char* tokens[MAX];
    int count = 0;
    char* token = strtok(expression, " ");
    while (token != NULL) {
        tokens[count++] = token;
        token = strtok(NULL, " ");
    }

    // Process tokens from right to left
    for (int i = count - 1; i >= 0; i--) {
        // If the token is a number, push it to the stack
        if (isdigit(tokens[i][0])) {
            push(&stack, atoi(tokens[i]));
        } 
        // If the token is an operator, pop two elements, perform the operation, and push the result
        else {
            int operand1 = pop(&stack);
            int operand2 = pop(&stack);
            int result;
            switch (tokens[i][0]) {
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
                    printf("Invalid operator\n");
                    return -1;
            }
            push(&stack, result);
        }
    }
    return pop(&stack);
}

int main() {
    char expression[] = "- + 10 * 2 3 5";
    printf("Prefix Expression: %s\n", expression);
    int result = evaluatePrefix(expression);
    printf("Result: %d\n", result);
    return 0;
}
