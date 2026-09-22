#include <stdio.h>

void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int contains(int arr[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
            return 1;
    }

    return 0;
}

int main()
{
    int n, m;

    printf("Enter size of first array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements of first array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &m);

    int b[m];

    printf("Enter elements of second array:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    int unionArr[n + m];
    int count = 0;

    // Add elements of first array
    for (int i = 0; i < n; i++)
    {
        if (!contains(unionArr, count, a[i]))
        {
            unionArr[count] = a[i];
            count++;
        }
    }

    // Add elements of second array
    for (int i = 0; i < m; i++)
    {
        if (!contains(unionArr, count, b[i]))
        {
            unionArr[count] = b[i];
            count++;
        }
    }

    // Sort union
    sort(unionArr, count);

    printf("\nUnion of the two arrays:\n");

    for (int i = 0; i < count; i++)
    {
        printf("%d ", unionArr[i]);
    }

    return 0;
}