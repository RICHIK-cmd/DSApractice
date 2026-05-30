#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to reverse linked list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *current = head, *nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next; // store next node
        current->next = prev;     // reverse link
        prev = current;           // move prev
        current = nextNode;       // move current
    }

    return prev;
}

// Function to print linked list
void printList(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {

    // Creating linked list: 1->2->3->4->5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original Linked List:\n");
    printList(head);

    head = reverseList(head);

    printf("Reversed Linked List:\n");
    printList(head);

    return 0;
}