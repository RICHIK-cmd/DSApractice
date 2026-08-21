#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Insert node at the end
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

// Insertion Sort
struct Node* insertionSort(struct Node *head) {

    struct Node *sorted = NULL;
    struct Node *current = head;

    while (current != NULL) {

        // Save the next node
        struct Node *next = current->next;

        // Insert current into sorted list
        if (sorted == NULL || current->data < sorted->data) {

            current->next = sorted;
            sorted = current;
        }
        else {

            struct Node *temp = sorted;

            while (temp->next != NULL &&
                   temp->next->data <= current->data) {

                temp = temp->next;
            }

            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    return sorted;
}

// Display linked list
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

    // Sort the linked list
    head = insertionSort(head);

    printf("Sorted List: ");
    display(head);

    return 0;
}