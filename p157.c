#include <stdio.h>
#include <stdlib.h>

void solve(int candidates[], int n, int index, int target,
           int current[], int currentSize)
{
    // Target reached
    if (target == 0)
    {
        printf("[");
        for (int i = 0; i < currentSize; i++)
        {
            printf("%d", current[i]);
            if (i < currentSize - 1)
                printf(",");
        }
        printf("]\n");
        return;
    }

    // No more candidates
    if (index == n || target < 0)
        return;

    // INCLUDE current candidate
    if (candidates[index] <= target)
    {
        current[currentSize] = candidates[index];

        // Same index because we can reuse the same number
        solve(candidates, n, index, target - candidates[index],
              current, currentSize + 1);
    }

    // EXCLUDE current candidate
    solve(candidates, n, index + 1, target,
          current, currentSize);
}

int main()
{
    int n, target;

    printf("Enter number of candidates: ");
    scanf("%d", &n);

    int *candidates = malloc(n * sizeof(int));

    printf("Enter candidates: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &candidates[i]);

    printf("Enter target: ");
    scanf("%d", &target);

    int *current = malloc(target * sizeof(int));

    printf("Combinations:\n");

    solve(candidates, n, 0, target, current, 0);

    free(candidates);
    free(current);

    return 0;
}