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

struct Node* updateValue(struct Node *head, int oldValue, int newValue)
{
    if(head == NULL)
    {
        printf("List is Empty.\n");
        return head;
    }

    struct Node *temp = head;

    do
    {
        if(temp->data == oldValue)
        {
            temp->data = newValue;
            printf("Value Updated Successfully.\n");
            
        }

        temp = temp->next;

    }while(temp != head);

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

    printf("\nBefore Update:\n");
    display(head);

    printf("\nEnter value to update: ");
    scanf("%d", &oldValue);

    printf("Enter new value: ");
    scanf("%d", &newValue);

    head = updateValue(head, oldValue, newValue);

    printf("\nAfter Update:\n");
    display(head);

    return 0;
}