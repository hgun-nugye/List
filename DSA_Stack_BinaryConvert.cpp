#include <stdio.h>
#include <stdlib.h>

struct nut {
    int giatri;
    struct nut *next;
};
typedef struct nut Node;

struct Stack {
    Node *top;
};
typedef struct Stack StackType;

//prototype
StackType *PushBinary(StackType **stack, int n);
void ViewBinary(StackType *stack);

int main() 
{
    StackType *stack;
    int n;
		printf("Nhap vao so nguyen he 10 can chuyen doi: ");
    scanf("%d", &n);
    stack = PushBinary(&stack, n);
    printf("He 2 cua so vua nhap la:  ");
    ViewBinary(stack);

    // Free the stack
    while (stack->top != NULL) 
		{
        Node *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    free(stack);
    return 0;
}

//function
StackType *PushBinary(StackType **stack, int n) 
{
    (*stack)->top = NULL;

    while (n!= 1) 
		{
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->giatri=n%2;
        newNode->next=(*stack)->top;
        (*stack)->top=newNode;
        n/=2;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->giatri = n;
    newNode->next =(*stack)->top;
    (*stack)->top = newNode;

    return *stack;
}
void ViewBinary(StackType *stack) 
{
    while (stack->top != NULL) 
		{
        printf("%d", stack->top->giatri);
        stack->top = stack->top->next;
    }
}
