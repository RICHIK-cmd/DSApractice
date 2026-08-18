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

// Insert at end
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

// Count nodes present in the loop
int countNodesInLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Step 1: Detect loop
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: Count nodes in the loop
            int count = 1;
            fast = fast->next;

            while (fast != slow) {
                count++;
                fast = fast->next;
            }

            return count;
        }
    }

    return 0; // No loop
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

    temp->next = head->next->next; // 50 -> 30

    int nodes = countNodesInLoop(head);

    if (nodes > 0)
        printf("Number of nodes in loop = %d\n", nodes);
    else
        printf("No loop found.\n");

    return 0;
}