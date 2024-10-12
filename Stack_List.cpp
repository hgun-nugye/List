#include <stdio.h>
#include <stdlib.h>

//DN struct Node
struct Node {
    int data;
    struct Node* next;
};

// Stack
struct Stack {
    struct Node* top;
};

// Khoiw tao Stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Check stack rong
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Push Stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed to stack\n", data);
}

// pop
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// phan tu dau stack peek
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}

// xem stackz
void display(struct Stack* stack) {
    struct Node* temp = stack->top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Stack elements:\n");
    display(stack);

    printf("%d popped from stack\n", pop(stack));
    printf("Top element is %d\n", peek(stack));

    printf("Stack elements after pop:\n");
    display(stack);

    return 0;
}
