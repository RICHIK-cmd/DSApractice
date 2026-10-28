
#include <stdio.h>
#include <string.h>

int characterReplacement(char s[], int k)
{
    int n = strlen(s);
    int ans = 0;

    // Try each uppercase English letter
    for (char ltr = 'A'; ltr <= 'Z'; ltr++)
    {
        int start = 0;
        int ltrCnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == ltr)
                ltrCnt++;

            // Shrink the window if replacements exceed k
            while ((i - start + 1) - ltrCnt > k)
            {
                if (s[start] == ltr)
                    ltrCnt--;

                start++;
            }

            int len = i - start + 1;

            if (len > ans)
                ans = len;
        }
    }

    return ans;
}

int main()
{
    char s[1000];
    int k;

    printf("Enter an uppercase string: ");
    scanf("%999s", s);

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Longest substring length: %d\n",
           characterReplacement(s, k));

    return 0;
}
