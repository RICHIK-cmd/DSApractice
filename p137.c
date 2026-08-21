#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data)
{
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Insert node at the end
struct Node* insertEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

// Find the last node
struct Node* getTail(struct Node *head)
{
    while (head != NULL && head->next != NULL)
        head = head->next;

    return head;
}

// Partition the list
struct Node* partition(struct Node *head,
                       struct Node *end,
                       struct Node **newHead,
                       struct Node **newEnd)
{
    struct Node *pivot = end;
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *tail = pivot;

    *newHead = NULL;

    while (curr != pivot)
    {
        if (curr->data < pivot->data)
        {
            // First smaller element becomes new head
            if (*newHead == NULL)
                *newHead = curr;

            prev = curr;
            curr = curr->next;
        }
        else
        {
            // Remove current from its position
            if (prev != NULL)
                prev->next = curr->next;

            // Move current to the end
            tail->next = curr;
            tail = curr;

            curr = curr->next;
            tail->next = NULL;
        }
    }

    // If no smaller element exists,
    // pivot becomes the new head
    if (*newHead == NULL)
        *newHead = pivot;

    *newEnd = tail;

    return pivot;
}

// Recursive Quick Sort
struct Node* quickSortRec(struct Node *head,
                          struct Node *end)
{
    // Empty list or one node
    if (head == NULL || head == end)
        return head;

    struct Node *newHead = NULL;
    struct Node *newEnd = NULL;

    // Partition the list
    struct Node *pivot =
        partition(head, end, &newHead, &newEnd);

    // Sort the left part
    if (newHead != pivot)
    {
        struct Node *temp = newHead;

        // Find node just before pivot
        while (temp->next != pivot)
            temp = temp->next;

        // Separate left part
        temp->next = NULL;

        // Sort left part
        newHead = quickSortRec(newHead, temp);

        // Connect sorted left part to pivot
        temp = getTail(newHead);
        temp->next = pivot;
    }

    // Sort the right part
    pivot->next =
        quickSortRec(pivot->next, newEnd);

    return newHead;
}

// Main Quick Sort function
struct Node* quickSort(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *end = getTail(head);

    return quickSortRec(head, end);
}

// Display the list
void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Main function
int main()
{
    struct Node *head = NULL;
    int n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head = insertEnd(head, data);
    }

    printf("\nOriginal list: ");
    display(head);

    head = quickSort(head);

    printf("Sorted list: ");
    display(head);

    return 0;
}