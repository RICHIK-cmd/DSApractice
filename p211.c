
#include <stdio.h>

int totalFruits(int fruits[], int n)
{
    int start = 0, ans = 0;
    int type1 = -1, type2 = -1;
    int count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (fruits[i] == type1)
        {
            count1++;
        }
        else if (fruits[i] == type2)
        {
            count2++;
        }
        else
        {
            while (count1 > 0 && count2 > 0)
            {
                if (fruits[start] == type1)
                    count1--;
                else if (fruits[start] == type2)
                    count2--;

                start++;
            }

            if (count1 == 0)
            {
                type1 = fruits[i];
                count1 = 1;
            }
            else
            {
                type2 = fruits[i];
                count2 = 1;
            }
        }

        if (i - start + 1 > ans)
            ans = i - start + 1;
    }

    return ans;
}

int main()
{
    int n;

    printf("Enter the number of trees: ");
    scanf("%d", &n);

    int fruits[n];

    printf("Enter the fruit types: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &fruits[i]);
    }

    printf("Maximum fruits collected: %d\n", totalFruits(fruits, n));

    return 0;
}
