#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack structure to manage top pointer
typedef struct Stack {
    Node* top;
} Stack;

// Function to initialize the stack
void initStack(Stack* stack) {
    stack->top = NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap overflow\n");
        return;
    }
    newNode->data = x;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed onto stack\n", x);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    Node* temp = stack->top;
    stack->top = stack->top->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to peek the top element of the stack
int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to traverse and print the stack
void traverse(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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
