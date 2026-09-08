#include <stdio.h>
#include <string.h>

void reverse(char str[], int start, int end)
{
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

void rotateString(char str[], int k)
{
    int n = strlen(str);

    // If k is greater than n
    k = k % n;

    // Step 1: Reverse first k characters
    reverse(str, 0, k - 1);

    // Step 2: Reverse remaining characters
    reverse(str, k, n - 1);

    // Step 3: Reverse the entire string
    reverse(str, 0, n - 1);
}

int main()
{
    char str[100];
    int k;

    printf("Enter the string: ");
    scanf("%s", str);

    printf("Enter number of rotations: ");
    scanf("%d", &k);

    rotateString(str, k);

    printf("Rotated string: %s\n", str);

    return 0;
}