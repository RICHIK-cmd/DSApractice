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

// Create linked list
struct Node* createList(int n)
{
    struct Node *head = NULL;
    struct Node *temp = NULL;

    for (int i = 1; i <= n; i++)
    {
        int data;

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        struct Node *newNode = createNode(data);

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

// Display linked list
void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d", temp->data);

        if (temp->next != NULL)
            printf(" -> ");

        temp = temp->next;
    }

    printf(" -> NULL\n");
}

// Delete middle node
struct Node* deleteMiddle(struct Node *head)
{
    // If list has only one node
    if (head == NULL || head->next == NULL)
    {
        free(head);
        return NULL;
    }

    struct Node *slow = head;
    struct Node *fast = head;
    struct Node *prev = NULL;

    // Find middle node
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Delete middle node
    prev->next = slow->next;

    free(slow);

    return head;
}

int main()
{
    struct Node *head = NULL;

    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of nodes!\n");
        return 0;
    }

    head = createList(n);

    printf("\nOriginal Linked List:\n");
    display(head);

    head = deleteMiddle(head);

    printf("\nAfter deleting middle node:\n");
    display(head);

    return 0;
}