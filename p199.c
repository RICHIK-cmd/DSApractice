#include <stdio.h>
#include <stdlib.h>

void rearrangeArray(int nums[], int n)
{
    int pos = 0;
    int neg = 1;

    int *ans = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            ans[pos] = nums[i];
            pos += 2;
        }
        else
        {
            ans[neg] = nums[i];
            neg += 2;
        }
    }

    for (int i = 0; i < n; i++)
    {
        nums[i] = ans[i];
    }

    free(ans);
}

int main()
{
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    if (n % 2 != 0)
    {
        printf("Array size must be even.\n");
        return 0;
    }

    int nums[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    rearrangeArray(nums, n);

    printf("Rearranged array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}