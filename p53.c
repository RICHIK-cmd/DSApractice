#include <stdio.h>
#include <stdlib.h>

// Define Node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert at given position
struct Node* insertAtPosition(struct Node* head, int value, int position) {
    
    // Create new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // Case 1: Insert at beginning
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    int i = 1;

    // Traverse to (position - 1)
    while (i < position - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    // Invalid position
    if (temp == NULL) {
        printf("Invalid Position!\n");
        return head;
    }

    // Insert node
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Function to display list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value, position;

    // Create initial list
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);

        // Insert at end
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            struct Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Display original list
    printf("Original List:\n");
    display(head);

    // Take input for insertion
    printf("Enter value to insert: ");
    scanf("%d", &value);

    printf("Enter position: ");
    scanf("%d", &position);

    // Insert
    head = insertAtPosition(head, value, position);

    // Display updated list
    printf("Updated List:\n");
    display(head);

    return 0;
}