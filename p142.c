#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* insertEnd(struct Node *head, int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
        return newNode;

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

struct Node* deleteKey(struct Node *head, int key)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            struct Node *deleteNode = temp;

            // If deleting first node
            if (temp->prev == NULL)
            {
                head = temp->next;

                if (head != NULL)
                    head->prev = NULL;
            }
            else
            {
                temp->prev->next = temp->next;

                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
            }

            temp = temp->next;
            free(deleteNode);
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
}

void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d", temp->data);

        if (temp->next != NULL)
            printf(" <-> ");

        temp = temp->next;
    }
}

int main()
{
    struct Node *head = NULL;
    int n, data, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head = insertEnd(head, data);
    }

    printf("Enter key to delete: ");
    scanf("%d", &key);

    printf("Original list: ");
    display(head);

    head = deleteKey(head, key);

    printf("\nAfter deleting all occurrences of %d: ", key);
    display(head);

    return 0;
}