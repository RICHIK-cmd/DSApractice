#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for(int i = 1; i <= n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode->data = value;

        if(head == NULL)
        {
            head = temp = newNode;
            newNode->next = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
            temp->next = head;
        }
    }

    return head;
}

void display(struct Node *head)
{
    if(head == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("Circular Linked List: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != head);

    printf("\n");
}

struct Node* replaceAll(struct Node *head, int oldValue, int newValue)
{
    if(head == NULL)
    {
        printf("List is Empty.\n");
        return head;
    }

    int found = 0;
    struct Node *temp = head;

    do
    {
        if(temp->data == oldValue)
        {
            temp->data = newValue;
            found = 1;
        }

        temp = temp->next;

    }while(temp != head);

    if(found)
        printf("All Occurrences Replaced.\n");
    else
        printf("Value Not Found.\n");

    return head;
}

int main()
{
    int n, oldValue, newValue;
    struct Node *head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("\nBefore Replacement:\n");
    display(head);

    printf("\nEnter value to replace: ");
    scanf("%d", &oldValue);

    printf("Enter new value: ");
    scanf("%d", &newValue);

    head = replaceAll(head, oldValue, newValue);

    printf("\nAfter Replacement:\n");
    display(head);

    return 0;
}