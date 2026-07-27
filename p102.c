#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createList(int n)
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
            head=temp=newNode;
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
        printf("List is Empty\n");
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

struct Node* deleteLast(struct Node *head)
{
    if(head==NULL)
        return NULL;

    if(head->next==head)
    {
        free(head);
        return NULL;
    }

    struct Node *prev=NULL,*curr=head;

    while(curr->next!=head)
    {
        prev=curr;
        curr=curr->next;
    }

    prev->next=head;
    free(curr);

    return head;
}

int main()
{
    int n;
    struct Node *head;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    head=createList(n);

    head=deleteLast(head);

    display(head);

    return 0;
}