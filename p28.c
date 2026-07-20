#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Display
void display(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = head;
    return newNode;
}

// Insert at end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) return newNode;

    struct Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

// Delete first node
struct Node* deleteFirst(struct Node* head) {
    if(head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);

    return head;
}

// Count nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Search element
int search(struct Node* head, int key) {
    struct Node* temp = head;

    while(temp != NULL) {
        if(temp->data == key) return 1;
        temp = temp->next;
    }
    return 0;
}

// Reverse list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, n, data;

    while(1) {
        printf("\n--- MENU ---\n");
        printf("1. Create List\n");
        printf("2. Display\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Delete First\n");
        printf("6. Count Nodes\n");
        printf("7. Search Element\n");
        printf("8. Reverse List\n");
        printf("9. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                head = createList(n);
                break;

            case 2:
                display(head);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;

            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;

            case 5:
                head = deleteFirst(head);
                break;

            case 6:
                printf("Total nodes: %d\n", countNodes(head));
                break;

            case 7:
                printf("Enter element to search: ");
                scanf("%d", &data);
                if(search(head, data))
                    printf("Element found\n");
                else
                    printf("Element not found\n");
                break;

            case 8:
                head = reverseList(head);
                printf("List reversed\n");
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}