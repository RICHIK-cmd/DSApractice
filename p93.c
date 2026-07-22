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

int findMax(struct Node *head)
{
    if(head==NULL)
        return -1;

    int max=head->data;

    struct Node *temp=head->next;

    while(temp!=head)
    {
        if(temp->data>max)
            max=temp->data;

        temp=temp->next;
    }

    return max;
}

int main()
{
    struct Node *head;
    int n;

    printf("Enter number of nodes : ");
    scanf("%d",&n);

    head=createList(n);

    printf("Maximum Element = %d",findMax(head));

    return 0;
}