#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *create(struct node *start)
{
    struct node *p, *temp;
    int n, i, item;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Enter the element: ");
        scanf("%d", &item);

        p = (struct node *)malloc(sizeof(struct node));
        p->info = item;
        p->next = NULL;

        if(start == NULL)
        {
            start = p;
            temp = p;
        }
        else
        {
            temp->next = p;
            temp = p;
        }
    }

    return start;
}

struct node *delsllstr(struct node *start)
{
    struct node *temp;

    if (start == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        temp = start;
        start = start->next;

        printf("Deleted element: %d", temp->info);
        free(temp);
    }

    return start;
}

struct node *delsllend(struct node *start)
{
    struct node *temp, *prev;

    if (start == NULL)
    {
        printf("Linked list is empty");
    }
    else if (start->next == NULL)
    {
        printf("Deleted element: %d", start->info);
        free(start);
        start = NULL;
    }
    else
    {
        temp = start;

        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        printf("Deleted element: %d", temp->info);
        prev->next = NULL;
        free(temp);
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
        printf("\n1. Create Linked List");
        printf("\n2. Delete at beginning");
        printf("\n3. Delete at end");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                start = create(start);
                break;

            case 2:
                start = delsllstr(start);
                break;

            case 3:
                start = delsllend(start);
                break;

            case 4:
                displaysll(start);
                break;

            case 5:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice!");
        }

    } while(ch != 5);

    return 0;
}
