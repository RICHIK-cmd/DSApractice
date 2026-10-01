#include <stdio.h>
#include <stdbool.h>

void setZeroes(int matrix[][100], int m, int n)
{
    bool firstRowZero = false;
    bool firstColZero = false;

    // Check if first row contains 0
    for (int j = 0; j < n; j++)
    {
        if (matrix[0][j] == 0)
        {
            firstRowZero = true;
            break;
        }
    }

    // Check if first column contains 0
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] == 0)
        {
            firstColZero = true;
            break;
        }
    }

    // Mark rows and columns using first row and first column
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set rows to zero
    for (int i = 1; i < m; i++)
    {
        if (matrix[i][0] == 0)
        {
            for (int j = 1; j < n; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Set columns to zero
    for (int j = 1; j < n; j++)
    {
        if (matrix[0][j] == 0)
        {
            for (int i = 1; i < m; i++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Set first row to zero
    if (firstRowZero)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[0][j] = 0;
        }
    }

    // Set first column to zero
    if (firstColZero)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    int m, n;
    int matrix[100][100];

    printf("Enter number of rows: ");
    scanf("%d", &m);

    printf("Enter number of columns: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    setZeroes(matrix, m, n);

    printf("\nMatrix after setting zeroes:\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}