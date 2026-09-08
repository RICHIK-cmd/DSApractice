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

void leftRotate(char str[], int k)
{
    int n = strlen(str);

    k = k % n;

    // Reverse first k characters
    reverse(str, 0, k - 1);

    // Reverse remaining characters
    reverse(str, k, n - 1);

    // Reverse entire string
    reverse(str, 0, n - 1);
}

void rightRotate(char str[], int k)
{
    int n = strlen(str);

    k = k % n;

    // Reverse entire string
    reverse(str, 0, n - 1);

    // Reverse first k characters
    reverse(str, 0, k - 1);

    // Reverse remaining characters
    reverse(str, k, n - 1);
}

int main()
{
    char str[100];
    int k;
    char choice;

    printf("Enter string: ");
    scanf("%s", str);

    printf("Enter number of rotations: ");
    scanf("%d", &k);

    printf("Enter L for left rotation or R for right rotation: ");
    scanf(" %c", &choice);

    if (choice == 'L' || choice == 'l')
    {
        leftRotate(str, k);
    }
    else if (choice == 'R' || choice == 'r')
    {
        rightRotate(str, k);
    }
    else
    {
        printf("Invalid choice\n");
        return 0;
    }

    printf("Rotated string: %s\n", str);

    return 0;
}