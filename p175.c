#include <stdio.h>
#include <string.h>

void expandFromCenter(char s[], int start, int end,
                      int *ans_start, int *ans_end, int *maxLen)
{
    int n = strlen(s);

    while (start >= 0 && end < n && s[start] == s[end])
    {
        int currentLen = end - start + 1;

        if (currentLen > *maxLen)
        {
            *ans_start = start;
            *ans_end = end;
            *maxLen = currentLen;
        }

        start--;
        end++;
    }
}

void longestPalindrome(char s[], char ans[])
{
    int n = strlen(s);

    int maxLen = 0;
    int ans_start = -1;
    int ans_end = -1;

    for (int i = 0; i < n; i++)
    {
        // Odd length palindrome
        expandFromCenter(s, i, i,
                         &ans_start, &ans_end, &maxLen);

        // Even length palindrome
        expandFromCenter(s, i - 1, i,
                         &ans_start, &ans_end, &maxLen);
    }

    if (maxLen == 0)
    {
        ans[0] = '\0';
        return;
    }

    // Copy the longest palindrome into ans
    int j = 0;

    for (int i = ans_start; i <= ans_end; i++)
    {
        ans[j] = s[i];
        j++;
    }

    ans[j] = '\0';
}

int main()
{
    char s[1000];
    char ans[1000];

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    // Remove newline added by fgets
    s[strcspn(s, "\n")] = '\0';

    longestPalindrome(s, ans);

    printf("Longest palindromic substring: %s\n", ans);

    return 0;
}