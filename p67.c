#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Create a new node
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

// Create Doubly Linked List
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

// Display 
void display(struct Node *head)
{
    if(head==NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    printf("List : ");

    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }

    printf("\n");
}



int countNodes(struct Node *head)
{
    int count=0;

    while(head!=NULL)
    {
        count++;
        head=head->next;
    }

    return count;
}


int main()
{
    struct Node *head=NULL;

    createList(&head);

    display(head);
    

    printf("Number of Nodes = %d\n",countNodes(head));

   

    return 0;
}