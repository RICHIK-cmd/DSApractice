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

int countNodes(struct Node *head)
{
    if(head == NULL)
        return 0;

    int count = 0;
    struct Node *temp = head;

    do
    {
        count++;
        temp = temp->next;
    }
    while(temp != head);

    return count;
}

void findNthBeginning(struct Node *head, int pos)
{
    if(head == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    int count = countNodes(head);

    if(pos < 1 || pos > count)
    {
        printf("Invalid Position.\n");
        return;
    }

    struct Node *temp = head;

    for(int i = 1; i < pos; i++)
        temp = temp->next;

    printf("%dth Node = %d\n", pos, temp->data);
}

int main()
{
    int n, pos;
    struct Node *head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    display(head);

    printf("Enter Position: ");
    scanf("%d", &pos);

    findNthBeginning(head, pos);

    return 0;
}