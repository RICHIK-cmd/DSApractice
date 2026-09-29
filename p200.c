#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int arr[], int start, int end)
{
    while (start < end)
    {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

void nextPermutation(int arr[], int n)
{
    int bp = -1;

    // Step 1: Find the break point
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            bp = i;
            break;
        }
    }

    // Step 2 & 3: Find the first greater element
    // from the right and swap
    if (bp != -1)
    {
        for (int i = n - 1; i > bp; i--)
        {
            if (arr[i] > arr[bp])
            {
                swap(&arr[i], &arr[bp]);
                break;
            }
        }
    }

    // Step 4: Reverse everything after bp
    reverse(arr, bp + 1, n - 1);
}

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    nextPermutation(arr, n);

    printf("Next permutation: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}