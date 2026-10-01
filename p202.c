#include <stdio.h>
#include <stdlib.h>

#define SIZE 10007

// Hash table node
typedef struct Node
{
    int key;
    struct Node *next;
} Node;

// Hash function
int hash(int key)
{
    int index = key % SIZE;

    if (index < 0)
        index += SIZE;

    return index;
}

// Insert into hash set
void insert(Node *table[], int key)
{
    int index = hash(key);

    // Check if already exists
    Node *temp = table[index];

    while (temp != NULL)
    {
        if (temp->key == key)
            return;

        temp = temp->next;
    }

    // Insert new node
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->key = key;
    newNode->next = table[index];

    table[index] = newNode;
}

// Check whether key exists
int exists(Node *table[], int key)
{
    int index = hash(key);

    Node *temp = table[index];

    while (temp != NULL)
    {
        if (temp->key == key)
            return 1;

        temp = temp->next;
    }

    return 0;
}

// Find longest consecutive sequence
int longestConsecutive(int nums[], int n)
{
    Node *table[SIZE] = {NULL};

    // Insert all elements into hash set
    for (int i = 0; i < n; i++)
    {
        insert(table, nums[i]);
    }

    int ans = 0;

    // Check every element
    for (int i = 0; i < n; i++)
    {
        int start = nums[i];

        // If start - 1 does not exist,
        // then start is the beginning
        // of a consecutive sequence
        if (!exists(table, start - 1))
        {
            int length = 1;
            int current = start;

            // Keep checking current + 1
            while (exists(table, current + 1))
            {
                current++;
                length++;
            }

            if (length > ans)
            {
                ans = length;
            }
        }
    }

    return ans;
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *nums = (int *)malloc(n * sizeof(int));

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int result = longestConsecutive(nums, n);

    printf("Length of longest consecutive sequence = %d\n", result);

    free(nums);

    return 0;
}