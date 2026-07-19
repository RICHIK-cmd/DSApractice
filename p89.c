#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert node at end
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

// Display the DLL
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

// Concatenate two DLLs
void mergeLists(struct Node **head1, struct Node *head2)
{
    if(*head1 == NULL)
    {
        *head1 = head2;
        return;
    }

    if(head2 == NULL)
        return;

    struct Node *temp = *head1;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    head2->prev = temp;
}

// Sort DLL using Bubble Sort
void sortDLL(struct Node *head)
{
    if(head == NULL)
        return;

    int swapped;
    struct Node *ptr;
    struct Node *last = NULL;

    do
    {
        swapped = 0;
        ptr = head;

        while(ptr->next != last)
        {
            if(ptr->data > ptr->next->data)
            {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;

                swapped = 1;
            }

            ptr = ptr->next;
        }

        last = ptr;

    } while(swapped);
}

int main()
{
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    int n1, n2, value, i;

    printf("Enter number of nodes in First List: ");
    scanf("%d", &n1);

    for(i = 1; i <= n1; i++)
    {
        printf("Enter value %d: ", i);
        scanf("%d", &value);

        insertEnd(&head1, value);
    }

    printf("\nEnter number of nodes in Second List: ");
    scanf("%d", &n2);

    for(i = 1; i <= n2; i++)
    {
        printf("Enter value %d: ", i);
        scanf("%d", &value);

        insertEnd(&head2, value);
    }

    printf("\nFirst List:\n");
    display(head1);

    printf("Second List:\n");
    display(head2);

    mergeLists(&head1, head2);

    printf("\nMerged List:\n");
    display(head1);

    sortDLL(head1);

    printf("\nSorted Merged List:\n");
    display(head1);

    return 0;
}