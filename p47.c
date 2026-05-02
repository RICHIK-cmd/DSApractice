// Check for Balanced Parentheses
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure
struct Stack {
    char arr[MAX];
    int top;
};

// Initialize stack
void init(struct Stack* s) {
    s->top = -1;
}

// Push
void push(struct Stack* s, char c) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = c;
}

// Pop
char pop(struct Stack* s) {
    if (s->top == -1)
        return '\0';
    return s->arr[(s->top)--];
}

// Check matching pair
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

// Main logic
int isBalanced(char expr[]) {
    struct Stack s;
    init(&s);

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        // If opening bracket → push
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        }
        // If closing bracket → pop and match
        else if (ch == ')' || ch == '}' || ch == ']') {
            char popped = pop(&s);
            if (!isMatchingPair(popped, ch))
                return 0;
        }
    }

    // If stack empty → balanced
    return (s.top == -1);
}

int main() {
    char expr[MAX];

    printf("Enter expression: ");
    scanf("%s", expr);

    if (isBalanced(expr))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}