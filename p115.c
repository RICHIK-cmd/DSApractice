#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Create Circular Linked List
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

// Concatenate Two Circular Linked Lists
struct Node* concatenate(struct Node *head1, struct Node *head2)
{
    // If first list is empty
    if(head1 == NULL)
        return head2;

    // If second list is empty
    if(head2 == NULL)
        return head1;

    struct Node *last1 = head1;
    struct Node *last2 = head2;

    // Find last node of first list
    while(last1->next != head1)
        last1 = last1->next;

    // Find last node of second list
    while(last2->next != head2)
        last2 = last2->next;

    // Connect first list to second
    last1->next = head2;

    // Connect second list back to first
    last2->next = head1;

    return head1;
}

int main()
{
    int n1, n2;

    printf("Enter number of nodes in First List: ");
    scanf("%d", &n1);

    struct Node *head1 = NULL;

    if(n1 > 0)
        head1 = createList(n1);

    printf("\nEnter number of nodes in Second List: ");
    scanf("%d", &n2);

    struct Node *head2 = NULL;

    if(n2 > 0)
        head2 = createList(n2);

    printf("\nFirst Circular List:\n");
    display(head1);

    printf("\nSecond Circular List:\n");
    display(head2);

    head1 = concatenate(head1, head2);

    printf("\nConcatenated Circular List:\n");
    display(head1);

    return 0;
}