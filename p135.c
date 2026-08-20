#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create node
struct Node* createNode(int data) {

    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node *head, int data) {

    struct Node *newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

// Insert node into sorted list
struct Node* sortedInsert(struct Node *sorted,
                           struct Node *newNode) {

    // If sorted list is empty
    // or new node is smaller than first node
    if (sorted == NULL ||
        newNode->data < sorted->data) {

        newNode->next = sorted;
        sorted = newNode;

        return sorted;
    }

    struct Node *temp = sorted;

    // Find correct position
    while (temp->next != NULL &&
           temp->next->data <= newNode->data) {

        temp = temp->next;
    }

    // Insert new node
    newNode->next = temp->next;
    temp->next = newNode;

    return sorted;
}

// Insertion Sort
struct Node* insertionSort(struct Node *head) {

    struct Node *sorted = NULL;
    struct Node *current = head;

    while (current != NULL) {

        // Save next node before changing links
        struct Node *next = current->next;

        // Insert current into sorted list
        sorted = sortedInsert(sorted, current);

        // Move to next node
        current = next;
    }

    return sorted;
}

// Display
void display(struct Node *head) {

    while (head != NULL) {

        printf("%d", head->data);

        if (head->next != NULL)
            printf(" -> ");

        head = head->next;
    }

    printf("\n");
}

int main() {

    struct Node *head = NULL;

    int n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {

        scanf("%d", &data);

        head = insertEnd(head, data);
    }

    printf("Original List: ");
    display(head);

    head = insertionSort(head);

    printf("Sorted List: ");
    display(head);

    return 0;
}