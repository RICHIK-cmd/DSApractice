#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert at end (to create list)
void insertEnd(struct Node **head, int value) {

    struct Node *newNode = createNode(value);

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Display
void display(struct Node *head) {

    while(head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

// Insert at given position
void insertAtPosition(struct Node **head, int value, int pos) {

    struct Node *newNode = createNode(value);

    // Position 1
    if(pos == 1) {

        newNode->next = *head;

        if(*head != NULL)
            (*head)->prev = newNode;

        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    int i;

    for(i=1; i<pos-1 && temp!=NULL; i++)
        temp = temp->next;

    if(temp == NULL) {
        printf("Invalid Position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

int main() {

    struct Node *head = NULL;

    insertEnd(&head,10);
    insertEnd(&head,20);
    insertEnd(&head,30);
    insertEnd(&head,40);

    printf("Original List:\n");
    display(head);

    int value,pos;

    printf("Enter value: ");
    scanf("%d",&value);

    printf("Enter position: ");
    scanf("%d",&pos);

    insertAtPosition(&head,value,pos);

    printf("Updated List:\n");
    display(head);

    return 0;
}