#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for(int i = 1; i <= n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter value %d: ", i);
        scanf("%d", &value);

        newNode->data = value;

        if(head == NULL)
        {
            head = temp = newNode;
            newNode->next = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
            temp->next = head;
        }
    }

    return head;
}

void display(struct Node *head)
{
    if(head == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    struct Node *temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head);

    printf("\n");
}

int countNodes(struct Node *head)
{
    if(head == NULL)
        return 0;

    int count = 0;
    struct Node *temp = head;

    do
    {
        count++;
        temp = temp->next;
    }while(temp != head);

    return count;
}

struct Node* deleteByPosition(struct Node *head, int pos)
{
    if(head == NULL)
        return NULL;

    int count = countNodes(head);

    if(pos < 1 || pos > count)
    {
        printf("Invalid Position\n");
        return head;
    }

    if(pos == 1)
    {
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

    struct Node *prev = head;

    for(int i = 1; i < pos - 1; i++)
        prev = prev->next;

    struct Node *temp = prev->next;
    prev->next = temp->next;

    free(temp);

    return head;
}

int main()
{
    int n, pos;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    struct Node *head = createList(n);

    printf("Original List:\n");
    display(head);

    printf("Enter position to delete: ");
    scanf("%d",&pos);

    head = deleteByPosition(head,pos);

    printf("Updated List:\n");
    display(head);

    return 0;
}