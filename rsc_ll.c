
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create()
{
    struct node *head = NULL, *temp, *newnode;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL)
            head = newnode;
        else
            temp->next = newnode;

        temp = newnode;
    }

    return head;
}

void display(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sort(struct node *head)
{
    struct node *i, *j;
    int temp;

    for(i = head; i != NULL; i = i->next)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            if(i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

struct node* reverse(struct node *head)
{
    struct node *prev = NULL, *current = head, *next;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

struct node* concatenate(struct node *head1, struct node *head2)
{
    struct node *temp = head1;

    if(head1 == NULL)
        return head2;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = head2;

    return head1;
}

int main()
{
    struct node *head1 = NULL, *head2 = NULL;
    int choice;

    printf("Create First Linked List:\n");
    head1 = create();

    printf("\nCreate Second Linked List:\n");
    head2 = create();

    do
    {
        printf("\n1. Display\n");
        printf("2. Sort\n");
        printf("3. Reverse\n");
        printf("4. Concatenate\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("First List: ");
                display(head1);
                break;

            case 2:
                sort(head1);
                printf("Sorted List: ");
                display(head1);
                break;

            case 3:
                head1 = reverse(head1);
                printf("Reversed List: ");
                display(head1);
                break;

            case 4:
                head1 = concatenate(head1, head2);
                head2 = NULL;
                printf("Concatenated List: ");
                display(head1);
                break;

            case 5:
                printf("Exiting Program...");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}
