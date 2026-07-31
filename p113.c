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

// Split into Two Equal Halves
void splitHalf(struct Node *head, struct Node **head1, struct Node **head2)
{
    if(head == NULL)
    {
        *head1 = NULL;
        *head2 = NULL;
        return;
    }

    struct Node *slow = head;
    struct Node *fast = head;

    while(fast->next != head &&
          fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Even number of nodes
    if(fast->next->next == head)
        fast = fast->next;

    *head1 = head;

    if(head->next != head)
        *head2 = slow->next;

    // Complete first list
    slow->next = *head1;

    // Complete second list
    fast->next = *head2;
}

int main()
{
    int n;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    if(n<=0)
    {
        printf("Invalid Input\n");
        return 0;
    }

    struct Node *head = createList(n);

    printf("\nOriginal Circular List:\n");
    display(head);

    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    splitHalf(head,&head1,&head2);

    printf("\nFirst Half:\n");
    display(head1);

    printf("\nSecond Half:\n");
    display(head2);

    return 0;
}