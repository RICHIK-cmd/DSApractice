#include <stdio.h>

int main()
{
    int n, i, key;
    int found = 0;

    // Input array size
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Element to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Linear Search
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            found = 1;
            break;
        }
    }

    // Result
    if (found)
    {
        printf("Element found at index %d\n", i);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}