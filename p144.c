#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data)
{
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert at the end
struct Node* insertEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Find pairs whose sum equals target
void findPairs(struct Node *head, int target)
{
    if (head == NULL)
        return;

    struct Node *first = head;
    int found = 0;

    while (first != NULL)
    {
        struct Node *second = first->next;

        while (second != NULL)
        {
            if (first->data + second->data == target)
            {
                printf("(%d, %d)\n",
                       first->data,
                       second->data);

                found = 1;
            }

            second = second->next;
        }

        first = first->next;
    }

    if (found == 0)
        printf("No pairs found.\n");
}

// Display the list
void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d", temp->data);

        if (temp->next != NULL)
            printf(" <-> ");

        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    int n, data, target;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);

        head = insertEnd(head, data);
    }

    printf("Doubly Linked List: ");
    display(head);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("Pairs with sum %d:\n", target);

    findPairs(head, target);

    return 0;
}