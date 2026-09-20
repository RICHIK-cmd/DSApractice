#include <stdio.h>

// Merge two sorted parts
void merge(int arr[], int low, int mid, int high)
{
    int temp[high - low + 1];

    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= high)
    {
        temp[k++] = arr[j++];
    }

    // Copy back
    for (i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = temp[k];
    }
}

// Merge Sort
void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
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

    // Maximum possible size of union = n + m
    int unionArr[n + m];

    // Copy first array
    for (int i = 0; i < n; i++)
    {
        unionArr[i] = a[i];
    }

    // Copy second array
    for (int i = 0; i < m; i++)
    {
        unionArr[n + i] = b[i];
    }

    int total = n + m;

    // Sort combined array
    mergeSort(unionArr, 0, total - 1);

    // Remove duplicates
    int uniqueCount = 0;

    for (int i = 0; i < total; i++)
    {
        if (uniqueCount == 0 ||
            unionArr[i] != unionArr[uniqueCount - 1])
        {
            unionArr[uniqueCount] = unionArr[i];
            uniqueCount++;
        }
    }

    printf("\nUnion of the two arrays:\n");

    for (int i = 0; i < uniqueCount; i++)
    {
        printf("%d ", unionArr[i]);
    }

    return 0;
}