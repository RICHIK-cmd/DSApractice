#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Insert node at the end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node *newNode = createNode(data);

    // If list is empty
    if (head == NULL) {
        return newNode;
    }

    struct Node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

// Display the linked list
void display(struct Node* head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Reverse a linked list
struct Node* reverse(struct Node* head) {
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next;

    while (curr != NULL) {

        // Save the next node
        next = curr->next;

        // Reverse the current node's link
        curr->next = prev;

        // Move prev forward
        prev = curr;

        // Move curr forward
        curr = next;
    }

    return prev;
}

// Check whether linked list is palindrome
int isPalindrome(struct Node* head) {

    // Empty list or one node
    if (head == NULL || head->next == NULL) {
        return 1;
    }

    struct Node *slow = head;
    struct Node *fast = head;

    // Find middle of the linked list
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half
    struct Node *second = reverse(slow->next);

    // First half starts from head
    struct Node *first = head;

    // Second half starts from reversed second half
    struct Node *temp = second;

    // Compare both halves
    while (temp != NULL) {

        if (first->data != temp->data) {
            return 0;
        }

        first = first->next;
        temp = temp->next;
    }

    return 1;
}

// Main function
int main() {

    struct Node *head = NULL;
    int n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = insertEnd(head, data);
    }

    printf("\nOriginal Linked List:\n");
    display(head);

    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    return 0;
}