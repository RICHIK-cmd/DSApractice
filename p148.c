#include <stdio.h>

#define MOD 1000000007LL

long long power(long long base, long long exponent)
{
    long long result = 1;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % MOD;
        }

        base = (base * base) % MOD;
        exponent = exponent / 2;
    }

    return result;
}

long long countGoodStrings(long long n)
{
    long long evenPositions = (n + 1) / 2;
    long long oddPositions = n / 2;

    long long evenWays = power(5, evenPositions);
    long long oddWays = power(4, oddPositions);

    return (evenWays * oddWays) % MOD;
}

int main()
{
    long long n;

    printf("Enter n: ");
    scanf("%lld", &n);

    printf("Number of good digit strings = %lld\n", countGoodStrings(n));

    return 0;
}