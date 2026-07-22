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

void search(struct Node *head,int key)
{
    if(head==NULL)
    {
        printf("List Empty");
        return;
    }

    struct Node *temp=head;
    int pos=1;

    do
    {
        if(temp->data==key)
        {
            printf("Element Found at Position %d",pos);
            return;
        }

        temp=temp->next;
        pos++;

    }while(temp!=head);

    printf("Element Not Found");
}

int main()
{
    struct Node *head;
    int n,key;

    printf("Enter number of nodes : ");
    scanf("%d",&n);

    head=createList(n);

    printf("Enter element to search : ");
    scanf("%d",&key);

    search(head,key);

    return 0;
}