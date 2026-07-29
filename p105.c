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

struct Node* deleteAllOccurrences(struct Node *head,int value)
{
    if(head==NULL)
        return NULL;

    while(head!=NULL && head->data==value)
    {
        if(head->next==head)
        {
            free(head);
            return NULL;
        }

        struct Node *last=head;

        while(last->next!=head)
            last=last->next;

        struct Node *temp=head;
        head=head->next;
        last->next=head;

        free(temp);
    }

    if(head==NULL)
        return NULL;

    struct Node *curr=head;

    while(curr->next!=head)
    {
        if(curr->next->data==value)
        {
            struct Node *temp=curr->next;
            curr->next=temp->next;
            free(temp);
        }
        else
            curr=curr->next;
    }

    return head;
}

int main()
{
    int n,value;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    struct Node *head=createList(n);

    printf("Original List:\n");
    display(head);

    printf("Enter value to delete: ");
    scanf("%d",&value);

    head=deleteAllOccurrences(head,value);

    printf("Updated List:\n");
    display(head);

    return 0;
}