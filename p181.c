#include <stdio.h>

// Function to reverse part of the array
void reverse(int arr[], int start, int end)
{
    end--;  // end is exclusive

    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

// Right rotate by k positions
void rightRotate(int arr[], int n, int k)
{
    k = k % n;

    // Reverse first n-k elements
    reverse(arr, 0, n - k);

    // Reverse last k elements
    reverse(arr, n - k, n);

    // Reverse entire array
    reverse(arr, 0, n);
}

// Left rotate by k positions
void leftRotate(int arr[], int n, int k)
{
    k = k % n;

    // Reverse first k elements
    reverse(arr, 0, k);

    // Reverse remaining n-k elements
    reverse(arr, k, n);

    // Reverse entire array
    reverse(arr, 0, n);
}

int main()
{
    int n, k, choice;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter k: ");
    scanf("%d", &k);

    printf("\nChoose rotation:\n");
    printf("1. Right Rotate\n");
    printf("2. Left Rotate\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            rightRotate(arr, n, k);
            printf("\nArray after right rotation by %d positions:\n", k);
            break;

        case 2:
            leftRotate(arr, n, k);
            printf("\nArray after left rotation by %d positions:\n", k);
            break;

        default:
            printf("\nInvalid choice!\n");
            return 0;
    }

    // Print final array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}