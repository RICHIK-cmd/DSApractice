#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Delete last node
void deleteEnd(struct Node **head) {

    // Empty list
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Only one node
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *temp = *head;

    // Traverse till second last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Delete last node
    free(temp->next);

    // Make second last node point to NULL
    temp->next = NULL;
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {

    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    printf("Before deletion:\n");
    display(head);

    deleteEnd(&head);

    printf("After deletion:\n");
    display(head);

    return 0;
}