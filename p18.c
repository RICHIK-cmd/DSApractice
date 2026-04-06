#include <stdio.h>

int productDigits(int n) {
    if(n == 0) return 1;   // base case

    int digit = 0;

    // while loop used to extract last digit
    while(n > 0) {
        digit = n % 10;
        break;   // take only last digit once
    }

    return digit * productDigits(n / 10);
}

int main() {
    int n = 1234;
    printf("Product = %d", productDigits(n));
    return 0;
}