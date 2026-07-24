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

    for (int i = 0; i < n; i++)
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

// Insert After a Given Node
struct Node *insertAfter(struct Node *head, int key, int value)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    struct Node *temp = head;

    do
    {
        if (temp->data == key)
        {
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;

            return head;
        }

        temp = temp->next;
    }
    while (temp != head);

    printf("Node not found.\n");

    return head;
}

int main()
{
    int n, key, value;
    struct Node *head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("\nCurrent List: ");
    display(head);

    printf("Enter key and value: ");
    scanf("%d %d", &key, &value);

    head = insertAfter(head, key, value);

    printf("\nUpdated List: ");
    display(head);

    return 0;
}