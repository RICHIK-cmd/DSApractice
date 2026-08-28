#include <stdio.h>

int nums[20];
int subset[20];
int n;

void generateSubsets(int index, int size)
{
    // Print the current subset
    printf("[");

    for (int i = 0; i < size; i++)
    {
        printf("%d", subset[i]);

        if (i < size - 1)
            printf(",");
    }

    printf("]\n");

    // Try adding every remaining element
    for (int i = index; i < n; i++)
    {
        subset[size] = nums[i];

        generateSubsets(i + 1, size + 1);
    }
}

int main()
{
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d unique elements: ", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("All subsets:\n");

    generateSubsets(0, 0);

    return 0;
}