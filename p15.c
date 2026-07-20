//reverse using recursion
#include <stdio.h>

void reverse(int arr[], int n) {
    
    if(n == 0)
        return;

    
    printf("%d ", arr[n - 1]);

    
    reverse(arr, n - 1);
}

int main() {
    int n;

    printf("ENTER THE NUMBER OF ELEMENTS:\n");
    scanf("%d", &n);

    int arr[n];

    printf("ENTER THE ELEMENTS OF THE ARRAY:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("REVERSE ARRAY:\n");
    reverse(arr, n);

    return 0;
}