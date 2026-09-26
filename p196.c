#include <stdio.h>
#include <limits.h>

int maxSubArray(int arr[], int n)
{
    int curr_sum = 0;
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];

        // Update maximum sum
        if (curr_sum > ans)
        {
            ans = curr_sum;
        }

        // If current sum becomes negative,
        // start a new subarray
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }

    return ans;
}

int main()
{
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int result = maxSubArray(arr, n);

    printf("Maximum Subarray Sum = %d\n", result);

    return 0;
}