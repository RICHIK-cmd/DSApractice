#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    // Create list
    for (int i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("\nOriginal List: ");
    display(head);

    printf("Enter value to delete: ");
    scanf("%d", &value);

    struct Node *curr = head, *prev = NULL;

    // Value at head
    if (head != NULL && head->data == value) {
        head = head->next;
        free(curr);
    } else {
        while (curr != NULL && curr->data != value) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            printf("Value not found!\n");
        } else {
            prev->next = curr->next;
            free(curr);
        }
    }

    printf("\nUpdated List: ");
    display(head);

    return 0;
}