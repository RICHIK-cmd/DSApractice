#include <stdio.h>

void leaders(int a[], int n)
{
    int ans[n];
    int count = 0;

    // Rightmost element is always a leader
    int maxi = a[n - 1];
    ans[count++] = maxi;

    // Traverse from right to left
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] >= maxi)
        {
            ans[count++] = a[i];
            maxi = a[i];
        }
    }

    // Print in correct left-to-right order
    printf("Leaders: ");

    for (int i = count - 1; i >= 0; i--)
    {
        printf("%d ", ans[i]);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    leaders(a, n);

    return 0;
}