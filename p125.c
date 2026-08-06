#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Insert at End (Singly Linked List)
struct Node* insertEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL)
        return newNode;

    struct Node *temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

// Convert Singly Linked List to Circular Linked List
struct Node* convertToCircular(struct Node *head)
{
    if(head == NULL)
        return NULL;

    struct Node *temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = head;

    return head;
}

// Display Circular Linked List
void displayCircular(struct Node *head)
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
    } while(temp != head);

    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    head = convertToCircular(head);

    printf("Circular Linked List:\n");
    displayCircular(head);

    return 0;
}