#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data)
{
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

// Add two linked lists
struct Node* addTwoNumbers(struct Node *head1,
                            struct Node *head2)
{
    struct Node *result = NULL;
    struct Node *tail = NULL;

    int carry = 0;

    while (head1 != NULL || head2 != NULL || carry != 0)
    {
        int sum = carry;

        // Take digit from first list
        if (head1 != NULL)
        {
            sum = sum + head1->data;
            head1 = head1->next;
        }

        // Take digit from second list
        if (head2 != NULL)
        {
            sum = sum + head2->data;
            head2 = head2->next;
        }

        // Calculate digit and carry
        int digit = sum % 10;
        carry = sum / 10;

        // Create new node
        struct Node *newNode = createNode(digit);

        // Insert into result
        if (result == NULL)
        {
            result = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return result;
}

// Display linked list
void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d", temp->data);

        if (temp->next != NULL)
            printf(" -> ");

        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *result = NULL;

    int n1, n2;
    int data;

    // Input first linked list
    printf("Enter number of nodes in first list: ");
    scanf("%d", &n1);

    printf("Enter digits of first list: ");

    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &data);
        head1 = insertEnd(head1, data);
    }

    // Input second linked list
    printf("Enter number of nodes in second list: ");
    scanf("%d", &n2);

    printf("Enter digits of second list: ");

    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &data);
        head2 = insertEnd(head2, data);
    }

    // Display input lists
    printf("\nFirst List: ");
    display(head1);

    printf("Second List: ");
    display(head2);

    // Add the two numbers
    result = addTwoNumbers(head1, head2);

    // Display result
    printf("Result: ");
    display(result);

    return 0;
}