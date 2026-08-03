#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Insert at End
struct Node* insertEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if(head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    struct Node *temp = head;

    while(temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;

    return head;
}

// Display
void display(struct Node *head)
{
    if(head == NULL)
    {
        printf("List is Empty.\n");
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

// Move First Node to Last
struct Node* moveFirstLast(struct Node *head)
{
    if(head == NULL || head->next == head)
        return head;

    struct Node *first = head;
    struct Node *last = head;

    // Find the last node
    while(last->next != head)
        last = last->next;

    // New head will be the second node
    head = first->next;

    // Old last points to old first
    last->next = first;

    // Old first becomes the last node
    first->next = head;

    return head;
}

int main()
{
    struct Node *head = NULL;
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    printf("\nOriginal Circular Linked List:\n");
    display(head);

    head = moveFirstLast(head);

    printf("\nAfter Moving First Node to Last:\n");
    display(head);

    return 0;
}