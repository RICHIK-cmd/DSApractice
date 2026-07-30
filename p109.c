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

        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode->data = value;

        if(head == NULL)
        {
            head = temp = newNode;
            newNode->next = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
            temp->next = head;
        }
    }

    return head;
}

void display(struct Node *head)
{
    if(head == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("Circular Linked List: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != head);

    printf("\n");
}

struct Node* reverseList(struct Node *head)
{
    if(head == NULL || head->next == head)
        return head;

    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;

    do
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    while(curr != head);

    head->next = prev;
    head = prev;

    return head;
}

int main()
{
    int n;
    struct Node *head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("\nBefore Reverse:\n");
    display(head);

    head = reverseList(head);

    printf("\nAfter Reverse:\n");
    display(head);

    return 0;
}