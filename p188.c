#include <stdio.h>

int missingNumber(int arr[], int n)
{
    for (int num = 0; num <= n; num++)
    {
        int found = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == num)
            {
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            return num;
        }
    }

    return -1;
}

int main()
{
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements between 0-5:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Missing number = %d\n", missingNumber(arr, n));

    return 0;
}