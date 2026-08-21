#include <stdio.h>
#include <stdlib.h>

struct Node {
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

// Insert node at end
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

// Merge two sorted linked lists
struct Node* merge(struct Node *left, struct Node *right)
{
    // If one list is empty
    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    struct Node *result;

    // Choose smaller node
    if (left->data <= right->data)
    {
        result = left;
        result->next = merge(left->next, right);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// Merge Sort
struct Node* mergeSort(struct Node *head)
{
    // 0 or 1 node is already sorted
    if (head == NULL || head->next == NULL)
        return head;

    // Find middle
    struct Node *slow = head;
    struct Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split into two halves
    struct Node *right = slow->next;
    slow->next = NULL;

    struct Node *left = head;

    // Sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge sorted halves
    return merge(left, right);
}

// Display linked list
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

// Main
int main()
{
    struct Node *head = NULL;
    int n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head = insertEnd(head, data);
    }

    printf("Original list: ");
    display(head);

    head = mergeSort(head);

    printf("Sorted list: ");
    display(head);

    return 0;
}