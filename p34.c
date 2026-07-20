#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int evaluatePrefix(char exp[]) {
    int len = strlen(exp);

    // Traverse from right to left
    for (int i = len - 1; i >= 0; i--) {
        
        // If operand, push to stack
        if (isdigit(exp[i])) {
            push(exp[i] - '0');  // convert char to int
        }
        else {
            int a = pop();
            int b = pop();

            switch (exp[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }
    return pop();
}

int main() {
    char exp[] = "+9*26";

    printf("Result = %d\n", evaluatePrefix(exp));

    return 0;
}