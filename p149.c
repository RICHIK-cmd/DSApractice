#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push an element into the stack
void push(int value)
{
    stack[++top] = value;
}

// Pop an element from the stack
int pop()
{
    return stack[top--];
}

// Insert an element at the bottom of the stack
void insertAtBottom(int value)
{
    // If stack is empty, push the value
    if (top == -1)
    {
        push(value);
        return;
    }

    // Remove the top element
    int temp = pop();

    // Recursively reach the bottom
    insertAtBottom(value);

    // Put the removed element back
    push(temp);
}

// Reverse the stack using recursion
void reverseStack()
{
    // Base case
    if (top == -1)
    {
        return;
    }

    // Remove the top element
    int temp = pop();

    // Reverse the remaining stack
    reverseStack();

    // Insert the removed element at the bottom
    insertAtBottom(temp);
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        push(value);
    }

    printf("Original stack (top to bottom): ");

    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    reverseStack();

    printf("\nReversed stack (top to bottom): ");

    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    return 0;
}