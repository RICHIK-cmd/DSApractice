// Stock Span Problem using Stack
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

int peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int main() {
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int span[7];
    int n = 7;

    push(0); // store index
    span[0] = 1;

    for (int i = 1; i < n; i++) {

        // Pop while current price is higher
        while (!isEmpty() && price[peek()] <= price[i]) {
            pop();
        }

        // Calculate span
        span[i] = isEmpty() ? (i + 1) : (i - peek());

        push(i);
    }

    // Print result
    printf("Span values:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", span[i]);
    }

    return 0;
}