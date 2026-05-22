#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to insert node at any position
void insertAtPosition(struct Node **head, int data, int position) {
    struct Node *newNode, *temp;
    
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // Insert at beginning
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    temp = *head;

    // Traverse to previous node
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // Invalid position
    if (temp == NULL) {
        printf("Invalid Position\n");
        return;
    }

    // Insert node
    newNode->next = temp->next;
    temp->next = newNode;
}

// Display linked list
void display(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int n, value, position;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // User input for nodes
    for (int i = 1; i <= n; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);

        insertAtPosition(&head, value, i);
    }

    printf("\nLinked List:\n");
    display(head);

    // Insert at any position
    printf("\nEnter value to insert: ");
    scanf("%d", &value);

    printf("Enter position: ");
    scanf("%d", &position);

    insertAtPosition(&head, value, position);

    printf("\nLinked List after insertion:\n");
    display(head);

    return 0;
}