#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printSubset(int subset[], int size)
{
    printf("[");
    
    for (int i = 0; i < size; i++)
    {
        printf("%d", subset[i]);

        if (i < size - 1)
            printf(",");
    }

    printf("]");
}

void generateSubsets(int nums[], int n, int index,
                     int subset[], int size)
{
    // Print the current subset
    printSubset(subset, size);
    printf(" ");

    // Try choosing every possible next element
    for (int i = index; i < n; i++)
    {
        // Skip duplicate elements at the same recursion level
        if (i > index && nums[i] == nums[i - 1])
            continue;

        // Include nums[i]
        subset[size] = nums[i];

        generateSubsets(nums, n, i + 1,
                        subset, size + 1);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];
    int subset[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    // Important: sort first
    sort(nums, n);

    printf("\nAll unique subsets:\n");

    generateSubsets(nums, n, 0, subset, 0);

    return 0;
}