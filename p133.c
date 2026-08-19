#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create new node
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

// Selection Sort
void selectionSort(struct Node *head) {

    struct Node *current = head;

    while (current != NULL) {

        struct Node *minNode = current;
        struct Node *temp = current->next;

        // Find minimum element
        while (temp != NULL) {

            if (temp->data < minNode->data)
                minNode = temp;

            temp = temp->next;
        }

        // Swap data
        int value = current->data;
        current->data = minNode->data;
        minNode->data = value;

        current = current->next;
    }
}

// Display
void display(struct Node *head) {

    struct Node *temp = head;

    while (temp != NULL) {

        printf("%d", temp->data);

        if (temp->next != NULL)
            printf(" -> ");

        temp = temp->next;
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

    selectionSort(head);

    printf("Sorted List: ");
    display(head);

    return 0;
}