#include <stdio.h>

int removeDuplicates(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                // Shift elements left
                for (int k = j; k < n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }

                n--;
                j--;
            }
        }
    }

    return n;
}

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    n = removeDuplicates(arr, n);

    printf("Array after removing duplicates:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}