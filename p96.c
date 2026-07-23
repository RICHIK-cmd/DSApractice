#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createList(int n)
{
    struct Node *head=NULL,*temp=NULL,*newNode;
    int value;

    for(int i=1;i<=n;i++)
    {
        newNode=(struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d",&value);

        newNode->data=value;

        if(head==NULL)
        {
            head=temp=newNode;
        }
        else
        {
            temp->next=newNode;
            temp=newNode;
        }
    }

    temp->next=head;
    return head;
}

void display(struct Node *head)
{
    struct Node *temp=head;

    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    while(temp!=head);

    printf("\n");
}

struct Node* insertEnd(struct Node *head,int value)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;

    if(head==NULL)
    {
        newNode->next=newNode;
        return newNode;
    }

    struct Node *last=head;

    while(last->next!=head)
        last=last->next;

    last->next=newNode;
    newNode->next=head;

    return head;
}

int main()
{
    int n,value;
    struct Node *head;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    head=createList(n);

    printf("Enter value: ");
    scanf("%d",&value);

    head=insertEnd(head,value);

    display(head);

    return 0;
}