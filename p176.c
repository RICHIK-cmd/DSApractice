#include <stdio.h>
#include <string.h>
#include <limits.h>

int get_maxmin(int freq[])
{
    int maxi = INT_MIN;
    int mini = INT_MAX;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > maxi)
            maxi = freq[i];

        // Ignore characters that are not present
        if (freq[i] != 0 && freq[i] < mini)
            mini = freq[i];
    }

    // If no character is present
    if (mini == INT_MAX)
        return 0;

    return maxi - mini;
}

int beautySum(char s[])
{
    int ans = 0;
    int n = strlen(s);

    // Choose the starting point of the substring
    for (int i = 0; i < n; i++)
    {
        int freq[26] = {0};

        // Choose the ending point of the substring
        for (int j = i; j < n; j++)
        {
            // Increase frequency of current character
            freq[s[j] - 'a']++;

            // Find beauty of current substring
            int beauty = get_maxmin(freq);

            // Add beauty to total
            ans += beauty;
        }
    }

    return ans;
}

int main()
{
    char s[1000];

    printf("Enter the string: ");
    scanf("%s", s);

    int result = beautySum(s);

    printf("Beauty Sum = %d\n", result);

    return 0;
}