#include <stdio.h>

int numSubarraysWithSum(int nums[], int n, int goal)
{
    int freq[n + 1];
    int prefSum = 0, cnt = 0;

    // Initialize frequency array
    for (int i = 0; i <= n; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        prefSum += nums[i];

        if (prefSum == goal)
        {
            cnt++;
        }

        if (prefSum - goal >= 0)
        {
            cnt += freq[prefSum - goal];
        }

        freq[prefSum]++;
    }

    return cnt;
}

int main()
{
    int n, goal;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter the binary array (0s and 1s): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("Enter the goal: ");
    scanf("%d", &goal);

    int result = numSubarraysWithSum(nums, n, goal);

    printf("Number of subarrays with sum %d: %d\n", goal, result);

    return 0;
}