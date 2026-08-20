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

// Bubble Sort
void bubbleSort(struct Node *head) {

    if (head == NULL)
        return;

    int swapped;

    struct Node *current;
    struct Node *last = NULL;

    do {
        swapped = 0;
        current = head;

        while (current->next != last) {

            if (current->data > current->next->data) {

                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;

                swapped = 1;
            }

            current = current->next;
        }

        last = current;

    } while (swapped);
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

    bubbleSort(head);

    printf("Sorted List: ");
    display(head);

    return 0;
}