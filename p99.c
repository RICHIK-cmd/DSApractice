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

// Insert Before a Given Node
struct Node *insertBefore(struct Node *head, int key, int value)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    // Insert before first node
    if (head->data == key)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;

        struct Node *last = head;

        while (last->next != head)
            last = last->next;

        newNode->next = head;
        last->next = newNode;

        return newNode;
    }

    struct Node *prev = head;
    struct Node *curr = head->next;

    while (curr != head)
    {
        if (curr->data == key)
        {
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

            newNode->data = value;
            newNode->next = curr;
            prev->next = newNode;

            return head;
        }

        prev = curr;
        curr = curr->next;
    }

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

    head = insertBefore(head, key, value);

    printf("\nUpdated List: ");
    display(head);

    return 0;
}