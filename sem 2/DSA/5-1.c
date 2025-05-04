#include <stdio.h>
#include <stdbool.h>

#define MAX 1000 // Define maximum size of stack

typedef struct {
    int top;
    int arr[MAX];
} Stack;

// Function to initialize the stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Function to push an element onto the stack
bool push(Stack *stack, int x) {
    if (stack->top >= (MAX - 1)) {
        printf("Stack Overflow\n");
        return false;
    } else {
        stack->arr[++stack->top] = x;
        printf("%d pushed onto stack\n", x);
        return true;
    }
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (stack->top < 0) {
        printf("Stack Underflow\n");
        return 0;
    } else {
        return stack->arr[stack->top--];
    }
}

// Function to peek the top element of the stack
int peek(Stack *stack) {
    if (stack->top < 0) {
        printf("Stack is Empty\n");
        return 0;
    } else {
        return stack->arr[stack->top];
    }
}

// Function to check if the stack is empty
bool isEmpty(Stack *stack) {
    return (stack->top < 0);
}

// Function to traverse and print the stack
void traverse(Stack *stack) {
    if (stack->top < 0) {
        printf("Stack is Empty\n");
        return;
    } else {
        for (int i = stack->top; i >= 0; i--) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    Stack stack;
    initStack(&stack);

    // Perform stack operations
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    traverse(&stack); // Display elements in stack

    printf("%d popped from stack\n", pop(&stack));
    traverse(&stack); // Display elements after pop

    printf("Top element is %d\n", peek(&stack));
    printf("Stack is empty: %s\n", isEmpty(&stack) ? "Yes" : "No");

    return 0;
}
