#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int myAtoi(char s[])
{
    int i = 0;

    // Step 1: Skip leading spaces
    while (s[i] == ' ')
        i++;

    // Step 2: Determine the sign
    int sign = 1;

    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
    {
        i++;
    }

    // Step 3: Convert digits into integer
    long long ans = 0;

    while (s[i] >= '0' && s[i] <= '9')
    {
        int digit = s[i] - '0';

        ans = ans * 10 + digit;

        // Step 4: Handle overflow
        if (sign == 1 && ans > INT_MAX)
            return INT_MAX;

        if (sign == -1 && -ans < INT_MIN)
            return INT_MIN;

        i++;
    }

    // Step 5: Apply sign
    ans = sign * ans;

    return (int)ans;
}

int main()
{
    char s[1000];

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    // Remove newline added by fgets
    s[strcspn(s, "\n")] = '\0';

    int result = myAtoi(s);

    printf("Integer: %d\n", result);

    return 0;
}