#include <stdio.h>
#include <string.h>

#define MOD 1000000007LL

char s[1000];
long long dp[1000];

int previousOccurrence(int pos)
{
    for (int j = pos - 1; j >= 0; j--)
    {
        if (s[j] == s[pos])
            return j;

    }

    return -1;
}

long long countSubsequences(int n)
{
    // Base case
    if (n == 0)
        return 1;

    // Already calculated
    if (dp[n] != -1)
        return dp[n];

    // Without worrying about duplicates:
    // every subsequence can either include
    // or exclude s[n-1]
    long long ans = (2 * countSubsequences(n - 1)) % MOD;

    // Find previous occurrence of current character
    int prev = previousOccurrence(n - 1);

    if (prev != -1)
    {
        // Remove duplicate subsequences
        ans = (ans - countSubsequences(prev) + MOD) % MOD;
    }

    dp[n] = ans;

    return ans;
}

int main()
{
    printf("Enter the string: ");
    scanf("%s", s);

    int n = strlen(s);

    for (int i = 0; i <= n; i++)
        dp[i] = -1;

    printf("Number of distinct subsequences = %lld\n",
           countSubsequences(n));

    return 0;
}