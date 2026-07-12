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

void deleteByValue(struct Node **head,int key)
{
    struct Node *temp=*head;

    while(temp!=NULL && temp->data!=key)
        temp=temp->next;

    if(temp==NULL)
    {
        printf("Value not found.\n");
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
    int key;

    createList(&head);

    printf("Original List:\n");
    display(head);

    printf("Enter value to delete: ");
    scanf("%d",&key);

    deleteByValue(&head,key);

    printf("Updated List:\n");
    display(head);

    return 0;
}