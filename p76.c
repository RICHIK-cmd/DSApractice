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
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=NULL;

    return newNode;
}

void createList(struct Node **head)
{
    int n,value;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    if(n<=0)
        return;

    printf("Enter node values:\n");

    scanf("%d",&value);

    *head=createNode(value);

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
    while(head)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

void deleteByPosition(struct Node **head,int pos)
{
    if(*head==NULL || pos<=0)
        return;

    struct Node *temp=*head;

    for(int i=1;i<pos && temp!=NULL;i++)
        temp=temp->next;

    if(temp==NULL)
    {
        printf("Invalid Position\n");
        return;
    }

    if(temp->prev!=NULL)
        temp->prev->next=temp->next;
    else
        *head=temp->next;

    if(temp->next!=NULL)
        temp->next->prev=temp->prev;

    free(temp);
}

int main()
{
    struct Node *head=NULL;
    int pos;

    createList(&head);

    printf("Original List:\n");
    display(head);

    printf("Enter position: ");
    scanf("%d",&pos);

    deleteByPosition(&head,pos);

    printf("Updated List:\n");
    display(head);

    return 0;
}