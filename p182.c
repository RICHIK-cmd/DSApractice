#include <stdio.h>

// Function to find the next non-zero element
int next_nonzero(int a[], int n, int *j)
{
    while (*j < n)
    {
        if (a[*j] != 0)
            return *j;

        (*j)++;
    }

    return -1;
}

// Function to move all zeroes to the end
void moveZeroes(int a[], int n)
{
    int j = -1;

    for (int i = 0; i < n; i++)
    {
        // If current element is non-zero, do nothing
        if (a[i] != 0)
            continue;

        // Find the first possible non-zero element
        if (j == -1)
            j = i + 1;

        int next = next_nonzero(a, n, &j);

        // No more non-zero elements
        if (next == -1)
            return;

        // Swap a[i] and a[next]
        int temp = a[i];
        a[i] = a[next];
        a[next] = temp;
    }
}

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    moveZeroes(a, n);

    printf("Array after moving zeroes:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}