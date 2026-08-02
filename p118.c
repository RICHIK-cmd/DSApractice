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

    if(temp != NULL)
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

// Remove Duplicates from Sorted Circular Linked List
struct Node* removeDuplicates(struct Node *head)
{
    if(head == NULL || head->next == head)
        return head;

    struct Node *curr = head;

    while(curr->next != head)
    {
        if(curr->data == curr->next->data)
        {
            struct Node *dup = curr->next;
            curr->next = dup->next;
            free(dup);
        }
        else
        {
            curr = curr->next;
        }
    }

    // Check first and last node
    if(curr->data == head->data && curr != head)
    {
        struct Node *dup = head;
        head = head->next;
        curr->next = head;
        free(dup);
    }

    return head;
}

int main()
{
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Invalid Input\n");
        return 0;
    }

    printf("Enter elements in sorted order:\n");

    struct Node *head = createList(n);

    printf("\nOriginal List:\n");
    display(head);

    head = removeDuplicates(head);

    printf("\nAfter Removing Duplicates:\n");
    display(head);

    return 0;
}