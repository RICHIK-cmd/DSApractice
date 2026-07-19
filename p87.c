#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void insertEnd(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);

    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void display(struct Node *head)
{
    if(head == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

void splitList(struct Node *head, struct Node **head1, struct Node **head2)
{
    if(head == NULL)
    {
        *head1 = NULL;
        *head2 = NULL;
        return;
    }

    struct Node *slow = head;
    struct Node *fast = head;

    // Find the middle node
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    *head1 = head;
    *head2 = slow->next;

    // Break the list into two parts
    if(slow->next != NULL)
    {
        slow->next->prev = NULL;
    }

    slow->next = NULL;
}

int main()
{
    struct Node *head = NULL;
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Enter value %d: ", i);
        scanf("%d", &value);

        insertEnd(&head, value);
    }

    printf("\nOriginal List:\n");
    display(head);

    splitList(head, &head1, &head2);

    printf("\nFirst Half:\n");
    display(head1);

    printf("Second Half:\n");
    display(head2);

    return 0;
}