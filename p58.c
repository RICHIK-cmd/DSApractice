// Circular Linked List - Insertion at End and Display
#include <stdio.h>
#include <stdlib.h>

// Structure for node
struct Node {
    int data;
    struct Node *next;
};

// Global head pointer
struct Node *head = NULL;

// Function to insert node at the end
void insertEnd(int value) {
    
    // Create new node
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = value;

    // If list is empty
    if (head == NULL) {
        head = newNode;
        newNode->next = head; // Points to itself
    }
    else {
        struct Node *temp = head;

        // Traverse till last node
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode; // Last node points to new node
        newNode->next = head; // New node points to head
    }
}

// Function to display circular linked list
void display() {

    // Check if list is empty
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    printf("Circular Linked List: ");

    // Traverse and print nodes
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(Back to Head)\n");
}

// Main function
int main() {

    // Insert elements
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    // Display list
    display();

    return 0;
}