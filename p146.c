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
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

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

// Rotate linked list to the right by k places
struct Node* rotateRight(struct Node *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Find length and last node
    int length = 1;
    struct Node *tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
        length++;
    }

    // Avoid unnecessary rotations
    k = k % length;

    if (k == 0)
        return head;

    // Make the list circular
    tail->next = head;

    // Find the new tail
    int steps = length - k - 1;

    struct Node *newTail = head;

    for (int i = 0; i < steps; i++)
        newTail = newTail->next;

    // New head is after new tail
    struct Node *newHead = newTail->next;

    // Break the circle
    newTail->next = NULL;

    return newHead;
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

int main()
{
    struct Node *head = NULL;
    int n, data, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head = insertEnd(head, data);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Original list: ");
    display(head);

    head = rotateRight(head, k);

    printf("List after rotating right by %d places: ", k);
    display(head);

    return 0;
}