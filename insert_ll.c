
#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *inssllstr(struct node *start)
{
    int item;
    struct node *p;

    printf("Enter the element to be inserted: ");
    scanf("%d", &item);

    p = (struct node *)malloc(sizeof(struct node));
    p->info = item;

    p->next = start;
    start = p;

    return start;
}

struct node *inssllend(struct node *start)
{
    int item;
    struct node *p, *temp;

    printf("Enter the element to be inserted: ");
    scanf("%d", &item);

    p = (struct node *)malloc(sizeof(struct node));
    p->info = item;
    p->next = NULL;

    if (start == NULL)
    {
        start = p;
    }
    else
    {
        temp = start;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = p;
    }

    return start;
}

void displaysll(struct node *start)
{
    struct node *temp;

    if (start == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        temp = start;

        while (temp != NULL)
        {
            printf("%d -> ", temp->info);
            temp = temp->next;
        }

        printf("NULL");
    }
}

int main()
{
    struct node *start = NULL;
    int ch;

    do
    {
        printf("\n\n--- SINGLY LINKED LIST ---");
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                start = inssllstr(start);
                break;

            case 2:
                start = inssllend(start);
                break;

            case 3:
                displaysll(start);
                break;

            case 4:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice!");
        }

    } while(ch != 4);

    return 0;
}
