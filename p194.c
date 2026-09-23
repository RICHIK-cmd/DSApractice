#include <stdio.h>

void sortColors(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            // Swap arr[mid] and arr[low]
            int temp = arr[mid];
            arr[mid] = arr[low];
            arr[low] = temp;

            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else    // arr[mid] == 2
        {
            // Swap arr[mid] and arr[high]
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;

            high--;
        }
    }
}

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements (only 0, 1, and 2):\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    sortColors(arr, n);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}