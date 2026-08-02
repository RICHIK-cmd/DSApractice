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

// Bubble Sort Circular Linked List
void sortList(struct Node *head)
{
    if(head == NULL || head->next == head)
        return;

    int swapped;
    struct Node *ptr1;
    struct Node *last = NULL;

    do
    {
        swapped = 0;
        ptr1 = head;

        while(ptr1->next != head && ptr1->next != last)
        {
            if(ptr1->data > ptr1->next->data)
            {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }

            ptr1 = ptr1->next;
        }

        last = ptr1;

    } while(swapped);
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

    // Check duplicate between last node and head
    if(curr->data == head->data)
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

    struct Node *head = createList(n);

    printf("\nOriginal Circular List:\n");
    display(head);

    // Sort the list
    sortList(head);

    printf("\nSorted Circular List:\n");
    display(head);

    // Remove duplicates
    head = removeDuplicates(head);

    printf("\nAfter Removing Duplicates:\n");
    display(head);

    return 0;
}