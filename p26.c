#include <stdio.h>
#include <stdlib.h>

void nextGreaterElement(int arr[], int n) {
    int stack[n];
    int top = -1;

    for(int i = 0; i < n; i++) {
        while(top != -1 && arr[i] > stack[top]) {
            printf("%d -> %d\n", stack[top], arr[i]);
            top--;
        }
        stack[++top] = arr[i];
    }

    while(top != -1) {
        printf("%d -> -1\n", stack[top]);
        top--;
    }
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr)/sizeof(arr[0]);

    nextGreaterElement(arr, n);
    return 0;
}