#include <stdio.h>

int longestSubarrayWithSumK(int arr[], int n, int k)
{
    int start = 0;
    int ans = 0;
    int sum = 0;

    for (int end = 0; end < n; end++)
    {
        // Add current element
        sum += arr[end];

        // If sum becomes greater than K,
        // remove elements from the left
        while (sum > k && start <= end)
        {
            sum -= arr[start];
            start++;
        }

        // If sum becomes exactly K
        if (sum == k)
        {
            int length = end - start + 1;

            if (length > ans)
            {
                ans = length;
            }
        }
    }

    return ans;
}

int main()
{
    int n, k;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter K: ");
    scanf("%d", &k);

    int result = longestSubarrayWithSumK(arr, n, k);

    printf("Length of longest subarray with sum %d = %d\n", k, result);

    return 0;
}