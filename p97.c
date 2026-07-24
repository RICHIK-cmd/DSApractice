#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Create Circular Singly Linked List
struct Node *createList(int n)
{
    if (n <= 0)
        return NULL;

    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for (int i = 1; i <= n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    temp->next = head;

    return head;
}

// Display List
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while (temp != head);

    printf("\n");
}

// Count Nodes
int countNodes(struct Node *head)
{
    if (head == NULL)
        return 0;

    int count = 1;
    struct Node *temp = head;

    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// Insert at Given Position
struct Node *insertPosition(struct Node *head, int pos, int value)
{
    int count = countNodes(head);

    if (pos < 1 || pos > count + 1)
    {
        printf("Invalid Position!\n");
        return head;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    // Empty List
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    // Insert at Beginning
    if (pos == 1)
    {
        struct Node *last = head;

        while (last->next != head)
            last = last->next;

        newNode->next = head;
        last->next = newNode;

        return newNode;
    }

    // Insert at Other Positions
    struct Node *temp = head;

    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

int main()
{
    int n, pos, value;
    struct Node *head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("\nCurrent List: ");
    display(head);

    printf("Enter Position: ");
    scanf("%d", &pos);

    printf("Enter Value: ");
    scanf("%d", &value);

    head = insertPosition(head, pos, value);

    printf("\nUpdated List: ");
    display(head);

    return 0;
}