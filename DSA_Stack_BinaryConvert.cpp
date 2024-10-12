#include <stdio.h>
#include <stdlib.h>

struct Node {
    int giatri;
    struct Node* next;
};
typedef struct Node Node;

struct Stack {
    Node* top;
};
typedef struct Stack StackType;

StackType *Binary(StackType **stack, int n) 
{
    StackType* temp = (StackType*)malloc(sizeof(StackType));
    temp->top = NULL;

    while (n != 1) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->giatri = n % 2;
        newNode->next = temp->top;
        temp->top = newNode;
        n /= 2;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->giatri = n;
    newNode->next = temp->top;
    temp->top = newNode;

    return temp;
}

void View(StackType* stack) {
    while (stack->top != NULL) {
        printf("%d", stack->top->giatri);
        stack->top = stack->top->next;
    }
}

int main() {
    StackType* stack;
    int n;

    scanf("%d", &n);
    stack = Binary(&stack, n);
    View(stack);

    // Free the stack
    while (stack->top != NULL) {
        Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    free(stack);

    return 0;
}