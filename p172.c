#include <stdio.h>
#include <string.h>

// Function to get the value of a Roman symbol
int value(char c)
{
    switch (c)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

// Function to convert Roman numeral to integer
int romanToInt(char s[])
{
    int result = value(s[0]);

    for (int i = 1; i < strlen(s); i++)
    {
        if (value(s[i]) > value(s[i - 1]))
        {
            result -= 2 * value(s[i - 1]);
            result += value(s[i]);
        }
        else
        {
            result += value(s[i]);
        }
    }

    return result;
}

int main()
{
    char s[100];

    printf("Enter Roman numeral: ");
    scanf("%s", s);

    int result = romanToInt(s);

    printf("Integer value: %d\n", result);

    return 0;
}