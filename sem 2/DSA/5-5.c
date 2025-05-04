#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    int top;
    char arr[MAX];
} Stack;

// Function to initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Function to push an element onto the stack
void push(Stack* stack, char x) {
    if (stack->top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = x;
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    if (stack->top < 0) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->arr[stack->top--];
}

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
int isOperand(char c) {
    return isalpha(c) || isdigit(c);
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    Stack stack;
    initStack(&stack);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // If the character is an operand, add it to the output string
        if (isOperand(c)) {
            postfix[j++] = c;
        }
        // If the character is '(', push it to the stack
        else if (c == '(') {
            push(&stack, c);
        }
        // If the character is ')', pop and output from the stack until '(' is found
        else if (c == ')') {
            while (stack.top >= 0 && stack.arr[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Remove '(' from the stack
        }
        // If the character is an operator
        else {
            while (stack.top >= 0 && precedence(c) <= precedence(stack.arr[stack.top])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, c);
        }
    }

    // Pop all remaining operators from the stack
    while (stack.top >= 0) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0'; // Null-terminate the string
}

int main() {
    char infix[] = "A+B*C";
    char postfix[MAX];

    printf("Infix Expression: %s\n", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
