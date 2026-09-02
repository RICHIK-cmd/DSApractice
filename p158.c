#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int result[MAX][MAX];
int resultSize = 0;
int path[MAX];
int pathSize = 0;

/* Compare function for qsort */
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

/* Backtracking function */
void backtrack(int candidates[], int n, int start, int target)
{
    /* Target reached */
    if (target == 0)
    {
        for (int i = 0; i < pathSize; i++)
        {
            result[resultSize][i] = path[i];
        }

        resultSize++;
        return;
    }

    for (int i = start; i < n; i++)
    {
        /* Since array is sorted */
        if (candidates[i] > target)
            break;

        /* Skip duplicates at the same level */
        if (i > start && candidates[i] == candidates[i - 1])
            continue;

        /* Choose */
        path[pathSize] = candidates[i];
        pathSize++;

        /*
         * i + 1 means this element cannot
         * be selected again.
         */
        backtrack(candidates, n, i + 1, target - candidates[i]);

        /* Undo choice */
        pathSize--;
    }
}

int main()
{
    int n, target;
    int candidates[MAX];

    printf("Enter number of candidates: ");
    scanf("%d", &n);

    printf("Enter the candidates:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &candidates[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    /* Sort the array */
    qsort(candidates, n, sizeof(int), compare);

    /* Find combinations */
    backtrack(candidates, n, 0, target);

    /* Print result */
    printf("\nUnique combinations:\n");

    printf("[");

    for (int i = 0; i < resultSize; i++)
    {
        printf("[");

        for (int j = 0; j < MAX && result[i][j] != 0; j++)
        {
            if (j > 0)
                printf(",");

            printf("%d", result[i][j]);
        }

        printf("]");

        if (i < resultSize - 1)
            printf(",");
    }

    printf("]\n");

    return 0;
}