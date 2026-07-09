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

    if(newNode == NULL)
    {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void createList(struct Node **head)
{
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        printf("Enter data: ");
        scanf("%d",&value);

        struct Node *newNode = createNode(value);

        if(*head==NULL)
        {
            *head=newNode;
        }
        else
        {
            struct Node *temp=*head;

            while(temp->next!=NULL)
            {
                temp=temp->next;
            }

            temp->next=newNode;
            newNode->prev=temp;
        }
    }
}

void display(struct Node *head)
{
    if(head==NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    printf("Forward: ");

    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }

    printf("\n");
}

void insertBeginning(struct Node **head,int value)
{
    struct Node *newNode=createNode(value);

    if(*head==NULL)
    {
        *head=newNode;
        return;
    }

    newNode->next=*head;
    (*head)->prev=newNode;
    *head=newNode;
}

void insertEnd(struct Node **head,int value)
{
    struct Node *newNode=createNode(value);

    if(*head==NULL)
    {
        *head=newNode;
        return;
    }

    struct Node *temp=*head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newNode;
    newNode->prev=temp;
}

int main()
{
    struct Node *head=NULL;

    createList(&head);

    display(head);

    int value;

    printf("Enter value to insert at beginning: ");
    scanf("%d",&value);

    insertBeginning(&head,value);

    display(head);

    printf("Enter value to insert at end: ");
    scanf("%d",&value);

    insertEnd(&head,value);

    display(head);

    return 0;
}