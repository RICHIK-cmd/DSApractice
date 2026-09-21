#include <stdio.h>

int missingNumber(int arr[], int n)
{
    // Sum of all numbers from 0 to n
    long long optimum_sum = (long long)n * (n + 1) / 2;

    // Sum of elements actually present
    long long actual_sum = 0;

    for (int i = 0; i < n; i++)
    {
        actual_sum += arr[i];
    }

    // Missing number
    return optimum_sum - actual_sum;
}

int main()
{
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d distinct elements (range 0 to %d):\n", n, n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int missing = missingNumber(arr, n);

    printf("Missing number = %d\n", missing);

    return 0;
}