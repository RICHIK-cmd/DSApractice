
#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char s[])
{
    int ans = 0;
    int start = 0;
    int n = strlen(s);

    int freq[256] = {0};

    for (int i = 0; i < n; i++)
    {
        freq[(unsigned char)s[i]]++;

        while (freq[(unsigned char)s[i]] > 1)
        {
            freq[(unsigned char)s[start]]--;
            start++;
        }

        int windowSize = i - start + 1;

        if (windowSize > ans)
        {
            ans = windowSize;
        }
    }

    return ans;
}

int main()
{
    char s[] = "abcabcbb";

    printf("Length: %d\n", lengthOfLongestSubstring(s));

    return 0;
}
