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

    if(newNode == NULL)
    {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }

    newNode->data = data;

    // First node
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

// Display Circular Linked List
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

// Rotate Clockwise by K Nodes
struct Node* rotateClockwise(struct Node *head, int k)
{
    if(head == NULL || head->next == head)
        return head;

    int n = countNodes(head);

    k = k % n;

    if(k == 0)
        return head;

    // Move to the new last node
    int steps = n - k;

    struct Node *temp = head;

    for(int i = 1; i < steps; i++)
        temp = temp->next;

    // New head
    head = temp->next;

    return head;
}

int main()
{
    struct Node *head = NULL;
    int n, value, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("List is Empty.\n");
        return 0;
    }

    printf("Enter %d elements:\n", n);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("\nOriginal Circular Linked List:\n");
    display(head);

    printf("\nEnter value of K: ");
    scanf("%d", &k);

    head = rotateClockwise(head, k);

    printf("\nCircular Linked List after Clockwise Rotation:\n");
    display(head);

    return 0;
}