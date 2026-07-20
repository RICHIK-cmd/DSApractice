#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}

// Pop function
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

int main() {
    char str[MAX];
    
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);

    // Push all characters into stack
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    // Pop all characters to reverse string
    for (int i = 0; i < len; i++) {
        str[i] = pop();
    }

    printf("Reversed string: %s\n", str);

    return 0;
}