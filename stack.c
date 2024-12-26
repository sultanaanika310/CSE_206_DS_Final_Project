#include <stdio.h>
#define n 100

// Stack structure
typedef struct
{
    int arr[n];
    int top;
} stack;

// Initializing stack
void init (stack *st)
{
    st->top = -1;
}

// Push element onto stack
void push (stack *st, int x)
{
    if (st->top == n-1)
    {
        printf("Stack overflow\n");
    }
    st->top++;
    st->arr[st -> top] = x;
    printf("%d pushed in stack\n", x);
}

// Pop element from stack
void pop (stack *st)
{
    if (st->top == -1)
    {
        printf("Stack underflow\n");
    } else
    {
        printf("%d poped from stack\n", st->arr[st->top]);
        st->top--;
    }
}

// Get the top element of stack
int Top (stack *st)
{
    if (st->top == -1)
    {
        printf("No element in Stack\n");
        return 0;
    } else {
        printf("Top element : %d\n", st->arr[st->top]);
    }
    return st->arr[st->top];
}

int main()
{
    stack st;
    init (&st);

    int choice, value;

    while (1)
    {
        printf("\nSelect Operation : \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top element\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if (choice==1 || choice==2 || choice==3)
        {
            if (choice == 1){
                printf("Enter the value to push : ");
                scanf("%d", &value);
                push(&st, value);
            } else if (choice == 2)
            {
                pop(&st);
            } else
            {
                value = Top(&st);
            }
        } else
        {
            printf("Invalid number! Please try again.\n");
        }
    }

    return 0;
}
