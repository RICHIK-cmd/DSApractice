#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node *head, int value) {
    struct Node *newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Delete node with given value
struct Node* deleteNode(struct Node *head, int value) {
    struct Node *temp = head, *prev = NULL;

    // Empty list
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    // Delete head node
    if (head->data == value) {
        head = head->next;
        free(temp);
        printf("Node deleted successfully.\n");
        return head;
    }

    // Search for the node
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // Value not found
    if (temp == NULL) {
        printf("Value not found.\n");
        return head;
    }

    // Delete node
    prev->next = temp->next;
    free(temp);
    printf("Node deleted successfully.\n");

    return head;
}

// Display list
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

// Main function
int main() {
    struct Node *head = NULL;
    int n, value, delValue;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("\nOriginal List:\n");
    display(head);

    printf("\nEnter value to delete: ");
    scanf("%d", &delValue);

    head = deleteNode(head, delValue);

    printf("\nUpdated List:\n");
    display(head);

    return 0;
}