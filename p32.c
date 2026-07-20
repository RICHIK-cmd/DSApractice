#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack structure
char stack[MAX];
int top = -1;

// Push operation
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = ch;
    }
}

// Pop operation
char pop() {
    if (top == -1) {
        return '\0';  // Empty stack
    } else {
        return stack[top--];
    }
}

int main() {
    char str[MAX];
    int i, len;
    int isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    // Step 1: Push all characters into stack
    for (i = 0; i < len; i++) {
        push(str[i]);
    }

    // Step 2: Pop and compare with original string
    for (i = 0; i < len; i++) {
        if (str[i] != pop()) {
            isPalindrome = 0;
            break;
        }
    }

    // Output result
    if (isPalindrome)
        printf("Palindrome\n");
    else
        printf("Not a Palindrome\n");

    return 0;
}