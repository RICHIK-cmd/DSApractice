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
    int arr[] = {4, 5, 2, 25};
    int n = 4;

    push(arr[0]);

    for (int i = 1; i < n; i++) {
        int next = arr[i];

        while (!isEmpty() && peek() < next) {
            printf("%d -> %d\n", pop(), next);
        }

        push(next);
    }

    while (!isEmpty()) {
        printf("%d -> -1\n", pop());
    }

    return 0;
}