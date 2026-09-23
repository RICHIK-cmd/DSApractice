#include <stdio.h>

int longestSubarrayWithSumK(int arr[], int n, int k)
{
    int maxLength = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];

            if (sum == k)
            {
                int length = j - i + 1;

                if (length > maxLength)
                {
                    maxLength = length;
                }
            }
        }
    }

    return maxLength;
}

int main()
{
    int n, k;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter K: ");
    scanf("%d", &k);

    int result = longestSubarrayWithSumK(arr, n, k);

    printf("Longest subarray length = %d\n", result);

    return 0;
}