#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int precedence(char x) {
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char exp[] = "A+B*C";
    int i = 0;

    while(exp[i] != '\0') {
        if(isalnum(exp[i])) {
            printf("%c", exp[i]);
        }
        else {
            while(top != -1 && precedence(stack[top]) >= precedence(exp[i])) {
                printf("%c", pop());
            }
            push(exp[i]);
        }
        i++;
    }

    while(top != -1) {
        printf("%c", pop());
    }

    return 0;
}