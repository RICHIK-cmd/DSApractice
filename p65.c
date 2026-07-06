#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Insert node at the end
void insertEnd(struct Node **head, struct Node **tail, int value) {
    struct Node *newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

// Display the linked list
void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Delete the entire linked list
void deleteList(struct Node **head, struct Node **tail) {
    struct Node *temp;

    while (*head != NULL) {
        temp = *head;          // Store current node
        *head = (*head)->next; // Move head to next node
        free(temp);            // Free current node
    }

    *tail = NULL; // Tail should also become NULL
}

int main() {
    struct Node *head = NULL;
    struct Node *tail = NULL;

    // Creating the linked list
    insertEnd(&head, &tail, 10);
    insertEnd(&head, &tail, 20);
    insertEnd(&head, &tail, 30);
    insertEnd(&head, &tail, 40);
    insertEnd(&head, &tail, 50);

    printf("Original Linked List:\n");
    display(head);

    // Delete the entire list
    deleteList(&head, &tail);

    printf("\nAfter deleting the entire linked list:\n");
    display(head);

    return 0;
}