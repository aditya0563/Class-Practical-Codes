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

// Function to evaluate a postfix expression
int evaluatePostfix(char* expression) {
    Stack stack;
    initStack(&stack);

    char* token = strtok(expression, " ");
    while (token != NULL) {
        // If the token is a number, push it to the stack
        if (isdigit(token[0])) {
            push(&stack, atoi(token));
        } 
        // If the token is an operator, pop two elements from the stack, perform the operation, and push the result back to the stack
        else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
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
                    printf("Invalid operator\n");
                    return -1;
            }
            push(&stack, result);
        }
        token = strtok(NULL, " ");
    }
    return pop(&stack);
}

int main() {
    char expression[] = "10 2 8 * + 3 -";
    printf("Postfix Expression: %s\n", expression);
    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);
    return 0;
}
