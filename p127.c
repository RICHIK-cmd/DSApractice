#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Display linked list (use only before creating a loop)
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Find the starting node of the cycle
struct Node* startOfCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Step 1: Detect loop
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // No loop
    if (fast == NULL || fast->next == NULL)
        return NULL;

    // Step 2: Move slow to head
    slow = head;

    // Step 3: Move both one step at a time
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Start of cycle
    return slow;
}

int main() {
    struct Node* head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);

    printf("Original Linked List:\n");
    display(head);

    // Create loop: 50 points to 30
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head->next->next;

    struct Node* start = startOfCycle(head);

    if (start != NULL)
        printf("Start of cycle is node with value: %d\n", start->data);
    else
        printf("No cycle found.\n");

    return 0;
}