#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

// Recursive function to delete middle
void deleteMiddle(int current, int size) {
    if (top == -1 || current == size)
        return;

    int x = pop();

    // If middle, skip pushing it back
    if (current != size / 2)
        deleteMiddle(current + 1, size);
    else
        deleteMiddle(current + 1, size); // skip middle

    // Push back all except middle
    if (current != size / 2)
        push(x);
}

void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    printf("Original Stack:\n");
    display();

    deleteMiddle(0, top + 1);

    printf("After Deleting Middle:\n");
    display();

    return 0;
}