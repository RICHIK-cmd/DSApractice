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

        printf("Enter data : ");
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
    }
    while(temp!=head);

    return count;
}

int main()
{
    struct Node *head;
    int n;

    printf("Enter number of nodes : ");
    scanf("%d",&n);

    head=createList(n);

    printf("Total Nodes = %d",countNodes(head));

    return 0;
}