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

// Count Nodes
int countNodes(struct Node *head)
{
    if(head == NULL)
        return 0;

    int count = 0;
    struct Node *temp = head;

    do
    {
        count++;
        temp = temp->next;
    }
    while(temp != head);

    return count;
}

// Split at Given Position
void splitAtPosition(struct Node *head, int pos,
                     struct Node **head1,
                     struct Node **head2)
{
    if(head == NULL)
    {
        *head1 = NULL;
        *head2 = NULL;
        return;
    }

    int count = countNodes(head);

    if(pos < 1 || pos >= count)
    {
        printf("Invalid Position!\n");
        *head1 = head;
        *head2 = NULL;
        return;
    }

    *head1 = head;

    struct Node *temp = head;

    // Reach the split position
    for(int i = 1; i < pos; i++)
        temp = temp->next;

    *head2 = temp->next;

    // Complete first circular list
    temp->next = *head1;

    // Find last node of second list
    struct Node *last = *head2;

    while(last->next != head)
        last = last->next;

    last->next = *head2;
}

int main()
{
    int n, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Invalid Input\n");
        return 0;
    }

    struct Node *head = createList(n);

    printf("\nOriginal Circular List:\n");
    display(head);

    printf("\nEnter position to split after: ");
    scanf("%d", &pos);

    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    splitAtPosition(head, pos, &head1, &head2);

    printf("\nFirst Circular List:\n");
    display(head1);

    printf("\nSecond Circular List:\n");
    display(head2);

    return 0;
}