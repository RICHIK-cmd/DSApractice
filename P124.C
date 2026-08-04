#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* insertEnd(struct Node *head,int data)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;

    if(head==NULL)
    {
        newNode->next=newNode;
        return newNode;
    }

    struct Node *temp=head;

    while(temp->next!=head)
        temp=temp->next;

    temp->next=newNode;
    newNode->next=head;

    return head;
}

void display(struct Node *head)
{
    if(head==NULL)
    {
        printf("Empty\n");
        return;
    }

    struct Node *temp=head;

    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);

    printf("\n");
}

struct Node* swapNodes(struct Node *head,int x,int y)
{
    if(head==NULL || x==y)
        return head;

    struct Node *prevX=NULL,*currX=head;

    do
    {
        if(currX->data==x)
            break;

        prevX=currX;
        currX=currX->next;

    }while(currX!=head);

    if(currX->data!=x)
        return head;

    struct Node *prevY=NULL,*currY=head;

    do
    {
        if(currY->data==y)
            break;

        prevY=currY;
        currY=currY->next;

    }while(currY!=head);

    if(currY->data!=y)
        return head;

    struct Node *last=head;

    while(last->next!=head)
        last=last->next;

    if(prevX!=NULL)
        prevX->next=currY;
    else
    {
        head=currY;
        last->next=head;
    }

    if(prevY!=NULL)
        prevY->next=currX;
    else
    {
        head=currX;
        last->next=head;
    }

    struct Node *temp=currX->next;
    currX->next=currY->next;
    currY->next=temp;

    return head;
}

int main()
{
    struct Node *head=NULL;

    int n,x,value,y;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&value);
        head=insertEnd(head,value);
    }

    display(head);

    printf("Enter two values to swap: ");
    scanf("%d%d",&x,&y);

    head=swapNodes(head,x,y);

    display(head);

    return 0;
}