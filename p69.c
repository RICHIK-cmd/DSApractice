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
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void createList(struct Node **head)
{
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        printf("Enter data: ");
        scanf("%d",&value);

        struct Node *newNode = createNode(value);

        if(*head==NULL)
        {
            *head=newNode;
        }
        else
        {
            struct Node *temp=*head;

            while(temp->next!=NULL)
            {
                temp=temp->next;
            }

            temp->next=newNode;
            newNode->prev=temp;
        }
    }
}

void display(struct Node *head)
{
    if(head==NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    printf("Forward: ");

    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }

    printf("\n");
}
void searchElement(struct Node *head,int key)
{
    int pos=1;

    while(head!=NULL)
    {
        if(head->data==key)
        {
            printf("Element found at position %d\n",pos);
            return;
        }

        head=head->next;
        pos++;
    }

    printf("Element not found.\n");
}
int main()
{
    struct Node *head=NULL;

    createList(&head);

    display(head);

    int key;

    printf("Enter element to search: ");
    scanf("%d",&key);

    searchElement(head,key);

    return 0;
}