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

// Insert at end
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

// Reverse linked list
struct Node* reverse(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next;

    while (curr != NULL)
    {
        next = curr->next;

        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

// Add 1 to the number
struct Node* addOne(struct Node *head)
{
    // Step 1: Reverse the list
    head = reverse(head);

    struct Node *temp = head;

    int carry = 1;

    // Step 2: Add 1
    while (temp != NULL && carry != 0)
    {
        int sum = temp->data + carry;

        temp->data = sum % 10;
        carry = sum / 10;

        temp = temp->next;
    }

    // Step 3: If carry is still left
    if (carry != 0)
    {
        struct Node *newNode = createNode(carry);

        struct Node *last = head;

        while (last->next != NULL)
            last = last->next;

        last->next = newNode;
    }

    // Step 4: Reverse again
    head = reverse(head);

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

    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    int n, data;

    printf("Enter number of digits: ");
    scanf("%d", &n);

    printf("Enter the digits:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head = insertEnd(head, data);
    }

    printf("Original number: ");
    display(head);

    head = addOne(head);

    printf("After adding 1: ");
    display(head);

    return 0;
}