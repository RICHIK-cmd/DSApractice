#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data)
{
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

// Segregate 0s, 1s and 2s
struct Node* segregate(struct Node *head)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    struct Node *temp = head;

    // Step 1: Count 0s, 1s and 2s
    while (temp != NULL)
    {
        if (temp->data == 0)
            count0++;
        else if (temp->data == 1)
            count1++;
        else
            count2++;

        temp = temp->next;
    }

    // Step 2: Overwrite nodes
    temp = head;

    while (temp != NULL)
    {
        if (count0 > 0)
        {
            temp->data = 0;
            count0--;
        }
        else if (count1 > 0)
        {
            temp->data = 1;
            count1--;
        }
        else
        {
            temp->data = 2;
            count2--;
        }

        temp = temp->next;
    }

    return head;
}

// Display
void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct Node *head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values (only 0, 1 and 2):\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("Original list: ");
    display(head);

    head = segregate(head);

    printf("\nSegregated list: ");
    display(head);

    return 0;
}