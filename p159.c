#include <stdio.h>

int result[100][9];
int current[9];
int resultCount = 0;

// Backtracking function
void solve(int start, int k, int n, int index)
{
    // If we have selected k numbers
    if (index == k)
    {
        // Check whether their sum is n
        if (n == 0)
        {
            for (int i = 0; i < k; i++)
            {
                result[resultCount][i] = current[i];
            }

            resultCount++;
        }

        return;
    }

    // Try numbers from start to 9
    for (int i = start; i <= 9; i++)
    {
        // Choose i
        current[index] = i;

        // Recurse
        solve(i + 1, k, n - i, index + 1);

        // No explicit undo is needed here.
        // current[index] will simply be overwritten
        // by the next choice.
    }
}

int main()
{
    int k, n;

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Enter n: ");
    scanf("%d", &n);

    if (k < 1 || k > 9 || n < 1 || n > 45)
    {
        printf("No valid combinations.\n");
        return 0;
    }

    solve(1, k, n, 0);

    printf("Output: [");

    for (int i = 0; i < resultCount; i++)
    {
        printf("[");

        for (int j = 0; j < k; j++)
        {
            printf("%d", result[i][j]);

            if (j < k - 1)
                printf(",");
        }

        printf("]");

        if (i < resultCount - 1)
            printf(",");
    }

    printf("]\n");

    return 0;
}