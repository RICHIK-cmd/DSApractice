#include <stdio.h>

#define MOD 1000000007

int solve(int arr[], int index, int sum)
{
    // If required sum becomes 0,
    // we found one valid subset
    if (sum == 0)
    {
        return 1;
    }

    // If there are no elements left
    // and sum is still not 0
    if (index < 0)
    {
        return 0;
    }

    // Option 1: Exclude current element
    int exclude = solve(arr, index - 1, sum);

    // Option 2: Include current element
    int include = 0;

    if (arr[index] <= sum)
    {
        include = solve(arr, index - 1, sum - arr[index]);
    }

    return (include + exclude) % MOD;
}

int perfectSum(int arr[], int N, int sum)
{
    return solve(arr, N - 1, sum);
}

int main()
{
    int N, sum;

    printf("Enter N: ");
    scanf("%d", &N);

    int arr[N];

    printf("Enter array elements: ");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter sum: ");
    scanf("%d", &sum);

    int result = perfectSum(arr, N, sum);

    printf("Number of subsets = %d\n", result);

    return 0;
}