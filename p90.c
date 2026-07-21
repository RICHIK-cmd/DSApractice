#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode;
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
    if(head==NULL)
    {
        printf("List is Empty");
        return;
    }

    struct Node *temp=head;

    printf("List : ");

    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    while(temp!=head);

    printf("\n");
}

int main()
{
    struct Node *head;
    int n;

    printf("Enter number of nodes : ");
    scanf("%d",&n);

    head=createList(n);

    display(head);

    return 0;
}