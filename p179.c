#include <stdio.h>
#include <stdbool.h>

bool check(int nums[], int n)
{
    int cnt = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            cnt++;
        }
    }

    if (cnt == 0)
    {
        return true;
    }
    else if (cnt == 1 && nums[0] >= nums[n - 1])
    {
        return true;
    }

    return false;
}

int main()
{
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    if (check(nums, n))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}