#include <stdio.h>

int print2largest(int arr[], int n)
{
    int prev = -1;
    int curr = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > curr)
        {
            prev = curr;
            curr = arr[i];
        }
        else if (arr[i] > prev && arr[i] != curr)
        {
            prev = arr[i];
        }
    }

    return prev;
}

int main()
{
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int result = print2largest(arr, n);

    printf("Second largest distinct element = %d\n", result);

    return 0;
}