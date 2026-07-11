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

void createList(struct Node **head)
{
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    if(n<=0)
        return;

    printf("Enter node values:\n");

    scanf("%d",&value);
    *head = createNode(value);

    struct Node *temp=*head;

    for(int i=2;i<=n;i++)
    {
        scanf("%d",&value);

        struct Node *newNode=createNode(value);

        temp->next=newNode;
        newNode->prev=temp;
        temp=newNode;
    }
}

void display(struct Node *head)
{
    if(head==NULL)
    {
        printf("List is empty.\n");
        return;
    }

    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

void deleteFirst(struct Node **head)
{
    if(*head==NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp=*head;

    *head=(*head)->next;

    if(*head!=NULL)
        (*head)->prev=NULL;

    free(temp);
}

int main()
{
    struct Node *head=NULL;

    createList(&head);

    printf("Original List:\n");
    display(head);

    deleteFirst(&head);

    printf("After deleting first node:\n");
    display(head);

    return 0;
}