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
    newNode->data = data;

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

// Move Last Node to First
struct Node* moveLastFirst(struct Node *head)
{
    if(head == NULL || head->next == head)
        return head;

    struct Node *prev = NULL;
    struct Node *last = head;

    // Find last and second-last node
    while(last->next != head)
    {
        prev = last;
        last = last->next;
    }

    // Remove last node from the end
    prev->next = head;

    // Find the current last node (which is now prev)
    last->next = head;

    // Update head
    head = last;

    // Complete the circle
    prev->next = head;

    return head;
}

int main()
{
    struct Node *head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("\nOriginal Circular Linked List:\n");
    display(head);

    head = moveLastFirst(head);

    printf("\nAfter Moving Last Node to First:\n");
    display(head);

    return 0;
}