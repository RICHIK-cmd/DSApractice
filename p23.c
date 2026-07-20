// insert at beginning LL
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Insert at beginning
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = value;
    newNode->next = head;
    
    head = newNode;
    return head;
}

// Display
void display(struct Node* head) {
    struct Node* temp = head;
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create initial list
    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insertAtBeginning(head, value);
    }

    printf("Initial list: ");
    display(head);

    // Insert new node at beginning
    printf("Enter value to insert at beginning: ");
    scanf("%d", &value);

    head = insertAtBeginning(head, value);

    printf("Updated list: ");
    display(head);

    return 0;
}