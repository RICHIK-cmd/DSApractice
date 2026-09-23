#include <stdio.h>

int singleNumber(int arr[], int n)
{
    int xr = 0;

    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
    }

    return xr;
}

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int result = singleNumber(arr, n);

    printf("The single number is: %d\n", result);

    return 0;
}