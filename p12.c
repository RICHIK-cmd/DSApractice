//Given an array of stock prices where price is the price on day i, find the maximum profit from only ONE buy and ONE sell.//
#include <stdio.h>

int maxProfit(int prices[], int n) {
    int minPrice = prices[0];
    int maxProfit = 0;

    for(int i = 1; i < n; i++) {
        // Update minimum price
        if(prices[i] < minPrice) {
            minPrice = prices[i];
        }
        // Calculate profit
        else if(prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }

    return maxProfit;
}

int main() {
    int n;

    printf("Enter number of days: ");
    scanf("%d", &n);

    int prices[n];

    printf("Enter stock prices:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    int result = maxProfit(prices, n);

    printf("Maximum Profit = %d\n", result);

    return 0;
}