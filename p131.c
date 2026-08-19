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

// Create linked list using user input
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

// Remove Nth node from end
struct Node* removeNthFromEnd(struct Node *head, int n)
{
    struct Node *dummy = (struct Node*)malloc(sizeof(struct Node));

    dummy->next = head;

    struct Node *slow = dummy;
    struct Node *fast = dummy;

    // Move fast n+1 steps ahead
    for (int i = 0; i <= n; i++)
    {
        fast = fast->next;
    }

    // Move both pointers
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Delete the required node
    struct Node *temp = slow->next;

    slow->next = slow->next->next;

    free(temp);

    // Update head
    head = dummy->next;

    free(dummy);

    return head;
}

int main()
{
    struct Node *head = NULL;

    int size;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &size);

    head = createList(size);

    printf("\nOriginal Linked List:\n");
    display(head);

    printf("\nEnter n (node to remove from end): ");
    scanf("%d", &n);

    if (n < 1 || n > size)
    {
        printf("Invalid value of n!\n");
        return 0;
    }

    head = removeNthFromEnd(head, n);

    printf("\nLinked List after removing %dth node from end:\n", n);
    display(head);

    return 0;
}