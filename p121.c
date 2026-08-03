#include <stdio.h>
#include <stdlib.h>

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
        printf("List Empty\n");
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

int countNodes(struct Node *head)
{
    if(head==NULL)
        return 0;

    int count=0;
    struct Node *temp=head;

    do
    {
        count++;
        temp=temp->next;
    }while(temp!=head);

    return count;
}

struct Node* rotateAnti(struct Node *head,int k)
{
    if(head==NULL)
        return head;

    int n=countNodes(head);

    k=k%n;

    if(k==0)
        return head;

    struct Node *temp=head;

    for(int i=1;i<=k;i++)
        temp=temp->next;

    head=temp;

    return head;
}

int main()
{
    struct Node *head=NULL;
    int n,value,k;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&value);
        head=insertEnd(head,value);
    }

    display(head);

    printf("Enter K: ");
    scanf("%d",&k);

    head=rotateAnti(head,k);

    display(head);

    return 0;
}