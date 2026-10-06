#include <stdio.h>

int main()
{
    int n, m;

    // User input for rows and columns
    printf("Enter number of rows: ");
    scanf("%d", &n);

    printf("Enter number of columns: ");
    scanf("%d", &m);

    int matrix[n][m];

    // Input matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;

    printf("Spiral Order: ");

    while (top <= bottom && left <= right)
    {
        // Traverse top row: left -> right
        for (int i = left; i <= right; i++)
        {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // Traverse right column: top -> bottom
        for (int i = top; i <= bottom; i++)
        {
            printf("%d ", matrix[i][right]);
        }
        right--;

        // Traverse bottom row: right -> left
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // Traverse left column: bottom -> top
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }

    return 0;
}