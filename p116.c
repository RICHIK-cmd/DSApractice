#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Create Sorted Circular Linked List
struct Node* createList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for(int i = 1; i <= n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter element %d: ", i);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

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

// Display Circular Linked List
void display(struct Node *head)
{
    if(head == NULL)
    {
        printf("List Empty\n");
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

// Insert into Sorted Circular Linked List
struct Node* insertSorted(struct Node *head, int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    // Empty list
    if(head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    // Insert before head
    if(value <= head->data)
    {
        struct Node *last = head;

        while(last->next != head)
            last = last->next;

        last->next = newNode;
        newNode->next = head;

        return newNode;
    }

    struct Node *temp = head;

    while(temp->next != head && temp->next->data < value)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Merge Two Sorted Circular Linked Lists
struct Node* mergeSorted(struct Node *head1, struct Node *head2)
{
    struct Node *merged = NULL;

    if(head1 != NULL)
    {
        struct Node *temp = head1;

        do
        {
            merged = insertSorted(merged, temp->data);
            temp = temp->next;
        }
        while(temp != head1);
    }

    if(head2 != NULL)
    {
        struct Node *temp = head2;

        do
        {
            merged = insertSorted(merged, temp->data);
            temp = temp->next;
        }
        while(temp != head2);
    }

    return merged;
}

int main()
{
    int n1, n2;

    printf("Enter number of nodes in First Sorted List: ");
    scanf("%d", &n1);

    struct Node *head1 = NULL;

    if(n1 > 0)
        head1 = createList(n1);

    printf("\nEnter number of nodes in Second Sorted List: ");
    scanf("%d", &n2);

    struct Node *head2 = NULL;

    if(n2 > 0)
        head2 = createList(n2);

    printf("\nFirst Sorted Circular List:\n");
    display(head1);

    printf("\nSecond Sorted Circular List:\n");
    display(head2);

    struct Node *merged = mergeSorted(head1, head2);

    printf("\nMerged Sorted Circular List:\n");
    display(merged);

    return 0;
}