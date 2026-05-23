#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;


void push(char ch) {
    stack[++top] = ch;
}


char pop() {
    return stack[top--];
}

int main() {

    char str[100];

    printf("Enter a string: ");
    gets(str);

    
    for (int i = 0; i < strlen(str); i++) {
        push(str[i]);
    }

    printf("Reversed string: ");

    
    while (top != -1) {
        printf("%c", pop());
    }

    return 0;
}