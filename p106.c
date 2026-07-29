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

        printf("Enter value %d: ",i);
        scanf("%d",&value);

        newNode->data=value;

        if(head==NULL)
        {
            head=temp=newNode;
            newNode->next=head;
        }
        else
        {
            temp->next=newNode;
            temp=newNode;
            temp->next=head;
        }
    }

    return head;
}

void display(struct Node *head)
{
    if(head==NULL)
    {
        printf("List is Empty.\n");
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

struct Node* deleteEntireList(struct Node *head)
{
    if(head==NULL)
        return NULL;

    struct Node *temp=head->next;

    while(temp!=head)
    {
        struct Node *next=temp->next;
        free(temp);
        temp=next;
    }

    free(head);

    return NULL;
}

int main()
{
    int n;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    struct Node *head=createList(n);

    printf("Original List:\n");
    display(head);

    head=deleteEntireList(head);

    printf("After deleting entire list:\n");
    display(head);

    return 0;
}