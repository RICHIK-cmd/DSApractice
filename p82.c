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

    printf("Doubly Linked List: ");

    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

void updateNode(struct Node *head, int oldValue, int newValue)
{
    while(head != NULL)
    {
        if(head->data == oldValue)
        {
            head->data = newValue;
            
            printf("Node updated successfully.\n");
            
        }
        head = head->next;

        
    }

    printf("Value not found in the list.\n");
}

int main()
{
    struct Node *head = NULL;

    int n, value, i;
    int oldValue, newValue;

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

    printf("\nEnter value to update: ");
    scanf("%d", &oldValue);

    printf("Enter new value: ");
    scanf("%d", &newValue);

    updateNode(head, oldValue, newValue);

    printf("\nUpdated List:\n");
    display(head);

    return 0;
}