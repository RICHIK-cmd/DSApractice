#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void insertEnd(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);

    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void display(struct Node *head)
{
    if(head == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    printf("Doubly Linked List: ");

    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

void removeDuplicates(struct Node *head)
{
    if(head == NULL)
        return;

    struct Node *current = head;

    while(current != NULL && current->next != NULL)
    {
        if(current->data == current->next->data)
        {
            struct Node *duplicate = current->next;

            current->next = duplicate->next;

            if(duplicate->next != NULL)
                duplicate->next->prev = current;

            free(duplicate);
        }
        else
        {
            current = current->next;
        }
    }
}

int main()
{
    struct Node *head = NULL;

    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements in sorted order:\n");

    for(i = 1; i <= n; i++)
    {
        printf("Enter value %d: ", i);
        scanf("%d", &value);

        insertEnd(&head, value);
    }

    printf("\nOriginal List:\n");
    display(head);

    removeDuplicates(head);

    printf("\nList after removing duplicates:\n");
    display(head);

    return 0;
}