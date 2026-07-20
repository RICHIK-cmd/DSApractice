#include <stdio.h>

int main()
{
    int n, i, j, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Step 1: Sort (Bubble Sort)
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Step 2: Print unique elements
    printf("Unique elements:\n");

    for(i = 0; i < n-1; i++)
    {
        if(arr[i] != arr[i+1])
        {
            printf("%d ", arr[i]);
        }
    }

    // Print last element (always unique after loop)
    printf("%d", arr[n-1]);

    return 0;
}