#include <stdio.h>
#include <math.h>

int stack[100];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int num, temp, digits = 0;
    int reversed = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    temp = num;

    // Count digits
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = num;

    // Push digits from LEFT to RIGHT
    for (int i = digits - 1; i >= 0; i--) {
        int divisor = pow(10, i);
        int digit = temp / divisor;
        push(digit);
        temp = temp % divisor;
    }

    // Pop and build reversed number
    while (top != -1) {
        reversed = reversed * 10 + pop();
    }

    printf("Reversed number: %d\n", reversed);

    return 0;
}