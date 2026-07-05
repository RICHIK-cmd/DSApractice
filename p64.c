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

// Insert at end in O(1)
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

// Display the list
void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Delete all occurrences in O(n)
void deleteAllOccurrences(struct Node **head, int key) {
    struct Node *temp;

    // Delete from beginning
    while (*head != NULL && (*head)->data == key) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    if (*head == NULL)
        return;

    struct Node *curr = *head;

    while (curr->next != NULL) {
        if (curr->next->data == key) {
            temp = curr->next;
            curr->next = temp->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }
}

int main() {
    struct Node *head = NULL, *tail = NULL;
    int n, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, &tail, value);
    }

    printf("\nOriginal Linked List:\n");
    display(head);

    printf("\nEnter element to delete: ");
    scanf("%d", &key);

    deleteAllOccurrences(&head, key);

    printf("\nLinked List after deletion:\n");
    display(head);

    return 0;
}