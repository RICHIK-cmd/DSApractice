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

// Reverse nodes k at a time
struct Node* reverseKGroup(struct Node *head, int k)
{
    if (head == NULL)
        return NULL;

    // Check whether at least k nodes are present
    struct Node *temp = head;

    for (int i = 0; i < k; i++)
    {
        if (temp == NULL)
            return head;

        temp = temp->next;
    }

    // Reverse first k nodes
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;

    for (int i = 0; i < k; i++)
    {
        next = curr->next;

        curr->next = prev;

        prev = curr;
        curr = next;
    }

    // head is now the last node of the reversed group
    // curr points to the remaining list
    head->next = reverseKGroup(curr, k);

    // prev is the new head of this reversed group
    return prev;
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

    printf("Enter elements: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head = insertEnd(head, data);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    if (k <= 0)
    {
        printf("k must be greater than 0.\n");
        return 0;
    }

    printf("Original list: ");
    display(head);

    head = reverseKGroup(head, k);

    printf("List after reversing k nodes: ");
    display(head);

    return 0;
}