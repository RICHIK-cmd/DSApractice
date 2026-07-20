#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char c) {
    stack[++top] = c;
}

// Pop
char pop() {
    return stack[top--];
}

int main() {
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);

    int len = strlen(str);

    // Push all characters
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    // Compare
    for (int i = 0; i < len; i++) {
        if (str[i] != pop()) {
            printf("Not a Palindrome\n");
            return 0;
        }
    }

    printf("Palindrome\n");
    return 0;
}