#include <stdio.h>
#define MAX 5

int q[MAX], front = -1, rear = -1;

void insert()
{
    int x;
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        printf("Enter value: ");
        scanf("%d", &x);
        if (front == -1)
            front = 0;
        q[++rear] = x;
    }
}

void delete()
{
    if (front == -1)
        printf("Queue Empty\n");
    else
    {
        printf("Deleted: %d\n", q[front]);
        if (front == rear)
            front = rear = -1;
        else
            front++;
    }
}

void display()
{
    int i;
    if (front == -1)
        printf("Queue Empty\n");
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d ", q[i]);
        printf("\n");
    }
}

int main()
{
    while(1){
        int ch;
        printf("Choice: 1.Insert , 2.Delete , 3.Display , 4.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}
