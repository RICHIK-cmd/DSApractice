#include <stdio.h>

void rotate(int matrix[][100], int n)
{
    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < n; i++)
    {
        int start = 0;
        int end = n - 1;

        while (start < end)
        {
            int temp = matrix[i][start];
            matrix[i][start] = matrix[i][end];
            matrix[i][end] = temp;

            start++;
            end--;
        }
    }
}

int main()
{
    int n;
    int matrix[100][100];

    // Input size
    printf("Enter size of matrix: ");
    scanf("%d", &n);

    // Input matrix
    printf("Enter matrix elements:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Rotate matrix
    rotate(matrix, n);

    // Print rotated matrix
    printf("Matrix after 90 degree clockwise rotation:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }

    return 0;
}