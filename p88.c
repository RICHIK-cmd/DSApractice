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

    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

struct Node* mergeLists(struct Node *head1, struct Node *head2)
{
    if(head1 == NULL)
        return head2;

    if(head2 == NULL)
        return head1;

    struct Node *head = NULL;
    struct Node *tail = NULL;

    while(head1 != NULL && head2 != NULL)
    {
        struct Node *newNode;

        if(head1->data <= head2->data)
        {
            newNode = createNode(head1->data);
            head1 = head1->next;
        }
        else
        {
            newNode = createNode(head2->data);
            head2 = head2->next;
        }

        if(head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    while(head1 != NULL)
    {
        struct Node *newNode = createNode(head1->data);

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;

        head1 = head1->next;
    }

    while(head2 != NULL)
    {
        struct Node *newNode = createNode(head2->data);

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;

        head2 = head2->next;
    }

    return head;
}

int main()
{
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *merged = NULL;

    int n1, n2, value, i;

    printf("Enter number of nodes in First Sorted List: ");
    scanf("%d", &n1);

    printf("Enter elements in sorted order:\n");

    for(i = 1; i <= n1; i++)
    {
        scanf("%d", &value);
        insertEnd(&head1, value);
    }

    printf("Enter number of nodes in Second Sorted List: ");
    scanf("%d", &n2);

    printf("Enter elements in sorted order:\n");

    for(i = 1; i <= n2; i++)
    {
        scanf("%d", &value);
        insertEnd(&head2, value);
    }

    printf("\nFirst List:\n");
    display(head1);

    printf("Second List:\n");
    display(head2);

    merged = mergeLists(head1, head2);

    printf("\nMerged Sorted List:\n");
    display(merged);

    return 0;
}