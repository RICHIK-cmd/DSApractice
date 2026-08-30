#include <stdio.h>
#include <stdlib.h>

void solve(int index, int sum, int arr[], int N, int ans[], int *count)
{
    // Base case
    if (index == N)
    {
        ans[*count] = sum;
        (*count)++;
        return;
    }

    // Include current element
    solve(index + 1, sum + arr[index], arr, N, ans, count);

    // Exclude current element
    solve(index + 1, sum, arr, N, ans, count);
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int N;

    printf("Enter N: ");
    scanf("%d", &N);

    int arr[N];
    int total = 1 << N;
    int ans[total];

    printf("Enter the elements:\n");

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    int count = 0;

    solve(0, 0, arr, N, ans, &count);

    qsort(ans, count, sizeof(int), compare);

    printf("Subset sums:\n");

    for (int i = 0; i < count; i++)
    {
        printf("%d ", ans[i]);
    }

    return 0;
}