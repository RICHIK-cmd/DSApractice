#include <stdio.h>

int maxProfit(int prices[], int n)
{
    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++)
    {
        // Calculate profit if we sell today
        int profit = prices[i] - minPrice;

        // Update maximum profit
        if (profit > maxProfit)
        {
            maxProfit = profit;
        }

        // Update minimum buying price
        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
        }
    }

    return maxProfit;
}

int main()
{
    int n;

    printf("Enter number of days: ");
    scanf("%d", &n);

    int prices[n];

    printf("Enter stock prices:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &prices[i]);
    }

    int result = maxProfit(prices, n);

    printf("Maximum Profit = %d\n", result);

    return 0;
}