#include <stdio.h>

int longestOnes(int a[], int n, int k)
{
    int start = 0, zeros = 0, count = 0, maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            zeros++;

        while (zeros > k)
        {
            if (a[start] == 0)
                zeros--;

            start++;
        }

        count = i - start + 1;

        if (count > maxLen)
            maxLen = count;
    }

    return maxLen;
}

int main()
{
    int n, k;

    printf("Enter array size: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter binary array elements (0 or 1): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Maximum consecutive ones = %d\n", longestOnes(a, n, k));

    return 0;
}