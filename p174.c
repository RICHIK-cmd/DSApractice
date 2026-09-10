#include <stdio.h>
#include <string.h>

long long substrAtMostK(char s[], int k)
{
    int freq[26] = {0};
    int distinct = 0;
    int i = 0;
    long long ans = 0;

    for (int j = 0; s[j] != '\0'; j++)
    {
        // Add s[j] to the window
        int index = s[j] - 'a';

        if (freq[index] == 0)
            distinct++;

        freq[index]++;

        // If distinct characters exceed k,
        // move the left pointer
        while (distinct > k)
        {
            int leftIndex = s[i] - 'a';

            freq[leftIndex]--;

            if (freq[leftIndex] == 0)
                distinct--;

            i++;
        }

        // Number of valid substrings ending at j
        ans += j - i + 1;
    }

    return ans;
}

long long substrCount(char s[], int k)
{
    return substrAtMostK(s, k) - substrAtMostK(s, k - 1);
}

int main()
{
    char s[1000];
    int k;

    printf("Enter the string: ");
    scanf("%s", s);

    printf("Enter K: ");
    scanf("%d", &k);

    long long result = substrCount(s, k);

    printf("Number of substrings with exactly %d distinct characters: %lld\n",
           k, result);

    return 0;
}