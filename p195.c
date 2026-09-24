#include <stdio.h>

int majorityElement(int arr[], int n)
{
    int candidate = arr[0];
    int vote = 1;

    // Boyer-Moore Voting
    for (int i = 1; i < n; i++)
    {
        if (vote == 0)
        {
            candidate = arr[i];
            vote = 1;
        }
        else if (arr[i] == candidate)
        {
            vote++;
        }
        else
        {
            vote--;
        }
    }

    // Verify candidate
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == candidate)
        {
            count++;
        }
    }

    if (count > n / 2)
        return candidate;
    else
        return -1;
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

    int result = majorityElement(arr, n);

    if (result == -1)
        printf("No majority element exists.\n");
    else
        printf("Majority element = %d\n", result);

    return 0;
}