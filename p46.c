#include <stdio.h>
#include <stdlib.h>

// Define node
struct Node {
    int data;
    struct Node* next;
};

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Reverse linked list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;   // store next
        curr->next = prev;   // reverse link
        prev = curr;         // move prev
        curr = next;         // move curr
    }

    return prev;
}

// Display list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main
int main() {
    struct Node* head = NULL;
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    printf("Original List: ");
    display(head);

    head = reverseList(head);

    printf("Reversed List: ");
    display(head);

    return 0;
}