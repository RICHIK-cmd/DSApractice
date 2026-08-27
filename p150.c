#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push an element into the stack
void push(int element)
{
    top++;
    stack[top] = element;
}

// Pop an element from the stack
int pop()
{
    int element = stack[top];
    top--;
    return element;
}

// Returns the top element
int peek()
{
    return stack[top];
}

// Places element at its correct position
void placeAtCorrectPos(int element)
{
    // If stack is empty OR top element is smaller
    if (top == -1 || peek() < element)
    {
        push(element);
        return;
    }

    // Remove the top element
    int topElement = pop();

    // Recursively find correct position
    placeAtCorrectPos(element);

    // Put the removed element back
    push(topElement);
}

// Sorts the stack in descending order
void sortSt()
{
    // Base case
    if (top == -1)
        return;

    // Remove top element
    int element = pop();

    // Sort remaining stack
    sortSt();

    // Insert element at correct position
    placeAtCorrectPos(element);
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter stack elements from bottom to top: ");

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        push(x);
    }

    sortSt();

    printf("Sorted stack (top to bottom): ");

    while (top != -1)
    {
        printf("%d ", pop());
    }

    return 0;
}