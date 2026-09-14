#include <stdio.h>

int largest(int arr[], int n)
{
    int ans = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > ans)
            ans = arr[i];
    }

    return ans;
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

    int result = largest(arr, n);

    printf("Largest element = %d\n", result);

    return 0;
}