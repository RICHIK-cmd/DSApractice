#include <stdio.h>

int main()
{
    int i, n;

    printf("ENTER THE NUMBER OF ELEMENTS: \n");
    scanf("%d", &n);

    int arr[n];

    printf("ENTER THE ELEMENTS OF THE ARRAY : \n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("ORIGINAL ARRAY: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nREVERSED ARRAY: ");
    for(i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    return 0;
}