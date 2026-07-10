#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int value){

    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=NULL;

    return newNode;
}

void insertEnd(struct Node **head,int value){

    struct Node *newNode=createNode(value);

    if(*head==NULL){
        *head=newNode;
        return;
    }

    struct Node *temp=*head;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newNode;
    newNode->prev=temp;
}

void display(struct Node *head){

    while(head!=NULL){
        printf("%d <-> ",head->data);
        head=head->next;
    }

    printf("NULL\n");
}

// Insert before given node value
void insertBeforeNode(struct Node **head,int key,int value){

    struct Node *temp=*head;

    while(temp!=NULL && temp->data!=key)
        temp=temp->next;

    if(temp==NULL){
        printf("Node not found\n");
        return;
    }

    struct Node *newNode=createNode(value);

    // If inserting before first node
    if(temp==*head){

        newNode->next=*head;
        (*head)->prev=newNode;
        *head=newNode;

        return;
    }

    newNode->prev=temp->prev;
    newNode->next=temp;

    temp->prev->next=newNode;
    temp->prev=newNode;
}

int main(){

    struct Node *head=NULL;

    insertEnd(&head,10);
    insertEnd(&head,20);
    insertEnd(&head,30);
    insertEnd(&head,40);

    printf("Original List:\n");
    display(head);

    int key,value;

    printf("Insert before node value: ");
    scanf("%d",&key);

    printf("Enter new value: ");
    scanf("%d",&value);

    insertBeforeNode(&head,key,value);

    printf("Updated List:\n");
    display(head);

    return 0;
}