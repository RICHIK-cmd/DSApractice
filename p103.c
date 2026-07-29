#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Create Circular Singly Linked List
struct Node* createList(int n)
{
    if(n <= 0)
        return NULL;

    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for(int i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        if(newNode == NULL)
        {
            printf("Memory Allocation Failed\n");
            exit(1);
        }

        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    temp->next = head;

    return head;
}

// Display List
void display(struct Node *head)
{
    if(head == NULL)
    {
        printf("List Empty\n");
        return;
    }

    struct Node *temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("\n");
}

// Delete Node by Value
struct Node* deleteValue(struct Node *head, int key)
{
    if(head == NULL)
    {
        printf("List Empty\n");
        return NULL;
    }

    // Delete Head Node
    if(head->data == key)
    {
        // Only one node
        if(head->next == head)
        {
            free(head);
            return NULL;
        }

        struct Node *last = head;

        while(last->next != head)
            last = last->next;

        struct Node *temp = head;
        head = head->next;
        last->next = head;

        free(temp);

        return head;
    }

    // Delete Other Nodes
    struct Node *prev = head;
    struct Node *curr = head->next;

    while(curr != head)
    {
        if(curr->data == key)
        {
            prev->next = curr->next;
            free(curr);
            return head;
        }

        prev = curr;
        curr = curr->next;
    }

    printf("Value Not Found\n");

    return head;
}

int main()
{
    int n, key;
    struct Node *head = NULL;

    printf("Enter Number of Nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("Original List: ");
    display(head);

    printf("Enter Value to Delete: ");
    scanf("%d", &key);

    head = deleteValue(head, key);

    printf("Updated List: ");
    display(head);

    return 0;
}