#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for(int i = 1; i <= n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &value);

        newNode->data = value;

        if(head == NULL)
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

void display(struct Node *head)
{
    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    struct Node *temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != head);

    printf("\n");
}

struct Node* deleteFirst(struct Node *head)
{
    if(head == NULL)
    {
        printf("List is Empty\n");
        return NULL;
    }

    // Only one node
    if(head->next == head)
    {
        free(head);
        return NULL;
    }

    struct Node *last = head;

    while(last->next != head)
        last = last->next;

    struct Node *temp = head;

    head = head->next;
    last->next = head;

    free(temp);

    return head;
}

int main()
{
    struct Node *head;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("\nOriginal List:\n");
    display(head);

    head = deleteFirst(head);

    printf("\nAfter Deleting First Node:\n");
    display(head);

    return 0;
}