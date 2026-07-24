#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void display(struct Node *head)
{
    if(head==NULL)
        return;

    struct Node *temp=head;

    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    while(temp!=head);

    printf("\n");
}

struct Node* insertSorted(struct Node *head,int value)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;

    if(head==NULL)
    {
        newNode->next=newNode;
        return newNode;
    }

    if(value<head->data)
    {
        struct Node *last=head;

        while(last->next!=head)
            last=last->next;

        newNode->next=head;
        last->next=newNode;

        return newNode;
    }

    struct Node *temp=head;

    while(temp->next!=head && temp->next->data<value)
        temp=temp->next;

    newNode->next=temp->next;
    temp->next=newNode;

    return head;
}

int main()
{
    struct Node *head=NULL;

    head=insertSorted(head,10);
    head=insertSorted(head,20);
    head=insertSorted(head,30);
    head=insertSorted(head,40);

    head=insertSorted(head,25);

    display(head);

    return 0;
}