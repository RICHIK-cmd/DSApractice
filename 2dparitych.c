#include <stdio.h>

int main() {
    int data[10][10], rowParity[10], colParity[10];
    int n, m, rows, i, j;

    printf("Enter total bits (n): ");
    scanf("%d", &n);

    printf("Enter bits per block (m): ");
    scanf("%d", &m);

    rows = n / m;

    printf("Enter data bits:\n");
    for(i = 0; i < rows; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &data[i][j]);

    // Row parity
    for(i = 0; i < rows; i++) {
        int sum = 0;
        for(j = 0; j < m; j++)
            sum += data[i][j];
        rowParity[i] = sum % 2;
    }

    // Column parity
    for(j = 0; j < m; j++) {
        int sum = 0;
        for(i = 0; i < rows; i++)
            sum += data[i][j];
        colParity[j] = sum % 2;
    }

    printf("\nTransmitted Data:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < m; j++)
            printf("%d ", data[i][j]);
        printf("| %d\n", rowParity[i]);
    }

    for(j = 0; j < m; j++)
        printf("%d ", colParity[j]);

    float efficiency = (float)n / (n + rows + m);
    printf("\nEfficiency = %.2f\n", efficiency);

    return 0;
}